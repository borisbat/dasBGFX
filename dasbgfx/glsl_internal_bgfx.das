options indenting = 4
options no_unused_block_arguments = false
options no_unused_function_arguments = false

module glsl_internal_bgfx shared

require glsl/glsl_internal
require daslib/ast_boost
require daslib/strings_boost

class GlslBgfxShader : GlslShader
    override write_version = false
    override output_inout = false
    override output_inout_stub = true
    override output_inout_decl = true
    override output_shader_lines = false
    override replace_hlsl_incompatible_operations = true
    override restrict_uniform_types = true      // only vec4, mat3x3 and mat4x4
    override glsl_prefix = "\n#include <bgfx_shader.sh>\n\n"
    def override generate_bind_uniform_dummy ( var func:FunctionPtr )
        generate_bgfx_bind_uniform_dummy(func)
    def override generate_bind_uniform(fnMain:FunctionPtr; var fn:FunctionPtr)
        generate_bgfx_bind_uniform(fnMain, fn)

[macro_function]
def private generate_bgfx_bind_uniform_dummy(fnMain:FunctionPtr)
    var fn <- new [[Function() at = fnMain.at, atDecl = fnMain.at, name := bind_uniform_function_name(fnMain)]]
    fn.flags |= FunctionFlags generated
    fn.flags |= FunctionFlags exports   // note: this is temporary, until we are done with dependency collecting etc
    fn.result <- new [[TypeDecl() baseType=Type tVoid, at=fnMain.at]]
    fn.body <- new [[ExprBlock() at=fnMain.at]]
    if !(compiling_module() |> add_function(fn))
        panic("can't setup")
    return true

[macro_function]
def private generate_bgfx_bind_uniform(fnMain:FunctionPtr; var fn:FunctionPtr)
    var blk <- new [[ExprBlock() at=fn.at]]
    collect_dependencies(fnMain) <| $ ( vfun, vvar )
        for vv in vvar
            if find_arg("uniform", vv.annotation) is tBool
                if "{vv._module.name}" |> find("glsl_") == -1
                    var cll_uni <- new [[ExprCall() at=vv.at, name:="bgfx_any_uniform"]]
                    cll_uni.arguments |> emplace_new() <| new [[ExprConstString() at=vv.at, value:=vv.name]]
                    cll_uni.arguments |> emplace_new() <| new [[ExprVar() at=vv.at, name:=vv.name]]
                    blk.list |>emplace(cll_uni)
    fn.body := blk
    if DEBUG_SHADER_BINDINGS
        print("{describe(fn)}\n")

[function_macro(name="bgfx_vertex_program")]
class GlslBgfxVertexProgram : GlslBgfxShader
    override shaderType = ShaderType vertex

[function_macro(name="bgfx_fragment_program")]
class GlslBgfxPixelProgram : GlslBgfxShader
    override shaderType = ShaderType fragment

[function_macro(name="bgfx_compute_program")]
class GlslBgfxComputeProgram : GlslBgfxShader
    override shaderType = ShaderType compute
