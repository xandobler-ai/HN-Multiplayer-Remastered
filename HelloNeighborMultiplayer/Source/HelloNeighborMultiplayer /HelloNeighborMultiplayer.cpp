#include "HelloNeighborMultiplayer.h"

#define LOCTEXT_NAMESPACE "FHelloNeighborMultiplayerModule"

void FHelloNeighborMultiplayerModule::StartupModule()
{
}

void FHelloNeighborMultiplayerModule::ShutdownModule()
{
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(
    FHelloNeighborMultiplayerModule,
    HelloNeighborMultiplayer
)
