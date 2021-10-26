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
var [[uniform]] c_offset : float4

[bgfx_vertex_program(name="VERTEX_SRC")]
def vs_main
    v_color0 = a_color0
    v_texcoord0 = a_texcoord0
    gl_Position = u_modelViewProj * float4(a_position, 0.0, 1.0)

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

/*
    if gl_GlobalInvocationID.xy==uint2(0,0)
        c_mat.a_times_b = c_mat.a * c_mat.b
        c_mat.b_times_a = c_mat.b * c_mat.a
        c_mat.a_times_1234 = c_mat.a * float4(1,2,3,4)
        c_mat.b_times_1234 = c_mat.b * float4(1,2,3,4)
*/

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
    var init : bgfx_init_s
    bgfx_init_ctor(safe_addr(init))
    // init._type = bgfx_renderer_type BGFX_RENDERER_TYPE_OPENGL
    init._type = bgfx_renderer_type BGFX_RENDERER_TYPE_COUNT
    init.resolution.width = uint(WNDW_WIDTH)
    init.resolution.height = uint(WNDW_HEIGHT)
    init.resolution.reset = BGFX_RESET_VSYNC
    bgfx_init(safe_addr(init))
    let render_type = bgfx_get_renderer_type()
    print("render_type {render_type}\n")
    var pcvl_decl = bgfx_create_vertex_layout(type<Vertex>,render_type)
    var pcvl_handle = bgfx_create_vertex_layout(safe_addr(pcvl_decl))
    var vbh = bgfx_create_vertex_buffer(bgfx_make_ref(vertices), safe_addr(pcvl_decl), BGFX_BUFFER_NONE)
    var ibh = bgfx_create_index_buffer(bgfx_make_ref(indices), BGFX_BUFFER_INDEX32)
    var compute_program = bgfx_create_compute_shader_program(COMPUTE_SRC, render_type)
    var program = bgfx_create_shader_program(VERTEX_SRC, VERTEX_SRC_DECL, FRAGMENT_SRC, FRAGMENT_SRC_DECL, render_type)
    var texture = bgfx_create_texture_2d(256u, 256u, false, 1u,
        bgfx_texture_format BGFX_TEXTURE_FORMAT_RGBA8, BGFX_TEXTURE_COMPUTE_WRITE, null)
    if texture.idx==uint16(0xffff)
        panic("can't create texture")
    let v_ortho = bgfx_mat_ortho(-1.,1.,-1.,1.,0.,100.,0.,bgfx_get_caps().homogeneousDepth,false)
    bgfx_set_view_clear(0u, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, RGBA_TO_BGFX_UCOLOR(0.2,0.2,0.2,1.0), 1.0f, 0u)
    var ioffset = 0
    while glfwWindowShouldClose(window)==0
        glfwPollEvents()
        var display_w, display_h : int
        glfwGetFramebufferSize(window, display_w, display_h)
        c_offset.x = float(ioffset++)
        c_destTex.texture2D = uint(texture.idx)
        compute_effect_bind_uniform()
        bgfx_dispatch(0u, compute_program, 256u/16u, 256u/16u, 1u, 0u)
        bgfx_set_view_transform(0u, null, safe_addr(v_ortho))
        bgfx_set_view_rect(0u, 0u, 0u, uint(display_w), uint(display_h))
        bgfx_set_vertex_buffer(0u, vbh, 0u, uint(length(vertices)))
        bgfx_set_index_buffer(ibh, 0u, uint(length(indices)))
        f_tex.texture2D = uint(texture.idx)
        vs_main_bind_uniform()
        fs_main_bind_uniform()
        bgfx_submit(0u, program, 1u, BGFX_DISCARD_NONE)
        bgfx_frame(false)
    bgfx_shutdown()
