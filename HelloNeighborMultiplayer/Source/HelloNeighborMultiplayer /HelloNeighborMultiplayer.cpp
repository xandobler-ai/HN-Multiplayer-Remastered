#include "HelloNeighborMultiplayer.h"
#include "HNPlayerManager.h"

void FHelloNeighborMultiplayerModule::StartupModule()
{
    PlayerManager =
        NewObject<UHNPlayerManager>();

    if (PlayerManager)
    {
        PlayerManager->AddToRoot();
        PlayerManager->Start();
    }

    UE_LOG(
        LogTemp,
        Log,
        TEXT("[HNMP] Multiplayer plugin started")
    );
}

void FHelloNeighborMultiplayerModule::ShutdownModule()
{
    if (PlayerManager)
    {
        PlayerManager->Stop();
        PlayerManager->RemoveFromRoot();
        PlayerManager = nullptr;
    }

    UE_LOG(
        LogTemp,
        Log,
        TEXT("[HNMP] Multiplayer plugin stopped")
    );
}

IMPLEMENT_MODULE(
    FHelloNeighborMultiplayerModule,
    HelloNeighborMultiplayer
)
