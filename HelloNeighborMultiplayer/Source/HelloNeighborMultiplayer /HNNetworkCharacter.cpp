#include "HNNetworkCharacter.h"

#include "Net/UnrealNetwork.h"

AHNNetworkCharacter::AHNNetworkCharacter()
{
    bReplicates = true;

    SetReplicateMovement(true);

    NetworkPlayerID = -1;
    NetworkPlayerName = TEXT("Player");
}

void AHNNetworkCharacter::BeginPlay()
{
    Super::BeginPlay();

    UE_LOG(
        LogTemp,
        Log,
        TEXT(
            "[HNMP] Network character spawned: %s"
        ),
        *GetName()
    );
}

void AHNNetworkCharacter::GetLifetimeReplicatedProps(
    TArray<FLifetimeProperty>& OutLifetimeProps
) const
{
    Super::GetLifetimeReplicatedProps(
        OutLifetimeProps
    );

    DOREPLIFETIME(
        AHNNetworkCharacter,
        NetworkPlayerID
    );

    DOREPLIFETIME(
        AHNNetworkCharacter,
        NetworkPlayerName
    );
}
