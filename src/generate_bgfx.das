require fio
require strings
require daslib/strings_boost
require daslib/cpp_gen


[export]
def main
    // configure
    blocked_type_names <- [{auto[]
        "bgfx_callback_interface_t";
        "bgfx_indirect_buffer_handle_t"
    }]

    blocked_functions <- [{auto[]
        "bgfx_get_interface";
        "dbg_text_printf";
        "dbg_text_vprintf";
        "operator delete";
        "operator new";
        "__security_init_cookie";
        "__security_check_cookie"
    }]

/*
    cmres_functions <- [{auto[]
        "ImGui_ImplVulkanH_SelectSurfaceFormat"
    }]
*/

    enum_suffix = "_t"

    is_struct_blocked <- @ <| ( st:string ) : bool
        if (st=="bgfx_callback_vtbl_s" || st=="bgfx_encoder_s" || st=="bgfx_interface_vtbl" || st=="bgfx_callback_interface_s")
            return true
        if st |> starts_with("bgfx")
            return false
        return true

    is_function_blocked <- @ <| ( fn:string ) : bool
        if fn |> starts_with("bgfx")
            return false
        return true

    alt_struct_name <- @ <| ( st:string ) : string
        if st |> ends_with("_t")
            let nn = st |> chop ( 0, length(st)-2 )
            return "{nn}_s"
        return ""

    // generate
    allow_extern_c = true
    var args <- get_command_line_arguments()
    bindHeaders(args[3], args[4])

    /*
    const_type_table <- {{
        "BGFX_STATE_DEPTH_TEST_SHIFT" => "uint64_t";
        "BGFX_STATE_BLEND_SHIFT" => "uint64_t";
        "BGFX_STATE_BLEND_EQUATION_SHIFT" => "uint64_t";
        "BGFX_STATE_CULL_SHIFT" => "uint64_t";
        "BGFX_STATE_ALPHA_REF_SHIFT" => "uint64_t";
        "BGFX_STATE_PT_SHIFT" => "uint64_t";
        "BGFX_STATE_RESERVED_SHIFT" => "uint64_t";

        "BGFX_STENCIL_FUNC_REF_SHIFT" => "uint32_t";
        "BGFX_STENCIL_FUNC_RMASK_SHIFT" => "uint32_t";
        "BGFX_STENCIL_TEST_SHIFT" => "uint32_t";
        "BGFX_STENCIL_OP_FAIL_S_SHIFT" => "uint32_t";
        "BGFX_STENCIL_OP_FAIL_Z_SHIFT" => "uint32_t";
        "BGFX_STENCIL_OP_PASS_Z_SHIFT" => "uint32_t"
    }}
    */

    const_uint8_type = "uint32_t"
    const_uint16_type = "uint32_t"

    print("consts headers to bind: ${args[5]}\n")
    genDefineConstants(split(args[5], ";"), args[4])


