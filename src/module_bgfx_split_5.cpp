
#include "daScript/misc/platform.h"
#include "daScript/daScript.h"
#include "daScript/ast/ast_typefactory_bind.h"
#include "need_bgfx.h"
#define GLOBAL_NAMESPACE
using namespace das;
namespace das {
void Module_BGFX::initFunctions_5() {
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_encoder_set_dynamic_vertex_buffer)>(*this, lib, "bgfx_encoder_set_dynamic_vertex_buffer",SideEffects::worstDefault, "bgfx_encoder_set_dynamic_vertex_buffer")
	->args({"_this","_stream","_handle","_startVertex","_numVertices"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_set_shader_name)>(*this, lib, "bgfx_set_shader_name",SideEffects::worstDefault, "bgfx_set_shader_name")
	->args({"_handle","_name","_len"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_encoder_set_transient_index_buffer)>(*this, lib, "bgfx_encoder_set_transient_index_buffer",SideEffects::worstDefault, "bgfx_encoder_set_transient_index_buffer")
	->args({"_this","_tib","_firstIndex","_numIndices"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_set_debug)>(*this, lib, "bgfx_set_debug",SideEffects::worstDefault, "bgfx_set_debug")
	->args({"_debug"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_set_palette_color_rgba8)>(*this, lib, "bgfx_set_palette_color_rgba8",SideEffects::worstDefault, "bgfx_set_palette_color_rgba8")
	->args({"_index","_rgba"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_set_index_buffer)>(*this, lib, "bgfx_set_index_buffer",SideEffects::worstDefault, "bgfx_set_index_buffer")
	->args({"_handle","_firstIndex","_numIndices"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_set_compute_index_buffer)>(*this, lib, "bgfx_set_compute_index_buffer",SideEffects::worstDefault, "bgfx_set_compute_index_buffer")
	->args({"_stage","_handle","_access"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_weld_vertices)>(*this, lib, "bgfx_weld_vertices",SideEffects::worstDefault, "bgfx_weld_vertices")
	->args({"_output","_layout","_data","_num","_index32","_epsilon"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_set_dynamic_index_buffer)>(*this, lib, "bgfx_set_dynamic_index_buffer",SideEffects::worstDefault, "bgfx_set_dynamic_index_buffer")
	->args({"_handle","_firstIndex","_numIndices"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_encoder_set_vertex_buffer)>(*this, lib, "bgfx_encoder_set_vertex_buffer",SideEffects::worstDefault, "bgfx_encoder_set_vertex_buffer")
	->args({"_this","_stream","_handle","_startVertex","_numVertices"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_encoder_set_dynamic_index_buffer)>(*this, lib, "bgfx_encoder_set_dynamic_index_buffer",SideEffects::worstDefault, "bgfx_encoder_set_dynamic_index_buffer")
	->args({"_this","_handle","_firstIndex","_numIndices"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_set_vertex_buffer)>(*this, lib, "bgfx_set_vertex_buffer",SideEffects::worstDefault, "bgfx_set_vertex_buffer")
	->args({"_stream","_handle","_startVertex","_numVertices"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_destroy_occlusion_query)>(*this, lib, "bgfx_destroy_occlusion_query",SideEffects::worstDefault, "bgfx_destroy_occlusion_query")
	->args({"_handle"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_encoder_set_scissor)>(*this, lib, "bgfx_encoder_set_scissor",SideEffects::worstDefault, "bgfx_encoder_set_scissor")
	->args({"_this","_x","_y","_width","_height"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_get_avail_instance_data_buffer)>(*this, lib, "bgfx_get_avail_instance_data_buffer",SideEffects::worstDefault, "bgfx_get_avail_instance_data_buffer")
	->args({"_num","_stride"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_set_transient_vertex_buffer_with_layout)>(*this, lib, "bgfx_set_transient_vertex_buffer_with_layout",SideEffects::worstDefault, "bgfx_set_transient_vertex_buffer_with_layout")
	->args({"_stream","_tvb","_startVertex","_numVertices","_layoutHandle"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_alloc_instance_data_buffer)>(*this, lib, "bgfx_alloc_instance_data_buffer",SideEffects::worstDefault, "bgfx_alloc_instance_data_buffer")
	->args({"_idb","_num","_stride"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_get_stats)>(*this, lib, "bgfx_get_stats",SideEffects::worstDefault, "bgfx_get_stats")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_set_view_order)>(*this, lib, "bgfx_set_view_order",SideEffects::worstDefault, "bgfx_set_view_order")
	->args({"_id","_num","_order"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_set_transform_cached)>(*this, lib, "bgfx_set_transform_cached",SideEffects::worstDefault, "bgfx_set_transform_cached")
	->args({"_cache","_num"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_encoder_set_transient_vertex_buffer_with_layout)>(*this, lib, "bgfx_encoder_set_transient_vertex_buffer_with_layout",SideEffects::worstDefault, "bgfx_encoder_set_transient_vertex_buffer_with_layout")
	->args({"_this","_stream","_tvb","_startVertex","_numVertices","_layoutHandle"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_destroy_vertex_layout)>(*this, lib, "bgfx_destroy_vertex_layout",SideEffects::worstDefault, "bgfx_destroy_vertex_layout")
	->args({"_layoutHandle"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_destroy_index_buffer)>(*this, lib, "bgfx_destroy_index_buffer",SideEffects::worstDefault, "bgfx_destroy_index_buffer")
	->args({"_handle"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_get_supported_renderers)>(*this, lib, "bgfx_get_supported_renderers",SideEffects::worstDefault, "bgfx_get_supported_renderers")
	->args({"_max","_enum"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_set_instance_data_from_dynamic_vertex_buffer)>(*this, lib, "bgfx_set_instance_data_from_dynamic_vertex_buffer",SideEffects::worstDefault, "bgfx_set_instance_data_from_dynamic_vertex_buffer")
	->args({"_handle","_startVertex","_num"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_vertex_pack)>(*this, lib, "bgfx_vertex_pack",SideEffects::worstDefault, "bgfx_vertex_pack")
	->args({"_input","_inputNormalized","_attr","_layout","_data","_index"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_alloc_transient_buffers)>(*this, lib, "bgfx_alloc_transient_buffers",SideEffects::worstDefault, "bgfx_alloc_transient_buffers")
	->args({"_tvb","_layout","_numVertices","_tib","_numIndices","_index32"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_get_uniform_info)>(*this, lib, "bgfx_get_uniform_info",SideEffects::worstDefault, "bgfx_get_uniform_info")
	->args({"_handle","_info"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_encoder_set_vertex_buffer_with_layout)>(*this, lib, "bgfx_encoder_set_vertex_buffer_with_layout",SideEffects::worstDefault, "bgfx_encoder_set_vertex_buffer_with_layout")
	->args({"_this","_stream","_handle","_startVertex","_numVertices","_layoutHandle"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_encoder_set_uniform)>(*this, lib, "bgfx_encoder_set_uniform",SideEffects::worstDefault, "bgfx_encoder_set_uniform")
	->args({"_this","_handle","_value","_num"})
;
#endif

}
}
