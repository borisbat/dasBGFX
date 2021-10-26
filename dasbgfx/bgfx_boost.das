options indenting = 4
options no_unused_block_arguments = false
options no_unused_function_arguments = false

module bgfx_boost shared public

require bgfx public

require daslib/safe_addr
require daslib/strings_boost
require daslib/algorithm
require math
require fio
require stbimage

require dasbgfx/bgfx_boost_internal public
require dasbgfx/glsl_bgfx public

let VERBOSE_COMPILER = false

let BGFX_STATE_WRITE_RGB = (0ul
    | BGFX_STATE_WRITE_R
    | BGFX_STATE_WRITE_G
    | BGFX_STATE_WRITE_B
)

let BGFX_STATE_DEFAULT = (0ul
    | BGFX_STATE_WRITE_RGB
    | BGFX_STATE_WRITE_A
    | BGFX_STATE_WRITE_Z
    | BGFX_STATE_DEPTH_TEST_LESS
    | BGFX_STATE_CULL_CW
    | BGFX_STATE_MSAA
)

def UCOLOR_TO_BGFX_UCOLOR ( col:uint )
    let r = (col & 0x00ff0000) >> 16u
    let g = (col & 0x0000ff00) >> 8u
    let b = (col & 0x000000ff)
    let a = (col & 0xff000000) >> 24u
    return (b<<24u) | (g<<16u) | (r<<8u) | (a)

def RGBA_TO_BGFX_UCOLOR(r,g,b,a:float)
    return pack_float_to_byte(float4(a,b,g,r)*255.)

struct private BgfxUniform
    handle : bgfx_uniform_handle_s
    utype  : bgfx_uniform_type
    ucount : uint

var private g_bgfxUniform : table<string; BgfxUniform>

def private bgfx_cache_uniform ( name:string; utype:bgfx_uniform_type; ucount:uint )
    assert(ucount!=0u)
    var unf & = g_bgfxUniform[name]
    if unf.ucount==0u
        unf.handle = bgfx_create_uniform(name, utype, ucount)
        if unf.handle.idx==uint16(0xffff)
            panic("invalid uniform {name} {utype}[{ucount}]")
        unf.utype = utype
        unf.ucount = ucount
    else
        if unf.utype!=utype || unf.ucount!=ucount
            panic("uniform {name} type mismatch. expecting {utype}[{ucount}], got {unf.utype}[{unf.ucount!=ucount}]")
    return unf.handle

def public bgfx_reset_uniform_cache
    for val in values(g_bgfxUniform)
        bgfx_destroy_uniform(val.handle)
    delete g_bgfxUniform

def public bgfx_any_uniform ( name:string; stage:uint; value:sampler2D )
    var handle = bgfx_cache_uniform(name, bgfx_uniform_type BGFX_UNIFORM_TYPE_SAMPLER, 1u)
    bgfx_set_texture(stage, handle, [[bgfx_texture_handle_s idx=uint16(value.texture2D)]], 0xffff);

def public bgfx_any_uniform ( name:string; _value:uint )
    var value = [[bgfx_texture_handle_s idx=uint16(_value)]]
    var handle = bgfx_cache_uniform(name, bgfx_uniform_type BGFX_UNIFORM_TYPE_SAMPLER, 1u)
    bgfx_set_uniform(handle, safe_addr(value), 0xffff)

def public bgfx_any_uniform ( name:string; value:float4 )
    var handle = bgfx_cache_uniform(name, bgfx_uniform_type BGFX_UNIFORM_TYPE_VEC4, 1u)
    bgfx_set_uniform(handle, safe_addr(value), 0xffff)

[generic]
def public bgfx_any_uniform ( name:string; value:float4[] )
    var handle = bgfx_cache_uniform(name, bgfx_uniform_type BGFX_UNIFORM_TYPE_VEC4, uint(length(value)))
    bgfx_set_uniform(handle, safe_addr(value), 0xffff)

def public bgfx_any_uniform ( name:string; value:float3x3 )
    var handle = bgfx_cache_uniform(name, bgfx_uniform_type BGFX_UNIFORM_TYPE_MAT3, 1u)
    bgfx_set_uniform(handle, safe_addr(value), 0xffff)

def public bgfx_any_uniform ( name:string; value:float3x3[] )
    var handle = bgfx_cache_uniform(name, bgfx_uniform_type BGFX_UNIFORM_TYPE_MAT3, uint(length(value)))
    bgfx_set_uniform(handle, safe_addr(value), 0xffff)

def public bgfx_any_uniform ( name:string; value:float4x4 )
    var handle = bgfx_cache_uniform(name, bgfx_uniform_type BGFX_UNIFORM_TYPE_MAT4, 1u)
    bgfx_set_uniform(handle, safe_addr(value), 0xffff)

def public bgfx_any_uniform ( name:string; value:float4x4[] )
    var handle = bgfx_cache_uniform(name, bgfx_uniform_type BGFX_UNIFORM_TYPE_MAT4, uint(length(value)))
    bgfx_set_uniform(handle, safe_addr(value), 0xffff)

