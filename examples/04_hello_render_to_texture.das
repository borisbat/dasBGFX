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
var [[uniform]] f_offset : float4

[bgfx_vertex_program(name="VERTEX_SRC")]
def vs_main
    v_color0 = a_color0
    v_texcoord0 = a_texcoord0
    gl_Position = u_modelViewProj * float4(a_position, 0.0, 1.0)

[bgfx_fragment_program(name="FRAGMENT_SRC")]
def fs_main
    gl_FragColor = texture2D(f_tex,v_texcoord0+f_offset.xy) * float4(v_color0, 1.0)

def checker(uv:float2; checkSize:float=8.0)
    let fmodResult = (floor(checkSize * uv.x) + floor(checkSize * uv.y)) % 2.0
    return max(sign(fmodResult), 0.0);

def greyscale(color:float3)
    return dot(color,float3(0.2126,0.7152,0.0722))

[bgfx_vertex_program(name="DISPLAY_VERTEX_SRC")]
def vs_display_main
    v_texcoord0 = a_texcoord0
    gl_Position = u_modelViewProj * float4(a_position, 0.0, 1.0)

[bgfx_fragment_program(name="DISPLAY_FRAGMENT_SRC")]
def fs_display_main
    let f = checker(v_texcoord0.xy)
    let trgb = texture2D(f_tex,float2(v_texcoord0.x,v_texcoord0.y * f_offset.w)).xyz
    let tgrey = greyscale(trgb)
    gl_FragColor.xyz = trgb*f + float3(tgrey)*(1.0-f)
    gl_FragColor.w = 1.

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

let VIEW_MAIN = 0u
let VIEW_FB = 1u

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
    var program = bgfx_create_shader_program(VERTEX_SRC, VERTEX_SRC_DECL, FRAGMENT_SRC, FRAGMENT_SRC_DECL, render_type)
    var display_program = bgfx_create_shader_program(DISPLAY_VERTEX_SRC, DISPLAY_VERTEX_SRC_DECL, DISPLAY_FRAGMENT_SRC, DISPLAY_FRAGMENT_SRC_DECL, render_type)
    var texture = bgfx_load_image_from_file("{get_das_root()}/modules/dasBgfx/examples/image.png")
    var frame_buffer = bgfx_create_frame_buffer(uint(WNDW_WIDTH), uint(WNDW_HEIGHT),
        bgfx_texture_format BGFX_TEXTURE_FORMAT_RGBA8, BGFX_TEXTURE_NONE)
    let v_ortho = bgfx_mat_ortho(-1.,1.,-1.,1.,0.,100.,0.,bgfx_get_caps().homogeneousDepth,false)
    bgfx_set_view_name(VIEW_MAIN, "main")
    bgfx_set_view_clear(VIEW_MAIN, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, RGBA_TO_BGFX_UCOLOR(0.2,0.2,0.2,1.0), 1.0f, 0u)
    bgfx_set_view_frame_buffer(VIEW_MAIN, [[bgfx_frame_buffer_handle_s idx=BGFX_INVALID_HANDLE]])
    bgfx_set_view_name(VIEW_FB, "fb")
    bgfx_set_view_clear(VIEW_FB, BGFX_CLEAR_COLOR, 0u, 1.0f, 0u)
    bgfx_set_view_frame_buffer(VIEW_FB,frame_buffer)
    while glfwWindowShouldClose(window)==0
        glfwPollEvents()
        var display_w, display_h : int
        glfwGetFramebufferSize(window, display_w, display_h)
        let t = glfwGetTime()
        if t > 1lf
            glfwSetTime(t - 1lf)
        let ft = float(t)
        f_offset = float4(ft,sin(ft*PI*2.)*0.25,0.,bgfx_get_caps().originBottomLeft ? -1. : 1.)
        bgfx_set_view_transform(VIEW_FB, null, safe_addr(v_ortho))
        bgfx_set_view_rect(VIEW_FB, 0u, 0u, uint(display_w), uint(display_h))
        bgfx_set_vertex_buffer(0u, vbh, 0u, uint(length(vertices)))
        bgfx_set_index_buffer(ibh, 0u, uint(length(indices)))
        f_tex.texture2D = uint(texture.idx)
        vs_main_bind_uniform()
        fs_main_bind_uniform()
        bgfx_submit(VIEW_FB, program, 1u, BGFX_DISCARD_NONE)
        bgfx_set_view_transform(VIEW_MAIN, null, safe_addr(v_ortho))
        bgfx_set_view_rect(VIEW_MAIN, 0u, 0u, uint(display_w), uint(display_h))
        bgfx_set_vertex_buffer(0u, vbh, 0u, uint(length(vertices)))
        bgfx_set_index_buffer(ibh, 0u, uint(length(indices)))
        f_tex.texture2D = uint(bgfx_get_texture(frame_buffer,0u).idx)
        vs_display_main_bind_uniform()
        fs_display_main_bind_uniform()
        bgfx_submit(VIEW_MAIN, display_program, 1u, BGFX_DISCARD_NONE)
        bgfx_frame(false)
    bgfx_shutdown()
