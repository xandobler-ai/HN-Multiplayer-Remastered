#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "HNNetworkPlayerState.generated.h"

UCLASS()
class HELLONEIGHBORMULTIPLAYER_API AHNNetworkPlayerState
    : public APlayerState
{
    GENERATED_BODY()

public:

    AHNNetworkPlayerState();

    UPROPERTY(Replicated, BlueprintReadOnly)
    int32 NetworkPlayerID;

    UPROPERTY(Replicated, BlueprintReadOnly)
    FVector NetworkLocation;

    UPROPERTY(Replicated, BlueprintReadOnly)
    FRotator NetworkRotation;

protected:

    virtual void GetLifetimeReplicatedProps(
        TArray<FLifetimeProperty>& OutLifetimeProps
    ) const override;
};
