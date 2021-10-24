require glfw/glfw_boost
require daslib/defer
require daslib/safe_addr
require daslib/math_boost
require dasbgfx/bgfx_boost

require dasbgfx/glsl_bgfx

var [[inout, semantics=COLOR0]] v_color0   : float4 = float4(1.,0.,0.,1.)
var [[in, semantics=POSITION]]  a_position : float3
var [[in, semantics=COLOR0]]    a_color0   : float4

[bgfx_fragment_program(name="FRAGMENT_SRC")]
def fs_cube_main
    gl_FragColor = v_color0

[bgfx_vertex_program(name="VERTEX_SRC")]
def vs_cube_main
	gl_Position = u_modelViewProj * float4(a_position.xy * 1.25, a_position.z, 1.0)
	v_color0 = a_color0

[bgfx_vertex_buffer]
struct PosColorVertex
    [[size=3, type=FLOAT, semantics=POSITION]] xyz  : float3
	[[size=4, type=UINT8, semantics=COLOR0, normalized=true]] argb : uint

let cubeVertices = [[PosColorVertex
	xyz=float3(-1.0f,  1.0f,  1.0f), argb=0xff000000;
	xyz=float3( 1.0f,  1.0f,  1.0f), argb=0xff0000ff;
	xyz=float3(-1.0f, -1.0f,  1.0f), argb=0xff00ff00;
	xyz=float3( 1.0f, -1.0f,  1.0f), argb=0xff00ffff;
	xyz=float3(-1.0f,  1.0f, -1.0f), argb=0xffff0000;
	xyz=float3( 1.0f,  1.0f, -1.0f), argb=0xffff00ff;
	xyz=float3(-1.0f, -1.0f, -1.0f), argb=0xffffff00;
	xyz=float3( 1.0f, -1.0f, -1.0f), argb=0xffffffff
]]

let cubeTriList = [[int
	0; 1; 2;
	1; 3; 2;
	4; 6; 5;
	5; 6; 7;
	0; 2; 4;
	4; 2; 6;
	1; 5; 3;
	5; 7; 3;
	0; 4; 1;
	4; 5; 1;
	2; 3; 6;
	6; 3; 7
]]

[export]
def main
    let WNDW_WIDTH = 1280
    let WNDW_HEIGHT = 720
    if glfwInit()==0
		panic("can't init glfw")
    defer <|
        glfwTerminate()
    var window = glfwCreateWindow(WNDW_WIDTH, WNDW_HEIGHT, "Testing BGFX", null, null)
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
    var pcvl_decl = bgfx_create_vertex_layout(type<PosColorVertex>,render_type)
    var vbh = bgfx_create_vertex_buffer(bgfx_make_ref(cubeVertices), safe_addr(pcvl_decl), BGFX_BUFFER_NONE)
    var ibh = bgfx_create_index_buffer(bgfx_make_ref(cubeTriList), BGFX_BUFFER_INDEX32)
    var program = bgfx_create_shader_program(VERTEX_SRC, VERTEX_SRC_DECL, FRAGMENT_SRC, FRAGMENT_SRC_DECL, render_type)
    bgfx_set_view_clear(0u, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x443355FF, 1.0f, 0u)
	bgfx_set_debug(BGFX_DEBUG_TEXT)
    while glfwWindowShouldClose(window)==0
        glfwPollEvents()
        var display_w, display_h : int
        glfwGetFramebufferSize(window, display_w, display_h)
        let aspect = display_h!=0 ? float(display_w)/float(display_h) : 1.
        bgfx_set_view_rect(0u, 0u, 0u, uint(display_w), uint(display_h))
        // bgfx_touch(0u)   // NOTE: this introduces artifacts in OpenGL
        let t = glfwGetTime()
        if t > 10lf
            glfwSetTime(t - 10lf)
        let rot = un_quat_from_unit_vec_ang(normalize(float3(1.,1.,0.)), float(t)*PI*2.*0.1)
        let v_view = look_at_lh(float3(0,0,-5),float3(0,0,0),float3(0,1,0))
        let v_model = compose(float4(0,0,0,0), rot, float4(1.0))
        let v_projection = bgfx_mat_projection(60., 1280., 720., 0.1, 100., bgfx_get_caps().homogeneousDepth,true)
        bgfx_set_view_transform(0u, safe_addr(v_view), safe_addr(v_projection))
        bgfx_set_transform(safe_addr(v_model), 1u)
        bgfx_set_vertex_buffer(0u, vbh, 0u, uint(length(cubeVertices)))
        bgfx_set_index_buffer(ibh, 0u, uint(length(cubeTriList)))
        bgfx_submit(0u, program, 1u, BGFX_DISCARD_NONE)
		bgfx_dbg_text_clear(0u, false)
		bgfx_dbg_text_printf(1u, 1u, 0x0f, "Hello BGFX")
        bgfx_frame(true)
    bgfx_shutdown()