def public bgfx_create_shader_program ( vs, vd, fs, fd : string; render_type : bgfx_renderer_type )
    var vda <- split(vd,"\n")
    var pda <- split(fd,"\n")
    var vpda <- combine(vda, pda)
    sort_unique(vpda)
    delete vda
    delete pda
    let temp_dir = "{get_das_root()}/temp"
    mkdir(temp_dir)
    fopen("{temp_dir}/varying.def.sc","wb") <| $ ( fdef )
        for t in vpda
            if length(t)>0
                fwrite(fdef, "{t}\n")
    delete vpda
    let vs_name = "{temp_dir}/vertex.sh"
    fopen(vs_name,"wb") <| $ ( fvtx )
        fwrite ( fvtx, vs )
    let fs_name = "{temp_dir}/fragment.sh"
    fopen(fs_name,"wb") <| $ ( ffrag )
        fwrite ( ffrag, fs )
    let vs_bin_name = "{temp_dir}/vertex.bin"
    if !bgfx_compile_shader_file ( vs_name, vs_bin_name, "v", render_type )
        panic("can't compile {vs_name}")
    let fs_bin_name = "{temp_dir}/fragment.bin"
    if !bgfx_compile_shader_file ( fs_name, fs_bin_name, "f", render_type )
        panic("can't compile {fs_name}")
    var vsh = bgfx_load_shader_from_bin(vs_bin_name);
    var fsh = bgfx_load_shader_from_bin(fs_bin_name);
    let prog = bgfx_create_program(vsh, fsh, true)
    if prog.idx==uint16(0xffff)
        panic("failed to create program")
    return prog

def public bgfx_compile_shader_file ( fin, fout, ftype:string; rt : bgfx_renderer_type )
    var platform = ""
    var profile = ""
    if rt==bgfx_renderer_type BGFX_RENDERER_TYPE_NOOP
        pass
    elif rt==bgfx_renderer_type BGFX_RENDERER_TYPE_AGC || rt==bgfx_renderer_type BGFX_RENDERER_TYPE_GNM
        platform = "orbis"
        profile = "pssl"
    elif rt==bgfx_renderer_type BGFX_RENDERER_TYPE_DIRECT3D9
        platform = "windows"
        if ftype=="v"
            profile = "vs_3_0"
        elif ftype=="f"
            profile = "ps_3_0"
        elif ftype=="c"
            profile = "cs_3_0"
    elif rt==bgfx_renderer_type BGFX_RENDERER_TYPE_DIRECT3D11 || rt==bgfx_renderer_type BGFX_RENDERER_TYPE_DIRECT3D12
        platform = "windows"
        if ftype=="v"
            profile = "vs_5_0"
        elif ftype=="f"
            profile = "ps_5_0"
        elif ftype=="c"
            profile = "cs_5_0"
    elif rt==bgfx_renderer_type BGFX_RENDERER_TYPE_METAL
        platform = "osx"
        profile = "metal"
    elif rt==bgfx_renderer_type BGFX_RENDERER_TYPE_NVN
        panic("unsupported?")
    elif rt==bgfx_renderer_type BGFX_RENDERER_TYPE_OPENGLES
        platform = "android"
    elif rt==bgfx_renderer_type BGFX_RENDERER_TYPE_OPENGL
        platform = "linux"
        profile = ftype=="c" ? "430" : "120"
    elif rt==bgfx_renderer_type BGFX_RENDERER_TYPE_VULKAN || rt==bgfx_renderer_type BGFX_RENDERER_TYPE_WEBGPU
        platform = "linux"
        profile = "spirv"
    let shaderc = "{get_das_root()}/modules/dasBGFX/bin/shaderc.exe"
    let incl = "{get_das_root()}/modules/dasBGFX/bgfx/bgfx/src"
    let prof = profile=="" ? "" : " --profile {profile}"
    let sys = "\"{shaderc}\" -i {incl} -f {fin} -o {fout} --type {ftype} --platform {platform}{prof}"
    if VERBOSE_COMPILER
        print("{sys}\n")
    unsafe
        var text : array<string>
        let ex_code = popen(sys) <| $ ( f )
            if f != null
                while !feof(f)
                    let st = fgets(f)
                    text |> push(st)
            else
                print("das: can't open\n")
        if ex_code!=0 || VERBOSE_COMPILER
            for t in text
                print(t)
        if VERBOSE_COMPILER
            print("exit code {ex_code}\n")
        return ex_code==0

def public bgfx_load_shader_from_bin ( fileName:string )
    var sha : bgfx_shader_handle_s
    fopen(fileName,"rb") <| $ ( f )
        if f==null
            panic("can't open {fileName}")
        fmap(f) <| $ ( data )
            var mem = bgfx_alloc(uint(length(data)))
            var arr : array<uint8>
            unsafe
                _builtin_make_temp_array(arr, mem.data, int(mem.size) )
            for d,s in arr,data
                d = s
            sha = bgfx_create_shader(mem)
    return sha

def public bgfx_make_ref ( arr:array<auto(TT)> )
    return bgfx_make_ref(safe_addr(arr[0]), uint(length(arr)*typeinfo(sizeof type<TT>)))

def public bgfx_make_ref ( arr:auto(TT)[] )
    return bgfx_make_ref(safe_addr(arr[0]), uint(length(arr)*typeinfo(sizeof type<TT>)))

def bgfx_load_image_from_bytes ( width,height:int; data:void? )
    var mem = bgfx_copy(data, uint(width*height*4))
    let handle = bgfx_create_texture_2d(uint(width), uint(height), false, 1u,
        bgfx_texture_format BGFX_TEXTURE_FORMAT_RGBA8, BGFX_TEXTURE_NONE | uint64(BGFX_SAMPLER_NONE), mem)
    return handle

def bgfx_load_image_from_file ( fname:string implicit; canfail:bool=false )
    var x, y, comp : int
    let data = stbi_load(fname, safe_addr(x), safe_addr(y), safe_addr(comp), 4)
    if data == null
        if !canfail
            let reason = stbi_failure_reason();
            panic(reason)
        return [[bgfx_texture_handle_s idx=uint16(0xffff)]]
    else
        var texture_id = bgfx_load_image_from_bytes(x, y, data)
        stbi_image_free(data)
        return texture_id
