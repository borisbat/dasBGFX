
#include "daScript/misc/platform.h"
#include "daScript/daScript.h"
#include "daScript/ast/ast_typefactory_bind.h"
#include "need_bgfx.h"
#define GLOBAL_NAMESPACE
using namespace das;
namespace das {
void Module_BGFX::initFunctions_2() {
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_create_texture_3d), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "bgfx_create_texture_3d",SideEffects::worstDefault, "bgfx_create_texture_3d")
	->args({"_width","_height","_depth","_hasMips","_format","_flags","_mem"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_create_index_buffer), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "bgfx_create_index_buffer",SideEffects::worstDefault, "bgfx_create_index_buffer")
	->args({"_mem","_flags"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_encoder_touch)>(*this, lib, "bgfx_encoder_touch",SideEffects::worstDefault, "bgfx_encoder_touch")
	->args({"_this","_id"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_encoder_set_scissor_cached)>(*this, lib, "bgfx_encoder_set_scissor_cached",SideEffects::worstDefault, "bgfx_encoder_set_scissor_cached")
	->args({"_this","_cache"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_set_view_rect)>(*this, lib, "bgfx_set_view_rect",SideEffects::worstDefault, "bgfx_set_view_rect")
	->args({"_id","_x","_y","_width","_height"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_encoder_set_stencil)>(*this, lib, "bgfx_encoder_set_stencil",SideEffects::worstDefault, "bgfx_encoder_set_stencil")
	->args({"_this","_fstencil","_bstencil"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_vertex_unpack)>(*this, lib, "bgfx_vertex_unpack",SideEffects::worstDefault, "bgfx_vertex_unpack")
	->args({"_output","_attr","_layout","_data","_index"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_get_internal_data)>(*this, lib, "bgfx_get_internal_data",SideEffects::worstDefault, "bgfx_get_internal_data")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_encoder_set_index_buffer)>(*this, lib, "bgfx_encoder_set_index_buffer",SideEffects::worstDefault, "bgfx_encoder_set_index_buffer")
	->args({"_this","_handle","_firstIndex","_numIndices"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_dbg_text_clear)>(*this, lib, "bgfx_dbg_text_clear",SideEffects::worstDefault, "bgfx_dbg_text_clear")
	->args({"_attr","_small"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_encoder_set_instance_count)>(*this, lib, "bgfx_encoder_set_instance_count",SideEffects::worstDefault, "bgfx_encoder_set_instance_count")
	->args({"_this","_numInstances"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_set_marker)>(*this, lib, "bgfx_set_marker",SideEffects::worstDefault, "bgfx_set_marker")
	->args({"_marker"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_vertex_layout_has)>(*this, lib, "bgfx_vertex_layout_has",SideEffects::worstDefault, "bgfx_vertex_layout_has")
	->args({"_this","_attrib"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_set_state)>(*this, lib, "bgfx_set_state",SideEffects::worstDefault, "bgfx_set_state")
	->args({"_state","_rgba"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_init_ctor)>(*this, lib, "bgfx_init_ctor",SideEffects::worstDefault, "bgfx_init_ctor")
	->args({"_init"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_destroy_program)>(*this, lib, "bgfx_destroy_program",SideEffects::worstDefault, "bgfx_destroy_program")
	->args({"_handle"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_set_view_transform)>(*this, lib, "bgfx_set_view_transform",SideEffects::worstDefault, "bgfx_set_view_transform")
	->args({"_id","_view","_proj"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_shutdown)>(*this, lib, "bgfx_shutdown",SideEffects::worstDefault, "bgfx_shutdown")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_override_internal_texture_ptr)>(*this, lib, "bgfx_override_internal_texture_ptr",SideEffects::worstDefault, "bgfx_override_internal_texture_ptr")
	->args({"_handle","_ptr"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_set_vertex_count)>(*this, lib, "bgfx_set_vertex_count",SideEffects::worstDefault, "bgfx_set_vertex_count")
	->args({"_numVertices"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_destroy_dynamic_vertex_buffer)>(*this, lib, "bgfx_destroy_dynamic_vertex_buffer",SideEffects::worstDefault, "bgfx_destroy_dynamic_vertex_buffer")
	->args({"_handle"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_update_texture_2d)>(*this, lib, "bgfx_update_texture_2d",SideEffects::worstDefault, "bgfx_update_texture_2d")
	->args({"_handle","_layer","_mip","_x","_y","_width","_height","_mem","_pitch"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_calc_texture_size)>(*this, lib, "bgfx_calc_texture_size",SideEffects::worstDefault, "bgfx_calc_texture_size")
	->args({"_info","_width","_height","_depth","_cubeMap","_hasMips","_numLayers","_format"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_update_texture_3d)>(*this, lib, "bgfx_update_texture_3d",SideEffects::worstDefault, "bgfx_update_texture_3d")
	->args({"_handle","_mip","_x","_y","_z","_width","_height","_depth","_mem"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_encoder_set_compute_vertex_buffer)>(*this, lib, "bgfx_encoder_set_compute_vertex_buffer",SideEffects::worstDefault, "bgfx_encoder_set_compute_vertex_buffer")
	->args({"_this","_stage","_handle","_access"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_set_instance_count)>(*this, lib, "bgfx_set_instance_count",SideEffects::worstDefault, "bgfx_set_instance_count")
	->args({"_numInstances"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_blit)>(*this, lib, "bgfx_blit",SideEffects::worstDefault, "bgfx_blit")
	->args({"_id","_dst","_dstMip","_dstX","_dstY","_dstZ","_src","_srcMip","_srcX","_srcY","_srcZ","_width","_height","_depth"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_set_platform_data)>(*this, lib, "bgfx_set_platform_data",SideEffects::worstDefault, "bgfx_set_platform_data")
	->args({"_data"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_create_shader), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "bgfx_create_shader",SideEffects::worstDefault, "bgfx_create_shader")
	->args({"_mem"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_vertex_convert)>(*this, lib, "bgfx_vertex_convert",SideEffects::worstDefault, "bgfx_vertex_convert")
	->args({"_dstLayout","_dstData","_srcLayout","_srcData","_num"})
;
#endif

}
}
