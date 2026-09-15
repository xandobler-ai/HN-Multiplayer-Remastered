#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "HNPlayerAdapter.generated.h"

UCLASS()
class HELLONEIGHBORMULTIPLAYER_API UHNPlayerAdapter
    : public UObject
{
    GENERATED_BODY()

public:

    bool AttachToPlayer(AActor* Player);

    AActor* GetPlayer() const;

    void UpdateNetworkState();

private:

    UPROPERTY()
    TObjectPtr<AActor> PlayerActor;
};
