require glfw/glfw_boost
require dasbgfx/bgfx_boost
require daslib/defer
require daslib/math_boost
require daslib/safe_addr

var [[in, semantics=POSITION]]     a_position  : float2
var [[in, semantics=COLOR0]]       a_color0    : float3
var [[in, semantics=TEXCOORD0]]    a_texcoord0 : float2
var [[inout, semantics=COLOR0]]    v_color0    : float3
var [[inout, semantics=TEXCOORD0]] v_texcoord0 : float2
var [[uniform, stage=0]] f_tex : sampler2D
var [[uniform, format=rgba8, binding=0, writeonly]] c_destTex : image2D
var [[uniform, format=rgba32f, binding=1, readwrite]] c_matTex : image2D
var [[uniform]] c_offset : float4
var [[uniform]] c_mat_z : float4x4

var [[uniform]] v_model : float4x4
var [[uniform]] v_view : float4x4
var [[uniform]] v_projection : float4x4
var [[uniform]] v_pvm : float4x4

[bgfx_vertex_program(name="VERTEX_SRC")]
def vs_main
    v_color0 = a_color0
    v_texcoord0 = a_texcoord0
    gl_Position = float4(a_position, 0.0, 1.0)

[bgfx_fragment_program(name="FRAGMENT_SRC")]
def fs_main
    gl_FragColor = texture2D(f_tex,v_texcoord0) * float4(v_color0, 1.0)

[bgfx_compute_program(name="COMPUTE_SRC",local_size_x=16,local_size_y=16)]
def compute_effect
    let storePos = int2(gl_GlobalInvocationID.xy)
    let bitPos = storePos + int2(int(c_offset.x)*3,int(c_offset.x)*3)
    let bit = (bitPos.x>>4) & (bitPos.y>>4) & 1
    if bit != 0
        imageStore(c_destTex,storePos, float4(storePos.x,storePos.y,0,255)/255.)
    else
        imageStore(c_destTex,storePos, float4(1.,.5,.25,1.))
    if gl_GlobalInvocationID.xy==uint2(0u,0u)
        var c_model, c_view, c_projection : float4x4
        // unpack
        c_model[0] = imageLoad(c_matTex, int2(0,0))
        c_model[1] = imageLoad(c_matTex, int2(1,0))
        c_model[2] = imageLoad(c_matTex, int2(2,0))
        c_model[3] = imageLoad(c_matTex, int2(3,0))
        c_view[0] = imageLoad(c_matTex, int2(0,1))
        c_view[1] = imageLoad(c_matTex, int2(1,1))
        c_view[2] = imageLoad(c_matTex, int2(2,1))
        c_view[3] = imageLoad(c_matTex, int2(3,1))
        c_projection[0] = imageLoad(c_matTex, int2(0,2))
        c_projection[1] = imageLoad(c_matTex, int2(1,2))
        c_projection[2] = imageLoad(c_matTex, int2(2,2))
        c_projection[3] = imageLoad(c_matTex, int2(3,2))
        let c_pvm = c_projection * c_view * c_model
        let x_pvm = v_projection * v_view * c_model
        // pack
        imageStore(c_matTex, int2(0,4), x_pvm[0])
        imageStore(c_matTex, int2(1,4), x_pvm[1])
        imageStore(c_matTex, int2(2,4), x_pvm[2])
        imageStore(c_matTex, int2(3,4), x_pvm[3])

        imageStore(c_matTex, int2(0,5), c_pvm[0])
        imageStore(c_matTex, int2(1,5), c_pvm[1])
        imageStore(c_matTex, int2(2,5), c_pvm[2])
        imageStore(c_matTex, int2(3,5), c_pvm[3])

        imageStore(c_matTex, int2(0,6), v_model[0])
        imageStore(c_matTex, int2(1,6), v_model[1])
        imageStore(c_matTex, int2(2,6), v_model[2])
        imageStore(c_matTex, int2(3,6), v_model[3])

        imageStore(c_matTex, int2(0,7), v_view[0])
        imageStore(c_matTex, int2(1,7), v_view[1])
        imageStore(c_matTex, int2(2,7), v_view[2])
        imageStore(c_matTex, int2(3,7), v_view[3])

        imageStore(c_matTex, int2(0,8), v_projection[0])
        imageStore(c_matTex, int2(1,8), v_projection[1])
        imageStore(c_matTex, int2(2,8), v_projection[2])
        imageStore(c_matTex, int2(3,8), v_projection[3])



