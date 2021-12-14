
#include "daScript/misc/platform.h"
#include "daScript/daScript.h"
#include "daScript/ast/ast_typefactory_bind.h"
#include "need_bgfx.h"
#define GLOBAL_NAMESPACE
using namespace das;
namespace das {
void Module_BGFX::initFunctions_6() {
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_encoder_set_transient_vertex_buffer)>(*this, lib, "bgfx_encoder_set_transient_vertex_buffer",SideEffects::worstDefault, "bgfx_encoder_set_transient_vertex_buffer")
	->args({"_this","_stream","_tvb","_startVertex","_numVertices"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_set_view_mode)>(*this, lib, "bgfx_set_view_mode",SideEffects::worstDefault, "bgfx_set_view_mode")
	->args({"_id","_mode"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_override_internal_texture)>(*this, lib, "bgfx_override_internal_texture",SideEffects::worstDefault, "bgfx_override_internal_texture")
	->args({"_handle","_width","_height","_numMips","_format","_flags"})
;
#endif

}
}
