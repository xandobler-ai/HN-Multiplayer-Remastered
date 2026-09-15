#include "HNMultiplayerGameMode.h"
#include "HNNetworkCharacter.h"

#include "HNMultiplayerCharacter.h"
#include "HNMultiplayerPlayer.h"
#include "GameFramework/PlayerController.h"

AHNMultiplayerGameMode::AHNMultiplayerGameMode()
{
    DefaultPawnClass =
        AHNNetworkCharacter::StaticClass();
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
        TEXT(
            "[HNMP] Player connected: %s"
        ),
        *NewPlayer->GetName()
    );

    APawn* Pawn = NewPlayer->GetPawn();

    if (!Pawn)
    {
        return;
    }

    AHNNetworkCharacter* Character =
        Cast<AHNNetworkCharacter>(Pawn);

    if (!Character)
    {
        return;
    }

    Character->NetworkPlayerID =
        GetNumPlayers();

    Character->NetworkPlayerName =
        NewPlayer->PlayerState
            ? NewPlayer->PlayerState->GetPlayerName()
            : TEXT("Player");
}
