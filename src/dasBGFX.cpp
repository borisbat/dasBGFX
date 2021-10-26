#include "daScript/misc/platform.h"

#include "daScript/daScript.h"
#include "daScript/ast/ast_typefactory_bind.h"

#include "need_bgfx.h"

using namespace das;

#define BGFX_CAST_HANDLE_TYPE(tname) \
    template <> \
    struct cast_arg <tname> { \
        static __forceinline tname to ( Context & ctx, SimNode * x ) { \
            return *((tname *) x->evalPtr(ctx)); \
        } \
    };

#if USE_GENERATED
#include "bgfx_headers.h"
#include "bx/math.h"

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

#if USE_GENERATED

void Das_bgfx_dbg_text_printf(uint16_t _x, uint16_t _y, uint8_t _attr, const char* text ) {
    bgfx_dbg_text_printf(_x, _y, _attr, "%s", text );
}

float4x4 Das_bgfx_projection ( float angleD, float w, float h, float zn, float zf, bool HD, bool lh ) {
    float4x4 proj;
    bx::mtxProj((float *)&proj, angleD, w / h, zn, zf, HD, lh ? bx::Handness::Left : bx::Handness::Right);
    return proj;
}

float4x4 Das_bgfx_ortho ( float l, float r, float b, float t, float zn, float zf, float ofs, bool HD, bool lh ) {
    float4x4 ortho;
    bx::mtxOrtho((float *)&ortho, l, r, b, t, zn, zf, ofs, HD, lh ? bx::Handness::Left : bx::Handness::Right);
    return ortho;
}

#endif

Module_BGFX::Module_BGFX() : Module("bgfx") {
    ModuleLibrary lib;
    lib.addModule(this);
    lib.addBuiltInModule();
#if USE_GENERATED
    addAnnotation(make_smart<DummyTypeAnnotation>("bgfx_encoder_s", "bgfx_encoder_s",1,1));

    #include "module_bgfx.enum.inc"
    #include "module_bgfx.ann.inc"
    #include "module_bgfx.inc"
    #include "module_bgfx.const_inc"

    addExtern<DAS_BIND_FUN(Das_bgfx_dbg_text_printf)>(*this, lib, "bgfx_dbg_text_printf",SideEffects::worstDefault, "Das_bgfx_dbg_text_printf")
        ->args({"_x","_y","_attr","text"});

    addExtern<DAS_BIND_FUN(Das_bgfx_projection), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "bgfx_mat_projection",SideEffects::worstDefault, "Das_bgfx_projection")
        ->args({"angleD","w","h","zn","zf","homogeneousNdc","leftHanded"});

    addExtern<DAS_BIND_FUN(Das_bgfx_ortho), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "bgfx_mat_ortho",SideEffects::worstDefault, "Das_bgfx_ortho")
        ->args({"left","right","top","bottom","znear","zfar","offset","homogeneousNdc","leftHanded"});

    // we are fixing raw 'storage type' arguments
    for ( auto fn : this->functions ) {
        const auto&  pfn = fn.second;
        for ( auto & arg : pfn->arguments ) {
            if ( arg->type->isSimpleType(Type::tUInt8) || arg->type->isSimpleType(Type::tUInt16) ) {
                arg->type->baseType = Type::tUInt;
            }
        }
    }

#endif
}
ModuleAotType Module_BGFX::aotRequire ( TextWriter & tw ) const {
    tw << "#include \"../modules/dasBGFX/src/dasBGFX.h\"\n";
    return ModuleAotType::cpp;
}

}

REGISTER_MODULE_IN_NAMESPACE(Module_BGFX,das);

