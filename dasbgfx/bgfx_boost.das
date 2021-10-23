options indenting = 4
options no_unused_block_arguments = false
options no_unused_function_arguments = false

module bgfx_boost shared public

require bgfx public

require daslib/safe_addr

require fio

let VERBOSE_COMPILER = true

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
        let ex_code = popen(sys) <| $ ( f )
            if f != null
                while !feof(f)
                    let st = fgets(f)
                    if VERBOSE_COMPILER
                        print("{st}")
            else
                print("das: can't open\n")
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
