require glfw/glfw_boost
require dasbgfx/bgfx_boost
require daslib/defer
require daslib/math_boost
require daslib/safe_addr

require imgui
require imgui_app
require bgfx_imgui

[export]
def main
    let WNDW_WIDTH = 1280
    let WNDW_HEIGHT = 720
    if glfwInit()==0
		panic("can't init glfw")
    defer <|
        glfwTerminate()
    var window = glfwCreateWindow(WNDW_WIDTH, WNDW_HEIGHT, "BGFX - Hello IMGUI", null, null)
    if window==null
		panic("can't create window")
    defer <|
        glfwDestroyWindow(window)
    glfwMakeContextCurrent(window)
    var pd: bgfx_platform_data_s
    pd.nwh = glfwGetWin32Window(window)
    bgfx_set_platform_data(safe_addr(pd))
    bgfx_init(WNDW_WIDTH,WNDW_HEIGHT)
    glfwSetWindowTitle(window, "BGFX - Hello IMGUI - {bgfx_get_renderer_type()}")
    CreateContext(null)
    //var io & = imgui::GetIO()
    // unsafe
    //    debug(intptr(addr(io)),"IO at")
    // io.FontGlobalScale = 1.0   // BBATKIN: note - my monitor is HUGE
    // StyleColorsDark(null)
    bgfx_imgui_create(18.)
    ImGui_ImplGlfw_InitForOther(window, true)
    bgfx_set_view_clear(0u, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, RGBA_TO_BGFX_UCOLOR(0.2,0.2,0.2,1.0), 1.0f, 0u)
    while glfwWindowShouldClose(window)==0
        glfwPollEvents()
        ImGui_ImplGlfw_NewFrame()
        bgfx_imgui_begin_frame(255)
        bgfx_set_view_rect(0u, 0u, 0u, uint(WNDW_WIDTH), uint(WNDW_HEIGHT))
		// This dummy draw call is here to make sure that view 0 is cleared
		// if no other draw calls are submitted to view 0.
		let encoder = bgfx_encoder_begin(true)
		bgfx_encoder_touch(encoder, 0u)
		bgfx_encoder_end(encoder)
        ShowDemoWindow()
        bgfx_imgui_end_frame()
        bgfx_frame(true)
    ImGui_ImplGlfw_Shutdown()
    bgfx_imgui_destroy()
    bgfx_shutdown()
