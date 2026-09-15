#pragma once

#include "Modules/ModuleManager.h"

class FHelloNeighborMultiplayerModule
    : public IModuleInterface
{
public:

    virtual void StartupModule() override;

    virtual void ShutdownModule() override;
};
