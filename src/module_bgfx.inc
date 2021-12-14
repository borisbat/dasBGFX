// ------------
// functions
// ------------

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
