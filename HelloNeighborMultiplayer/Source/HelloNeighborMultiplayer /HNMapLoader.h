#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "HNMapLoader.generated.h"

UCLASS()
class HELLONEIGHBORMULTIPLAYER_API UHNMapLoader
    : public UObject
{
    GENERATED_BODY()

public:

    bool LoadMap(UWorld* World, const FString& MapName);

    bool LoadAct1(UWorld* World);
    bool LoadAct1Basement(UWorld* World);
    bool LoadAct1BasementLocation(UWorld* World);
    bool LoadAct1Day(UWorld* World);
    bool LoadPlayerHouse(UWorld* World);
    bool LoadNeighborHouse(UWorld* World);
    bool LoadAct2(UWorld* World);
    bool LoadAct3(UWorld* World);
    bool LoadFinale(UWorld* World);

private:

    bool TravelToMap(
        UWorld* World,
        const FString& MapPath
    );
};
