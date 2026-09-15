#include "TimerManager.h"
#include "HNPlayerManager.h"
#include "HNPlayerAdapter.h"

#include "Engine/World.h"
#include "Engine/Engine.h"
#include "GameFramework/PlayerController.h"

void UHNPlayerManager::Start()
{
    if (WorldInitializedHandle.IsValid())
    {
        return;
    }

    WorldInitializedHandle =
        FWorldDelegates::OnWorldInitializedActors.AddUObject(
            this,
            &UHNPlayerManager::OnWorldInitialized
        );

    UE_LOG(
        LogTemp,
        Log,
        TEXT("[HNMP] Player manager started")
    );
}

void UHNPlayerManager::Stop()
{
    if (WorldInitializedHandle.IsValid())
    {
        FWorldDelegates::OnWorldInitializedActors.Remove(
            WorldInitializedHandle
        );

        WorldInitializedHandle.Reset();
    }

    LocalPlayerAdapter = nullptr;

    UE_LOG(
        LogTemp,
        Log,
        TEXT("[HNMP] Player manager stopped")
    );
}

void UHNPlayerManager::OnWorldInitialized(
    UWorld* World,
    const UWorld::InitializationValues IVS
)
{
    if (!World)
    {
        return;
    }

    if (World->WorldType != EWorldType::Game &&
        World->WorldType != EWorldType::PIE)
    {
        return;
    }

    FindLocalPlayer(World);
}

bool UHNPlayerManager::FindLocalPlayer(UWorld* World)
{
    if (!World)
    {
        return false;
    }

    APlayerController* Controller =
        World->GetFirstPlayerController();

    if (!Controller)
    {
        return false;
    }

    APawn* Pawn = Controller->GetPawn();

    if (!Pawn)
    {
        UE_LOG(
            LogTemp,
            Warning,
            TEXT("[HNMP] No local player pawn yet")
        );

        return false;
    }

    LocalPlayerAdapter =
        NewObject<UHNPlayerAdapter>(this);

    if (!LocalPlayerAdapter)
    {
        return false;
    }

    const bool Attached =
        LocalPlayerAdapter->AttachToPlayer(Pawn);

    if (Attached)
    {
        UE_LOG(
            LogTemp,
            Log,
            TEXT("[HNMP] Successfully attached to local player")
        );
    }

    return Attached;
}

UHNPlayerAdapter*
UHNPlayerManager::GetLocalPlayerAdapter() const
{
    return LocalPlayerAdapter;
}
