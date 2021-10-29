#include "daScript/misc/platform.h"

#include "daScript/daScript.h"
#include "daScript/ast/ast_typefactory_bind.h"

#include "imgui/imgui_bgfx.h"

using namespace das;

namespace das {

void bgfx_imgui_create ( float fontSize ) {
    imguiCreate(fontSize);
}

void bgfx_imgui_destroy () {
    imguiDestroy();
}

void bgfx_imgui_begin_frame(int32_t viewId) {
    imguiBeginFrame(viewId);
}

void bgfx_imgui_end_frame() {
    imguiEndFrame();
}

class Module_BGFXImgui : public Module {
public:
    Module_BGFXImgui();
    virtual ModuleAotType aotRequire ( TextWriter & tw ) const override;
    virtual bool initDependencies() override;
protected:
    bool initialized = false;
    ModuleLibrary lib;
};

Module_BGFXImgui::Module_BGFXImgui() : Module("bgfx_imgui") {
}

bool Module_BGFXImgui::initDependencies() {
    if ( initialized ) return true;
    auto mod_imgui = Module::require("imgui");
    if ( !mod_imgui ) return false;
    if ( !mod_imgui->initDependencies() ) return false;
    initialized = true;
    lib.addModule(this);
    lib.addBuiltInModule();
    lib.addModule(mod_imgui);
    addExtern<DAS_BIND_FUN(bgfx_imgui_create)>(*this, lib, "bgfx_imgui_create",SideEffects::worstDefault, "bgfx_imgui_create")
        ->arg("fontSize");
    addExtern<DAS_BIND_FUN(bgfx_imgui_destroy)>(*this, lib, "bgfx_imgui_destroy",SideEffects::worstDefault, "bgfx_imgui_destroy");
    addExtern<DAS_BIND_FUN(bgfx_imgui_begin_frame)>(*this, lib, "bgfx_imgui_begin_frame",SideEffects::worstDefault, "bgfx_imgui_begin_frame")
        ->arg("viewId");
    addExtern<DAS_BIND_FUN(bgfx_imgui_end_frame)>(*this, lib, "bgfx_imgui_end_frame",SideEffects::worstDefault, "bgfx_imgui_end_frame");
    return true;
}

ModuleAotType Module_BGFXImgui::aotRequire ( TextWriter & tw ) const {
    // tw << "#include \"../modules/dasBGFX/src/dasBGFX.h\"\n";
    return ModuleAotType::cpp;
}

}

REGISTER_MODULE_IN_NAMESPACE(Module_BGFXImgui,das);

