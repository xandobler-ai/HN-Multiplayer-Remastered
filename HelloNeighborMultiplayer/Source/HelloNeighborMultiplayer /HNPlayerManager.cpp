#include "HNPlayerManager.h"
#include "HNPlayerAdapter.h"

#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

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
        return false;
    }

    LocalPlayerAdapter =
        NewObject<UHNPlayerAdapter>(this);

    if (!LocalPlayerAdapter)
    {
        return false;
    }

    return LocalPlayerAdapter->AttachToPlayer(Pawn);
}

UHNPlayerAdapter*
UHNPlayerManager::GetLocalPlayerAdapter() const
{
    return LocalPlayerAdapter;
}
