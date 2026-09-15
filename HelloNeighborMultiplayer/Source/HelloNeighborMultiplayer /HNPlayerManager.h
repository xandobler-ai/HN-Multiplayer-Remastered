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

    void Start();

    void Stop();

    bool FindLocalPlayer(UWorld* World);

    UHNPlayerAdapter* GetLocalPlayerAdapter() const;

private:

    void OnWorldInitialized(
        UWorld* World,
        const UWorld::InitializationValues IVS
    );

    UPROPERTY()
    TObjectPtr<UHNPlayerAdapter> LocalPlayerAdapter;

    FDelegateHandle WorldInitializedHandle;
};
