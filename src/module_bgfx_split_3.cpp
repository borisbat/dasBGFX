
#include "daScript/misc/platform.h"
#include "daScript/daScript.h"
#include "daScript/ast/ast_typefactory_bind.h"
#include "need_bgfx.h"
#define GLOBAL_NAMESPACE
using namespace das;
namespace das {
void Module_BGFX::initFunctions_3() {
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_encoder_set_instance_data_from_dynamic_vertex_buffer)>(*this, lib, "bgfx_encoder_set_instance_data_from_dynamic_vertex_buffer",SideEffects::worstDefault, "bgfx_encoder_set_instance_data_from_dynamic_vertex_buffer")
	->args({"_this","_handle","_startVertex","_num"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_submit)>(*this, lib, "bgfx_submit",SideEffects::worstDefault, "bgfx_submit")
	->args({"_id","_program","_depth","_flags"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_alloc)>(*this, lib, "bgfx_alloc",SideEffects::worstDefault, "bgfx_alloc")
	->args({"_size"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_create_frame_buffer), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "bgfx_create_frame_buffer",SideEffects::worstDefault, "bgfx_create_frame_buffer")
	->args({"_width","_height","_format","_textureFlags"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_encoder_set_compute_index_buffer)>(*this, lib, "bgfx_encoder_set_compute_index_buffer",SideEffects::worstDefault, "bgfx_encoder_set_compute_index_buffer")
	->args({"_this","_stage","_handle","_access"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_update_dynamic_index_buffer)>(*this, lib, "bgfx_update_dynamic_index_buffer",SideEffects::worstDefault, "bgfx_update_dynamic_index_buffer")
	->args({"_handle","_startIndex","_mem"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_encoder_set_condition)>(*this, lib, "bgfx_encoder_set_condition",SideEffects::worstDefault, "bgfx_encoder_set_condition")
	->args({"_this","_handle","_visible"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_set_dynamic_vertex_buffer)>(*this, lib, "bgfx_set_dynamic_vertex_buffer",SideEffects::worstDefault, "bgfx_set_dynamic_vertex_buffer")
	->args({"_stream","_handle","_startVertex","_numVertices"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_copy)>(*this, lib, "bgfx_copy",SideEffects::worstDefault, "bgfx_copy")
	->args({"_data","_size"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_create_texture), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "bgfx_create_texture",SideEffects::worstDefault, "bgfx_create_texture")
	->args({"_mem","_flags","_skip","_info"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_encoder_set_transform_cached)>(*this, lib, "bgfx_encoder_set_transform_cached",SideEffects::worstDefault, "bgfx_encoder_set_transform_cached")
	->args({"_this","_cache","_num"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_encoder_set_instance_data_from_vertex_buffer)>(*this, lib, "bgfx_encoder_set_instance_data_from_vertex_buffer",SideEffects::worstDefault, "bgfx_encoder_set_instance_data_from_vertex_buffer")
	->args({"_this","_handle","_startVertex","_num"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_set_texture)>(*this, lib, "bgfx_set_texture",SideEffects::worstDefault, "bgfx_set_texture")
	->args({"_stage","_sampler","_handle","_flags"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_set_compute_dynamic_index_buffer)>(*this, lib, "bgfx_set_compute_dynamic_index_buffer",SideEffects::worstDefault, "bgfx_set_compute_dynamic_index_buffer")
	->args({"_stage","_handle","_access"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_set_view_rect_ratio)>(*this, lib, "bgfx_set_view_rect_ratio",SideEffects::worstDefault, "bgfx_set_view_rect_ratio")
	->args({"_id","_x","_y","_ratio"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_topology_convert)>(*this, lib, "bgfx_topology_convert",SideEffects::worstDefault, "bgfx_topology_convert")
	->args({"_conversion","_dst","_dstSize","_indices","_numIndices","_index32"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_set_uniform)>(*this, lib, "bgfx_set_uniform",SideEffects::worstDefault, "bgfx_set_uniform")
	->args({"_handle","_value","_num"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_is_frame_buffer_valid)>(*this, lib, "bgfx_is_frame_buffer_valid",SideEffects::worstDefault, "bgfx_is_frame_buffer_valid")
	->args({"_num","_attachment"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_set_scissor)>(*this, lib, "bgfx_set_scissor",SideEffects::worstDefault, "bgfx_set_scissor")
	->args({"_x","_y","_width","_height"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_encoder_submit)>(*this, lib, "bgfx_encoder_submit",SideEffects::worstDefault, "bgfx_encoder_submit")
	->args({"_this","_id","_program","_depth","_flags"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_encoder_begin)>(*this, lib, "bgfx_encoder_begin",SideEffects::worstDefault, "bgfx_encoder_begin")
	->args({"_forThread"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_get_shader_uniforms)>(*this, lib, "bgfx_get_shader_uniforms",SideEffects::worstDefault, "bgfx_get_shader_uniforms")
	->args({"_handle","_uniforms","_max"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_set_view_clear)>(*this, lib, "bgfx_set_view_clear",SideEffects::worstDefault, "bgfx_set_view_clear")
	->args({"_id","_flags","_rgba","_depth","_stencil"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_encoder_set_marker)>(*this, lib, "bgfx_encoder_set_marker",SideEffects::worstDefault, "bgfx_encoder_set_marker")
	->args({"_this","_marker"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_topology_sort_tri_list)>(*this, lib, "bgfx_topology_sort_tri_list",SideEffects::worstDefault, "bgfx_topology_sort_tri_list")
	->args({"_sort","_dst","_dstSize","_dir","_pos","_vertices","_stride","_indices","_numIndices","_index32"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_encoder_set_transform)>(*this, lib, "bgfx_encoder_set_transform",SideEffects::worstDefault, "bgfx_encoder_set_transform")
	->args({"_this","_mtx","_num"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_set_transform)>(*this, lib, "bgfx_set_transform",SideEffects::worstDefault, "bgfx_set_transform")
	->args({"_mtx","_num"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_set_dynamic_vertex_buffer_with_layout)>(*this, lib, "bgfx_set_dynamic_vertex_buffer_with_layout",SideEffects::worstDefault, "bgfx_set_dynamic_vertex_buffer_with_layout")
	->args({"_stream","_handle","_startVertex","_numVertices","_layoutHandle"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_get_texture), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "bgfx_get_texture",SideEffects::worstDefault, "bgfx_get_texture")
	->args({"_handle","_attachment"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_set_index_buffer_name)>(*this, lib, "bgfx_set_index_buffer_name",SideEffects::worstDefault, "bgfx_set_index_buffer_name")
	->args({"_handle","_name","_len"})
;
#endif

}
}
