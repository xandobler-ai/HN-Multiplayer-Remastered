#include "HNMultiplayerPlayer.h"

#include "Net/UnrealNetwork.h"

AHNMultiplayerPlayer::AHNMultiplayerPlayer()
{
    bReplicates = true;

    PlayerID = -1;
    PlayerName = TEXT("Player");
}

void AHNMultiplayerPlayer::GetLifetimeReplicatedProps(
    TArray<FLifetimeProperty>& OutLifetimeProps
) const
{
    Super::GetLifetimeReplicatedProps(
        OutLifetimeProps
    );

    DOREPLIFETIME(
        AHNMultiplayerPlayer,
        PlayerName
    );

    DOREPLIFETIME(
        AHNMultiplayerPlayer,
        PlayerID
    );
}

void AHNMultiplayerPlayer::ServerSetPlayerName_Implementation(
    const FString& NewName
)
{
    PlayerName = NewName;
}
