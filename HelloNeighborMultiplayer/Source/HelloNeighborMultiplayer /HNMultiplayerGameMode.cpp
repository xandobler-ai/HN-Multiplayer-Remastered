#include "HNMultiplayerGameMode.h"

#include "HNMultiplayerPlayer.h"
#include "GameFramework/PlayerController.h"

AHNMultiplayerGameMode::AHNMultiplayerGameMode()
{
    DefaultPawnClass = nullptr;
}

void AHNMultiplayerGameMode::PostLogin(
    APlayerController* NewPlayer
)
{
    Super::PostLogin(NewPlayer);

    if (!NewPlayer)
    {
        return;
    }

    UE_LOG(
        LogTemp,
        Log,
        TEXT("[HNMP] Player connected: %s"),
        *NewPlayer->GetName()
    );
}
