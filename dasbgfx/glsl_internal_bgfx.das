options indenting = 4
options no_unused_block_arguments = false
options no_unused_function_arguments = false

module glsl_internal_bgfx shared

require glsl/glsl_internal
require daslib/ast_boost

class GlslBgfxShader : GlslShader
    override write_version = false
    override output_inout = false
    override output_inout_stub = true
    override output_inout_decl = true
    override output_shader_lines = false
    override replace_hlsl_incompatible_operations = true
    override glsl_prefix = "\n#include <bgfx_shader.sh>\n\n"

[function_macro(name="bgfx_vertex_program")]
class GlslBgfxVertexProgram : GlslBgfxShader
    override shaderType = ShaderType vertex

[function_macro(name="bgfx_fragment_program")]
class GlslBgfxPixelProgram : GlslBgfxShader
    override shaderType = ShaderType fragment

[function_macro(name="bgfx_compute_program")]
class GlslBgfxComputeProgram : GlslBgfxShader
    override shaderType = ShaderType compute
