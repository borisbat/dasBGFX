options indenting = 4
options no_unused_block_arguments = false
options no_unused_function_arguments = false

module bgfx_boost shared public

require bgfx public

require daslib/safe_addr

require fio

def public bgfx_load_shader ( fileName:string )
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
