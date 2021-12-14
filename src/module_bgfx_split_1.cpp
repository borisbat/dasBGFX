
#include "daScript/misc/platform.h"
#include "daScript/daScript.h"
#include "daScript/ast/ast_typefactory_bind.h"
#include "need_bgfx.h"
#define GLOBAL_NAMESPACE
using namespace das;
namespace das {
void Module_BGFX::initFunctions_1() {
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_create_frame_buffer_from_attachment), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "bgfx_create_frame_buffer_from_attachment",SideEffects::worstDefault, "bgfx_create_frame_buffer_from_attachment")
	->args({"_num","_attachment","_destroyTexture"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_encoder_set_texture)>(*this, lib, "bgfx_encoder_set_texture",SideEffects::worstDefault, "bgfx_encoder_set_texture")
	->args({"_this","_stage","_sampler","_handle","_flags"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_set_scissor_cached)>(*this, lib, "bgfx_set_scissor_cached",SideEffects::worstDefault, "bgfx_set_scissor_cached")
	->args({"_cache"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_create_indirect_buffer), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "bgfx_create_indirect_buffer",SideEffects::worstDefault, "bgfx_create_indirect_buffer")
	->args({"_num"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_set_stencil)>(*this, lib, "bgfx_set_stencil",SideEffects::worstDefault, "bgfx_set_stencil")
	->args({"_fstencil","_bstencil"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_set_view_name)>(*this, lib, "bgfx_set_view_name",SideEffects::worstDefault, "bgfx_set_view_name")
	->args({"_id","_name"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_vertex_layout_add)>(*this, lib, "bgfx_vertex_layout_add",SideEffects::worstDefault, "bgfx_vertex_layout_add")
	->args({"_this","_attrib","_num","_type","_normalized","_asInt"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_create_frame_buffer_from_nwh), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "bgfx_create_frame_buffer_from_nwh",SideEffects::worstDefault, "bgfx_create_frame_buffer_from_nwh")
	->args({"_nwh","_width","_height","_format","_depthFormat"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_set_view_frame_buffer)>(*this, lib, "bgfx_set_view_frame_buffer",SideEffects::worstDefault, "bgfx_set_view_frame_buffer")
	->args({"_id","_handle"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_get_direct_access_ptr)>(*this, lib, "bgfx_get_direct_access_ptr",SideEffects::worstDefault, "bgfx_get_direct_access_ptr")
	->args({"_handle"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_destroy_vertex_buffer)>(*this, lib, "bgfx_destroy_vertex_buffer",SideEffects::worstDefault, "bgfx_destroy_vertex_buffer")
	->args({"_handle"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_create_dynamic_vertex_buffer_mem), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "bgfx_create_dynamic_vertex_buffer_mem",SideEffects::worstDefault, "bgfx_create_dynamic_vertex_buffer_mem")
	->args({"_mem","_layout","_flags"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_create_occlusion_query), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "bgfx_create_occlusion_query",SideEffects::worstDefault, "bgfx_create_occlusion_query")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_dispatch)>(*this, lib, "bgfx_dispatch",SideEffects::worstDefault, "bgfx_dispatch")
	->args({"_id","_program","_numX","_numY","_numZ","_flags"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_set_view_scissor)>(*this, lib, "bgfx_set_view_scissor",SideEffects::worstDefault, "bgfx_set_view_scissor")
	->args({"_id","_x","_y","_width","_height"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_vertex_layout_decode)>(*this, lib, "bgfx_vertex_layout_decode",SideEffects::worstDefault, "bgfx_vertex_layout_decode")
	->args({"_this","_attrib","_num","_type","_normalized","_asInt"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_create_frame_buffer_from_handles), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "bgfx_create_frame_buffer_from_handles",SideEffects::worstDefault, "bgfx_create_frame_buffer_from_handles")
	->args({"_num","_handles","_destroyTexture"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_create_texture_cube), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "bgfx_create_texture_cube",SideEffects::worstDefault, "bgfx_create_texture_cube")
	->args({"_size","_hasMips","_numLayers","_format","_flags","_mem"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_render_frame)>(*this, lib, "bgfx_render_frame",SideEffects::worstDefault, "bgfx_render_frame")
	->args({"_msecs"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_vertex_layout_begin)>(*this, lib, "bgfx_vertex_layout_begin",SideEffects::worstDefault, "bgfx_vertex_layout_begin")
	->args({"_this","_rendererType"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_set_vertex_buffer_name)>(*this, lib, "bgfx_set_vertex_buffer_name",SideEffects::worstDefault, "bgfx_set_vertex_buffer_name")
	->args({"_handle","_name","_len"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_set_vertex_buffer_with_layout)>(*this, lib, "bgfx_set_vertex_buffer_with_layout",SideEffects::worstDefault, "bgfx_set_vertex_buffer_with_layout")
	->args({"_stream","_handle","_startVertex","_numVertices","_layoutHandle"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_create_uniform), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "bgfx_create_uniform",SideEffects::worstDefault, "bgfx_create_uniform")
	->args({"_name","_type","_num"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_vertex_layout_end)>(*this, lib, "bgfx_vertex_layout_end",SideEffects::worstDefault, "bgfx_vertex_layout_end")
	->args({"_this"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_encoder_set_compute_dynamic_vertex_buffer)>(*this, lib, "bgfx_encoder_set_compute_dynamic_vertex_buffer",SideEffects::worstDefault, "bgfx_encoder_set_compute_dynamic_vertex_buffer")
	->args({"_this","_stage","_handle","_access"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_set_transient_index_buffer)>(*this, lib, "bgfx_set_transient_index_buffer",SideEffects::worstDefault, "bgfx_set_transient_index_buffer")
	->args({"_tib","_firstIndex","_numIndices"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_reset_view)>(*this, lib, "bgfx_reset_view",SideEffects::worstDefault, "bgfx_reset_view")
	->args({"_id"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_create_dynamic_vertex_buffer), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "bgfx_create_dynamic_vertex_buffer",SideEffects::worstDefault, "bgfx_create_dynamic_vertex_buffer")
	->args({"_num","_layout","_flags"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_create_dynamic_index_buffer_mem), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "bgfx_create_dynamic_index_buffer_mem",SideEffects::worstDefault, "bgfx_create_dynamic_index_buffer_mem")
	->args({"_mem","_flags"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(bgfx_create_texture_2d), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "bgfx_create_texture_2d",SideEffects::worstDefault, "bgfx_create_texture_2d")
	->args({"_width","_height","_hasMips","_numLayers","_format","_flags","_mem"})
;
#endif

}
}