[bgfx_vertex_buffer]
struct Vertex
    [[type=FLOAT, size=2, semantics=POSITION]]   xy : float2
    [[type=FLOAT, size=3, semantics=COLOR0]]    rgb : float3
    [[type=FLOAT, size=2, semantics=TEXCOORD0]]  uv : float2

let vertices = [[Vertex
        xy=float2(-1.0, 1.0), rgb=float3(0.0,0.0,0.0), uv=float2(0.0,0.0);
        xy=float2( 1.0, 1.0), rgb=float3(1.0,1.0,0.0), uv=float2(1.0,0.0);
        xy=float2( 1.0,-1.0), rgb=float3(1.0,0.0,0.0), uv=float2(1.0,1.0);
        xy=float2(-1.0,-1.0), rgb=float3(1.0,1.0,0.0), uv=float2(0.0,1.0)
]]

let indices = [[int 0; 2; 1; 2; 0; 3]]

struct CMat
    a, b, c, d, e, z, cm, cv, cp : float4x4

def set_cmat ( var tex:bgfx_texture_handle_s; m : CMat )
    var mem = bgfx_copy(safe_addr(m), uint(typeinfo(sizeof m)))
    bgfx_update_texture_2d(tex, 0u, 0u, 0u, 0u, 4u, 9u, mem, uint(4*4*typeinfo(sizeof type<float>)))

def get_cmat ( var tex:bgfx_texture_handle_s; var m : CMat )
    return bgfx_read_texture(tex, safe_addr(m), 0u)

