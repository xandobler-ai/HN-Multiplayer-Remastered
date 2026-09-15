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
   if (CurrentWorld)
{
    CurrentWorld->GetTimerManager().ClearTimer(
        RetryTimerHandle
    );
}

CurrentWorld = nullptr;

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

    CurrentWorld = World;

    FindLocalPlayer(World);

    World->GetTimerManager().SetTimer(
        RetryTimerHandle,
        this,
        &UHNPlayerManager::RetryFindPlayer,
        0.5f,
        true
    );
}

void UHNPlayerManager::RetryFindPlayer()
{
    if (!CurrentWorld)
    {
        return;
    }

    if (LocalPlayerAdapter &&
        LocalPlayerAdapter->GetPlayer())
    {
        return;
    }

    if (FindLocalPlayer(CurrentWorld))
    {
        CurrentWorld->GetTimerManager().ClearTimer(
            RetryTimerHandle
        );

        UE_LOG(
            LogTemp,
            Log,
            TEXT("[HNMP] Player found!")
        );

        return;
    }

    UE_LOG(
        LogTemp,
        Verbose,
        TEXT("[HNMP] Player not spawned yet, retrying...")
    );
}v

UHNPlayerAdapter*
UHNPlayerManager::GetLocalPlayerAdapter() const
{
    return LocalPlayerAdapter;
}
