#pragma once

#include "Modules/ModuleManager.h"

class FHelloNeighborMultiplayerModule
    : public IModuleInterface
{
class FHelloNeighborMultiplayerModule
    : public IModuleInterface
{
public:

    virtual void StartupModule() override;

    virtual void ShutdownModule() override;

private:

    UHNPlayerManager* PlayerManager;
};
