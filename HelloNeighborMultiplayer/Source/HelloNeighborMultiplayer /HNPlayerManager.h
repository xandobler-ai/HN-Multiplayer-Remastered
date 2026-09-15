#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "HNPlayerManager.generated.h"

class UHNPlayerAdapter;

UCLASS()
class HELLONEIGHBORMULTIPLAYER_API UHNPlayerManager
    : public UObject
{
    GENERATED_BODY()

public:

    bool FindLocalPlayer(UWorld* World);

    UHNPlayerAdapter* GetLocalPlayerAdapter() const;

private:

    UPROPERTY()
    TObjectPtr<UHNPlayerAdapter> LocalPlayerAdapter;
};
