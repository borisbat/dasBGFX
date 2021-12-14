
#include "daScript/misc/platform.h"
#include "daScript/daScript.h"
#include "daScript/ast/ast_typefactory_bind.h"
#include "need_bgfx.h"
#define GLOBAL_NAMESPACE
using namespace das;
namespace das {
void Module_BGFX::initFunctions_0() {
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_set_condition)>(*this, lib, "bgfx_set_condition",SideEffects::worstDefault, "bgfx_set_condition")
	->args({"_handle","_visible"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_destroy_uniform)>(*this, lib, "bgfx_destroy_uniform",SideEffects::worstDefault, "bgfx_destroy_uniform")
	->args({"_handle"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_set_view_clear_mrt)>(*this, lib, "bgfx_set_view_clear_mrt",SideEffects::worstDefault, "bgfx_set_view_clear_mrt")
	->args({"_id","_flags","_depth","_stencil","_c0","_c1","_c2","_c3","_c4","_c5","_c6","_c7"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_set_image)>(*this, lib, "bgfx_set_image",SideEffects::worstDefault, "bgfx_set_image")
	->args({"_stage","_handle","_mip","_access","_format"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_make_ref)>(*this, lib, "bgfx_make_ref",SideEffects::worstDefault, "bgfx_make_ref")
	->args({"_data","_size"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_encoder_set_image)>(*this, lib, "bgfx_encoder_set_image",SideEffects::worstDefault, "bgfx_encoder_set_image")
	->args({"_this","_stage","_handle","_mip","_access","_format"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_get_avail_transient_index_buffer)>(*this, lib, "bgfx_get_avail_transient_index_buffer",SideEffects::worstDefault, "bgfx_get_avail_transient_index_buffer")
	->args({"_num","_index32"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_destroy_shader)>(*this, lib, "bgfx_destroy_shader",SideEffects::worstDefault, "bgfx_destroy_shader")
	->args({"_handle"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_get_renderer_type)>(*this, lib, "bgfx_get_renderer_type",SideEffects::worstDefault, "bgfx_get_renderer_type")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_set_palette_color)>(*this, lib, "bgfx_set_palette_color",SideEffects::worstDefault, "bgfx_set_palette_color")
	->args({"_index","_rgba"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_create_dynamic_index_buffer), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "bgfx_create_dynamic_index_buffer",SideEffects::worstDefault, "bgfx_create_dynamic_index_buffer")
	->args({"_num","_flags"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_encoder_set_instance_data_buffer)>(*this, lib, "bgfx_encoder_set_instance_data_buffer",SideEffects::worstDefault, "bgfx_encoder_set_instance_data_buffer")
	->args({"_this","_idb","_start","_num"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_encoder_set_state)>(*this, lib, "bgfx_encoder_set_state",SideEffects::worstDefault, "bgfx_encoder_set_state")
	->args({"_this","_state","_rgba"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_vertex_layout_skip)>(*this, lib, "bgfx_vertex_layout_skip",SideEffects::worstDefault, "bgfx_vertex_layout_skip")
	->args({"_this","_num"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_update_dynamic_vertex_buffer)>(*this, lib, "bgfx_update_dynamic_vertex_buffer",SideEffects::worstDefault, "bgfx_update_dynamic_vertex_buffer")
	->args({"_handle","_startVertex","_mem"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_frame)>(*this, lib, "bgfx_frame",SideEffects::worstDefault, "bgfx_frame")
	->args({"_capture"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_create_compute_program), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "bgfx_create_compute_program",SideEffects::worstDefault, "bgfx_create_compute_program")
	->args({"_csh","_destroyShaders"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_dbg_text_image)>(*this, lib, "bgfx_dbg_text_image",SideEffects::worstDefault, "bgfx_dbg_text_image")
	->args({"_x","_y","_width","_height","_data","_pitch"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_encoder_dispatch)>(*this, lib, "bgfx_encoder_dispatch",SideEffects::worstDefault, "bgfx_encoder_dispatch")
	->args({"_this","_id","_program","_numX","_numY","_numZ","_flags"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_encoder_blit)>(*this, lib, "bgfx_encoder_blit",SideEffects::worstDefault, "bgfx_encoder_blit")
	->args({"_this","_id","_dst","_dstMip","_dstX","_dstY","_dstZ","_src","_srcMip","_srcX","_srcY","_srcZ","_width","_height","_depth"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_reset)>(*this, lib, "bgfx_reset",SideEffects::worstDefault, "bgfx_reset")
	->args({"_width","_height","_flags","_format"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_discard)>(*this, lib, "bgfx_discard",SideEffects::worstDefault, "bgfx_discard")
	->args({"_flags"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_alloc_transient_vertex_buffer)>(*this, lib, "bgfx_alloc_transient_vertex_buffer",SideEffects::worstDefault, "bgfx_alloc_transient_vertex_buffer")
	->args({"_tvb","_num","_layout"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_read_texture)>(*this, lib, "bgfx_read_texture",SideEffects::worstDefault, "bgfx_read_texture")
	->args({"_handle","_data","_mip"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_set_transient_vertex_buffer)>(*this, lib, "bgfx_set_transient_vertex_buffer",SideEffects::worstDefault, "bgfx_set_transient_vertex_buffer")
	->args({"_stream","_tvb","_startVertex","_numVertices"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_encoder_alloc_transform)>(*this, lib, "bgfx_encoder_alloc_transform",SideEffects::worstDefault, "bgfx_encoder_alloc_transform")
	->args({"_this","_transform","_num"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_set_compute_dynamic_vertex_buffer)>(*this, lib, "bgfx_set_compute_dynamic_vertex_buffer",SideEffects::worstDefault, "bgfx_set_compute_dynamic_vertex_buffer")
	->args({"_stage","_handle","_access"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_create_frame_buffer_scaled), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "bgfx_create_frame_buffer_scaled",SideEffects::worstDefault, "bgfx_create_frame_buffer_scaled")
	->args({"_ratio","_format","_textureFlags"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_submit_occlusion_query)>(*this, lib, "bgfx_submit_occlusion_query",SideEffects::worstDefault, "bgfx_submit_occlusion_query")
	->args({"_id","_program","_occlusionQuery","_depth","_flags"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_destroy_frame_buffer)>(*this, lib, "bgfx_destroy_frame_buffer",SideEffects::worstDefault, "bgfx_destroy_frame_buffer")
	->args({"_handle"})
;
#endif

}
}