[export]
def main
    let WNDW_WIDTH = 1280
    let WNDW_HEIGHT = 720
    if glfwInit()==0
		panic("can't init glfw")
    defer <|
        glfwTerminate()
    var window = glfwCreateWindow(WNDW_WIDTH, WNDW_HEIGHT, "Hello image", null, null)
    if window==null
		panic("can't create window")
    defer <|
        glfwDestroyWindow(window)
    var pd: bgfx_platform_data_s
    pd.nwh = glfwGetWin32Window(window)
    bgfx_set_platform_data(safe_addr(pd))

    bgfx_init(WNDW_WIDTH,WNDW_HEIGHT)
    // bgfx_init(WNDW_WIDTH,WNDW_HEIGHT,bgfx_renderer_type BGFX_RENDERER_TYPE_DIRECT3D12)
    // bgfx_init(WNDW_WIDTH,WNDW_HEIGHT,bgfx_renderer_type BGFX_RENDERER_TYPE_OPENGL)

    let render_type = bgfx_get_renderer_type()
    print("render_type {render_type}\n")
    var can_read_back = false
    if (bgfx_get_caps().supported & BGFX_CAPS_TEXTURE_READ_BACK) != 0ul
        can_read_back = true
    var pcvl_decl = bgfx_create_vertex_layout(type<Vertex>,render_type)
    var pcvl_handle = bgfx_create_vertex_layout(safe_addr(pcvl_decl))
    var vbh = bgfx_create_vertex_buffer(bgfx_make_ref(vertices), safe_addr(pcvl_decl), BGFX_BUFFER_NONE)
    var ibh = bgfx_create_index_buffer(bgfx_make_ref(indices), BGFX_BUFFER_INDEX32)

    // this is here as a workaround for the OpenGL bug
    bgfx_create_uniform("c_offset", bgfx_uniform_type BGFX_UNIFORM_TYPE_VEC4, 1u)

    bgfx_create_uniform("v_model",  bgfx_uniform_type BGFX_UNIFORM_TYPE_MAT4, 1u)
    bgfx_create_uniform("v_view",  bgfx_uniform_type BGFX_UNIFORM_TYPE_MAT4, 1u)
    bgfx_create_uniform("v_projection",  bgfx_uniform_type BGFX_UNIFORM_TYPE_MAT4, 1u)
    bgfx_create_uniform("v_pvm",  bgfx_uniform_type BGFX_UNIFORM_TYPE_MAT4, 1u)

    var compute_program = bgfx_create_compute_shader_program(COMPUTE_SRC, render_type)
    var program = bgfx_create_shader_program(VERTEX_SRC, VERTEX_SRC_DECL, FRAGMENT_SRC, FRAGMENT_SRC_DECL, render_type)
    var texture = bgfx_create_texture_2d(256u, 256u, false, 1u,
        bgfx_texture_format BGFX_TEXTURE_FORMAT_RGBA8, BGFX_TEXTURE_COMPUTE_WRITE, null)
    if texture.idx==uint16(0xffff)
        panic("can't create texture")
    var mat_texture = bgfx_create_texture_2d(4u, 9u, false, 1u,
        bgfx_texture_format BGFX_TEXTURE_FORMAT_RGBA32F,
        BGFX_TEXTURE_COMPUTE_WRITE | BGFX_TEXTURE_READ_BACK, null)
    if mat_texture.idx==uint16(0xffff)
        panic("can't create texture")
    let v_ortho = bgfx_mat_ortho(-1.,1.,-1.,1.,0.,100.,0.,bgfx_get_caps().homogeneousDepth,false)
    bgfx_set_view_clear(0u, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, RGBA_TO_BGFX_UCOLOR(0.2,0.2,0.2,1.0), 1.0f, 0u)
    var ioffset = 0
    var c_mat_res : CMat
    var c_res_frame = 0u
    while glfwWindowShouldClose(window)==0
        glfwPollEvents()
        var display_w, display_h : int
        glfwGetFramebufferSize(window, display_w, display_h)
        var c_mat : CMat

        let t = glfwGetTime()
        if t > 10lf
            glfwSetTime(t - 10lf)
        v_view = look_at_rh(float3(0,0,10),float3(0,0,0),float3(0,1,0))
        v_model = compose(float4(0,0,0,0), float4(0,0,0,0), float4(1.0))
        v_projection = bgfx_mat_projection(45., float(display_w), float(display_h), 0.1, 50., bgfx_get_caps().homogeneousDepth,false)
        v_pvm = v_projection * v_view * v_model

        c_mat.a = v_model
        c_mat.b = v_view
        c_mat.c = v_projection
        c_mat.d = v_pvm

        set_cmat(mat_texture, c_mat)

        c_offset.x = float(ioffset++)
        c_destTex.texture2D = uint(texture.idx)
        c_matTex.texture2D = uint(mat_texture.idx)
        compute_effect_bind_uniform()
        bgfx_dispatch(0u, compute_program, 256u/16u, 256u/16u, 1u, 0u)
        bgfx_set_view_rect(0u, 0u, 0u, uint(display_w), uint(display_h))
        bgfx_set_vertex_buffer(0u, vbh, 0u, uint(length(vertices)))
        bgfx_set_index_buffer(ibh, 0u, uint(length(indices)))
        f_tex.texture2D = uint(texture.idx)
        vs_main_bind_uniform()
        fs_main_bind_uniform()
        bgfx_submit(0u, program, 1u, BGFX_DISCARD_NONE)

        if c_res_frame==0u
            c_res_frame = get_cmat(mat_texture, c_mat_res)
        let n_frame = bgfx_frame(false)
        if n_frame>=c_res_frame && c_res_frame!=0u
            print("c_pvm = {c_mat_res.z}\n")
            print("x_pvm = {c_mat_res.e}\n")
            print("v_pvm = {v_pvm}\n")

            print("v_model       = {v_model}\n")
            print("c_model       = {c_mat_res.cm}\n")

            print("v_view        = {v_view}\n")
            print("c_view        = {c_mat_res.cv}\n")

            print("v_projection  = {v_projection}\n")
            print("c_projection  = {c_mat_res.cp}\n")
            c_res_frame = 0u

    bgfx_shutdown()
