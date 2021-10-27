require glfw/glfw_boost
require dasbgfx/bgfx_boost
require daslib/defer
require daslib/math_boost
require daslib/safe_addr

var [[in, semantics=POSITION]]  a_position : float2
var [[in, semantics=COLOR0]]    a_color0   : float3
var [[inout, semantics=COLOR0]] v_color0   : float3
var [[uniform]] v_ortho : float4x4

[bgfx_vertex_program(name="VERTEX_SRC")]
def vs_main
    v_color0 = a_color0
    gl_Position = v_ortho * float4(a_position, 0.0, 1.0)

[bgfx_fragment_program(name="FRAGMENT_SRC")]
def fs_main
    gl_FragColor = float4(v_color0, 1.0)

[bgfx_vertex_buffer]
struct Vertex
    [[type=FLOAT, size=2, semantics=POSITION]] xy : float2
    [[type=FLOAT, size=3, semantics=COLOR0]] rgb : float3

let vertices = [[Vertex
        xy=float2(-0.5, 0.5), rgb=float3(0.0,0.0,0.0);
        xy=float2( 0.5,-0.5), rgb=float3(1.0,0.0,0.0);
        xy=float2( 0.5, 0.5), rgb=float3(1.0,1.0,0.0)
]]

let indices = [[int 0;1;2]]

[export]
def main
    let WNDW_WIDTH = 1280
    let WNDW_HEIGHT = 720
    if glfwInit()==0
		panic("can't init glfw")
    defer <|
        glfwTerminate()
    var window = glfwCreateWindow(WNDW_WIDTH, WNDW_HEIGHT, "Hello triangle", null, null)
    if window==null
		panic("can't create window")
    defer <|
        glfwDestroyWindow(window)
    var pd: bgfx_platform_data_s
    pd.nwh = glfwGetWin32Window(window)
    bgfx_set_platform_data(safe_addr(pd))
    bgfx_init(WNDW_WIDTH,WNDW_HEIGHT)
    let render_type = bgfx_get_renderer_type()
    print("render_type {render_type}\n")
    var pcvl_decl = bgfx_create_vertex_layout(type<Vertex>,render_type)
    var vbh = bgfx_create_vertex_buffer(bgfx_make_ref(vertices), safe_addr(pcvl_decl), BGFX_BUFFER_NONE)
    var ibh = bgfx_create_index_buffer(bgfx_make_ref(indices), BGFX_BUFFER_INDEX32)
    var program = bgfx_create_shader_program(VERTEX_SRC, VERTEX_SRC_DECL, FRAGMENT_SRC, FRAGMENT_SRC_DECL, render_type)
    bgfx_set_view_clear(0u, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, RGBA_TO_BGFX_UCOLOR(0.2,0.2,0.2,1.0), 1.0f, 0u)
    v_ortho = bgfx_mat_ortho(-1.,1.,-1.,1.,-100.,100.,0.,bgfx_get_caps().homogeneousDepth,false)
    while glfwWindowShouldClose(window)==0
        glfwPollEvents()
        var display_w, display_h : int
        glfwGetFramebufferSize(window, display_w, display_h)
        bgfx_set_view_rect(0u, 0u, 0u, uint(display_w), uint(display_h))
        bgfx_set_vertex_buffer(0u, vbh, 0u, uint(length(vertices)))
        bgfx_set_index_buffer(ibh, 0u, uint(length(indices)))
        vs_main_bind_uniform()
        fs_main_bind_uniform()
        bgfx_set_state(BGFX_STATE_DEFAULT, 0u)
        bgfx_submit(0u, program, 1u, BGFX_DISCARD_NONE)
        bgfx_frame(true)
    bgfx_shutdown()
