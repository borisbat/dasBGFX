#include "daScript/misc/platform.h"

#include "daScript/daScript.h"
#include "daScript/ast/ast_typefactory_bind.h"

using namespace das;

#define BGFX_CAST_HANDLE_TYPE(tname) \
    template <> \
    struct cast_arg <tname> { \
        static __forceinline tname to ( Context & ctx, SimNode * x ) { \
            return *((tname *) x->evalPtr(ctx)); \
        } \
    };

#define USE_GENERATED   1

#if USE_GENERATED
#include "bgfx_headers.h"

MAKE_EXTERNAL_TYPE_FACTORY(bgfx_encoder_s,bgfx_encoder_s);

IMPLEMENT_EXTERNAL_TYPE_FACTORY(bgfx_encoder_s,bgfx_encoder_s);

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

#define GLOBAL_NAMESPACE
#include "module_bgfx.h"
#include "module_bgfx.enum.cpp_inc"
#include "module_bgfx.ann.cpp_inc"
#endif

namespace das {

void Das_bgfx_dbg_text_printf(uint16_t _x, uint16_t _y, uint8_t _attr, const char* text ) {
    bgfx_dbg_text_printf(_x, _y, _attr, "%s", text );
}

class Module_BGFX : public Module {
public:
    Module_BGFX() : Module("bgfx") {
        ModuleLibrary lib;
        lib.addModule(this);
        lib.addBuiltInModule();
#if USE_GENERATED
        addAnnotation(make_smart<DummyTypeAnnotation>("bgfx_encoder_s", "bgfx_encoder_s",1,1));

        #include "module_bgfx.enum.inc"
        #include "module_bgfx.ann.inc"
        #include "module_bgfx.inc"

        addExtern<DAS_BIND_FUN(Das_bgfx_dbg_text_printf)>(*this, lib, "bgfx_dbg_text_printf",SideEffects::worstDefault, "Das_bgfx_dbg_text_printf")
            ->args({"_x","_y","_attr","text"});

        addConstant(*this,"BGFX_RESET_VSYNC",BGFX_RESET_VSYNC);

        addConstant(*this,"BGFX_CLEAR_COLOR", BGFX_CLEAR_COLOR);
        addConstant(*this,"BGFX_CLEAR_DEPTH", BGFX_CLEAR_DEPTH);

        addConstant(*this,"BGFX_DEBUG_TEXT", BGFX_DEBUG_TEXT);
#endif
    }
    virtual ModuleAotType aotRequire ( TextWriter & tw ) const override {
        tw << "#include \"../modules/dasBGFX/src/dasBGFX.h\"\n";
        return ModuleAotType::cpp;
    }
};

}

REGISTER_MODULE_IN_NAMESPACE(Module_BGFX,das);

