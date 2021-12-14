#include "daScript/misc/platform.h"

#include "daScript/daScript.h"
#include "daScript/ast/ast_typefactory_bind.h"

#include "need_bgfx.h"

using namespace das;

IMPLEMENT_EXTERNAL_TYPE_FACTORY(bgfx_encoder_s,bgfx_encoder_s);

#define GLOBAL_NAMESPACE
#include "module_bgfx.enum.cpp_inc"
#include "module_bgfx.ann.cpp_inc"

#include <bx/debug.h>


namespace das {

Module_BGFX::Module_BGFX() : Module("bgfx") {
    lib.addModule(this);
    lib.addBuiltInModule();
    addAnnotation(make_smart<DummyTypeAnnotation>("bgfx_encoder_s", "bgfx_encoder_s",1,1));
    #include "module_bgfx.enum.inc"
    #include "module_bgfx.ann.inc"
    #include "module_bgfx.const_inc"
#ifdef _MSC_VER
    addConstant(*this,"BGFX_SHADERC_NAME","shaderc.exe");
#elif defined(__APPLE__)
    addConstant(*this,"BGFX_SHADERC_NAME","shaderc-osx");
#elif defined(__linux__)
    addConstant(*this,"BGFX_SHADERC_NAME","shaderc-ubuntu");
#else
     addConstant(*this,"BGFX_SHADERC_NAME","shaderc.exe");
#endif
    initFunctions();
}

ModuleAotType Module_BGFX::aotRequire ( TextWriter & tw ) const {
    tw << "#include \"../modules/dasBGFX/src/dasBGFX.h\"\n";
    return ModuleAotType::cpp;
}

}

REGISTER_MODULE_IN_NAMESPACE(Module_BGFX,das);

