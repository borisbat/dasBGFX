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

#define USE_GENERATED   0

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

class Module_BGFX : public Module {
public:
    Module_BGFX() : Module("bgfx") {
        ModuleLibrary lib;
        lib.addModule(this);
        lib.addBuiltInModule();
#if USE_GENERATED
        addAnnotation(make_smart<DummyTypeAnnotation>("bgfx_encoder_s", "bgfx_encoder_s",1,1));

        #include "module_bgfx.ann.inc"
        #include "module_bgfx.enum.inc"
        #include "module_bgfx.inc"
#endif
    }
    virtual ModuleAotType aotRequire ( TextWriter & tw ) const override {
        tw << "#include \"../modules/dasBGFX/src/dasBGFX.h\"\n";
        return ModuleAotType::cpp;
    }
};

}

REGISTER_MODULE_IN_NAMESPACE(Module_BGFX,das);

