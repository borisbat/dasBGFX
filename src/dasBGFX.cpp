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

#include <bx/debug.h>

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

// bgfx callbacks

namespace callbacks {
    void fatal(bgfx_callback_interface_t* ,const char* _filePath, uint16_t _line, bgfx_fatal_t _code, const char* _str)
    {
        printf("%s (%d): ", _filePath, _line);
        printf("Fatal error: 0x%08x: %s", _code, _str);
        abort();
    }
    void traceVargs(bgfx_callback_interface_t* ,const char* _filePath, uint16_t _line, const char* _format, va_list _argList)
    {
        printf("%s (%d): ", _filePath, _line);
        vprintf(_format, _argList);
    }
}

void Das_bgfx_init_debug ( bgfx_init_s & init ) {
    static bgfx_callback_interface_s interface;
    static bgfx_callback_vtbl_s vtbl;
    interface.vtbl = &vtbl;
    init.callback = &interface;
    vtbl.fatal = callbacks::fatal;
    vtbl.trace_vargs = callbacks::traceVargs;
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
    addExtern<DAS_BIND_FUN(Das_bgfx_init_debug)>(*this, lib, "bgfx_init_debug",SideEffects::worstDefault, "Das_bgfx_init_debug")
        ->arg("init");
    // set_vertex_buffer(...,...,0u,0xffffffff)
    auto svb = this->findUniqueFunction("bgfx_set_vertex_buffer");
    svb->arguments[2]->init = make_smart<ExprConstUInt>(0);
    svb->arguments[3]->init = make_smart<ExprConstUInt>(0xffffffff);
    // set_idnex_buffer(...,0u,0xffffffff)
    auto sib = this->findUniqueFunction("bgfx_set_index_buffer");
    sib->arguments[1]->init = make_smart<ExprConstUInt>(0);
    sib->arguments[2]->init = make_smart<ExprConstUInt>(0xffffffff);
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

