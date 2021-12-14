
#include "daScript/misc/platform.h"
#include "daScript/daScript.h"
#include "daScript/ast/ast_typefactory_bind.h"
#include "need_bgfx.h"
#define GLOBAL_NAMESPACE
using namespace das;
namespace das {
void Module_BGFX::initFunctions_4() {
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_destroy_dynamic_index_buffer)>(*this, lib, "bgfx_destroy_dynamic_index_buffer",SideEffects::worstDefault, "bgfx_destroy_dynamic_index_buffer")
	->args({"_handle"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_set_instance_data_from_vertex_buffer)>(*this, lib, "bgfx_set_instance_data_from_vertex_buffer",SideEffects::worstDefault, "bgfx_set_instance_data_from_vertex_buffer")
	->args({"_handle","_startVertex","_num"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_encoder_set_compute_dynamic_index_buffer)>(*this, lib, "bgfx_encoder_set_compute_dynamic_index_buffer",SideEffects::worstDefault, "bgfx_encoder_set_compute_dynamic_index_buffer")
	->args({"_this","_stage","_handle","_access"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_set_texture_name)>(*this, lib, "bgfx_set_texture_name",SideEffects::worstDefault, "bgfx_set_texture_name")
	->args({"_handle","_name","_len"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_update_texture_cube)>(*this, lib, "bgfx_update_texture_cube",SideEffects::worstDefault, "bgfx_update_texture_cube")
	->args({"_handle","_layer","_side","_mip","_x","_y","_width","_height","_mem","_pitch"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_get_renderer_name)>(*this, lib, "bgfx_get_renderer_name",SideEffects::worstDefault, "bgfx_get_renderer_name")
	->args({"_type"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_request_screen_shot)>(*this, lib, "bgfx_request_screen_shot",SideEffects::worstDefault, "bgfx_request_screen_shot")
	->args({"_handle","_filePath"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_init)>(*this, lib, "bgfx_init",SideEffects::worstDefault, "bgfx_init")
	->args({"_init"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_encoder_submit_occlusion_query)>(*this, lib, "bgfx_encoder_submit_occlusion_query",SideEffects::worstDefault, "bgfx_encoder_submit_occlusion_query")
	->args({"_this","_id","_program","_occlusionQuery","_depth","_flags"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_encoder_set_vertex_count)>(*this, lib, "bgfx_encoder_set_vertex_count",SideEffects::worstDefault, "bgfx_encoder_set_vertex_count")
	->args({"_this","_numVertices"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_encoder_discard)>(*this, lib, "bgfx_encoder_discard",SideEffects::worstDefault, "bgfx_encoder_discard")
	->args({"_this","_flags"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_create_program), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "bgfx_create_program",SideEffects::worstDefault, "bgfx_create_program")
	->args({"_vsh","_fsh","_destroyShaders"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_touch)>(*this, lib, "bgfx_touch",SideEffects::worstDefault, "bgfx_touch")
	->args({"_id"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_encoder_end)>(*this, lib, "bgfx_encoder_end",SideEffects::worstDefault, "bgfx_encoder_end")
	->args({"_encoder"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_create_texture_2d_scaled), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "bgfx_create_texture_2d_scaled",SideEffects::worstDefault, "bgfx_create_texture_2d_scaled")
	->args({"_ratio","_hasMips","_numLayers","_format","_flags"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_get_caps)>(*this, lib, "bgfx_get_caps",SideEffects::worstDefault, "bgfx_get_caps")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_alloc_transient_index_buffer)>(*this, lib, "bgfx_alloc_transient_index_buffer",SideEffects::worstDefault, "bgfx_alloc_transient_index_buffer")
	->args({"_tib","_num","_index32"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_encoder_set_dynamic_vertex_buffer_with_layout)>(*this, lib, "bgfx_encoder_set_dynamic_vertex_buffer_with_layout",SideEffects::worstDefault, "bgfx_encoder_set_dynamic_vertex_buffer_with_layout")
	->args({"_this","_stream","_handle","_startVertex","_numVertices","_layoutHandle"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_get_avail_transient_vertex_buffer)>(*this, lib, "bgfx_get_avail_transient_vertex_buffer",SideEffects::worstDefault, "bgfx_get_avail_transient_vertex_buffer")
	->args({"_num","_layout"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_set_instance_data_buffer)>(*this, lib, "bgfx_set_instance_data_buffer",SideEffects::worstDefault, "bgfx_set_instance_data_buffer")
	->args({"_idb","_start","_num"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_is_texture_valid)>(*this, lib, "bgfx_is_texture_valid",SideEffects::worstDefault, "bgfx_is_texture_valid")
	->args({"_depth","_cubeMap","_numLayers","_format","_flags"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_set_compute_vertex_buffer)>(*this, lib, "bgfx_set_compute_vertex_buffer",SideEffects::worstDefault, "bgfx_set_compute_vertex_buffer")
	->args({"_stage","_handle","_access"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_set_frame_buffer_name)>(*this, lib, "bgfx_set_frame_buffer_name",SideEffects::worstDefault, "bgfx_set_frame_buffer_name")
	->args({"_handle","_name","_len"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_create_vertex_buffer), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "bgfx_create_vertex_buffer",SideEffects::worstDefault, "bgfx_create_vertex_buffer")
	->args({"_mem","_layout","_flags"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_get_result)>(*this, lib, "bgfx_get_result",SideEffects::worstDefault, "bgfx_get_result")
	->args({"_handle","_result"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_alloc_transform)>(*this, lib, "bgfx_alloc_transform",SideEffects::worstDefault, "bgfx_alloc_transform")
	->args({"_transform","_num"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_destroy_texture)>(*this, lib, "bgfx_destroy_texture",SideEffects::worstDefault, "bgfx_destroy_texture")
	->args({"_handle"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_create_vertex_layout), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "bgfx_create_vertex_layout",SideEffects::worstDefault, "bgfx_create_vertex_layout")
	->args({"_layout"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_attachment_init)>(*this, lib, "bgfx_attachment_init",SideEffects::worstDefault, "bgfx_attachment_init")
	->args({"_this","_handle","_access","_layer","_numLayers","_mip","_resolve"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_make_ref_release)>(*this, lib, "bgfx_make_ref_release",SideEffects::worstDefault, "bgfx_make_ref_release")
	->args({"_data","_size","_releaseFn","_userData"})
;
#endif

}
}
