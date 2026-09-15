#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "HNNetworkCharacter.generated.h"

UCLASS()
class HELLONEIGHBORMULTIPLAYER_API AHNNetworkCharacter
    : public ACharacter
{
    GENERATED_BODY()

public:

    AHNNetworkCharacter();

protected:

    virtual void BeginPlay() override;

    virtual void GetLifetimeReplicatedProps(
        TArray<FLifetimeProperty>& OutLifetimeProps
    ) const override;

public:

    UPROPERTY(Replicated, BlueprintReadOnly)
    int32 NetworkPlayerID;

    UPROPERTY(Replicated, BlueprintReadOnly)
    FString NetworkPlayerName;
};
