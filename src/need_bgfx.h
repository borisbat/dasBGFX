#pragma once

#define USE_GENERATED 1

namespace das {

    class Module_BGFX : public Module {
    public:
        Module_BGFX();
        virtual ModuleAotType aotRequire ( TextWriter & tw ) const override;
    };

}

