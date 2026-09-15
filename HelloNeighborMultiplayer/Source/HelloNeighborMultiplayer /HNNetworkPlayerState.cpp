#include "HNNetworkPlayerState.h"

#include "Net/UnrealNetwork.h"

AHNNetworkPlayerState::AHNNetworkPlayerState()
{
    NetworkPlayerID = -1;
    NetworkLocation = FVector::ZeroVector;
    NetworkRotation = FRotator::ZeroRotator;
}

void AHNNetworkPlayerState::GetLifetimeReplicatedProps(
    TArray<FLifetimeProperty>& OutLifetimeProps
) const
{
    Super::GetLifetimeReplicatedProps(
        OutLifetimeProps
    );

    DOREPLIFETIME(
        AHNNetworkPlayerState,
        NetworkPlayerID
    );

    DOREPLIFETIME(
        AHNNetworkPlayerState,
        NetworkLocation
    );

    DOREPLIFETIME(
        AHNNetworkPlayerState,
        NetworkRotation
    );
}
