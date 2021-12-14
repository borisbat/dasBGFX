#pragma once

#include "bgfx_headers.h"
#include "bx/math.h"
#include "module_bgfx.h"

#define BGFX_CAST_HANDLE_TYPE(tname) \
    template <> \
    struct cast_arg <tname> { \
        static __forceinline tname to ( Context & ctx, SimNode * x ) { \
            return *((tname *) x->evalPtr(ctx)); \
        } \
    };

namespace das {
BGFX_CAST_HANDLE_TYPE(bgfx_dynamic_vertex_buffer_handle_t);
BGFX_CAST_HANDLE_TYPE(bgfx_occlusion_query_handle_t);
BGFX_CAST_HANDLE_TYPE(bgfx_frame_buffer_handle_t);
BGFX_CAST_HANDLE_TYPE(bgfx_program_handle_t);
BGFX_CAST_HANDLE_TYPE(bgfx_texture_handle_t);
BGFX_CAST_HANDLE_TYPE(bgfx_dynamic_index_buffer_handle_t);
BGFX_CAST_HANDLE_TYPE(bgfx_vertex_buffer_handle_t);
BGFX_CAST_HANDLE_TYPE(bgfx_uniform_handle_t);
BGFX_CAST_HANDLE_TYPE(bgfx_vertex_layout_handle_t);
BGFX_CAST_HANDLE_TYPE(bgfx_index_buffer_handle_t);
BGFX_CAST_HANDLE_TYPE(bgfx_shader_handle_t);
}

MAKE_EXTERNAL_TYPE_FACTORY(bgfx_encoder_s,bgfx_encoder_s);

namespace das {

    class Module_BGFX : public Module {
    public:
        Module_BGFX();
        virtual ModuleAotType aotRequire ( TextWriter & tw ) const override;
    protected:
        void initFunctions();
        void initFunctions_0();
        void initFunctions_1();
        void initFunctions_2();
        void initFunctions_3();
        void initFunctions_4();
        void initFunctions_5();
        void initFunctions_6();
    protected:
        ModuleLibrary lib;
    };

}

