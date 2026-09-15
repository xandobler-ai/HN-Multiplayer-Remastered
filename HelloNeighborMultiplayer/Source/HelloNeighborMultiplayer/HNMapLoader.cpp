#include "HNMapLoader.h"

#include "Engine/World.h"

bool UHNMapLoader::TravelToMap(
    UWorld* World,
    const FString& MapPath)
{
    if (!World || MapPath.IsEmpty())
    {
        return false;
    }

    UE_LOG(
        LogTemp,
        Log,
        TEXT("[HNMP] Loading map: %s"),
        *MapPath
    );

    World->ServerTravel(MapPath);

    return true;
}

bool UHNMapLoader::LoadMap(
    UWorld* World,
    const FString& MapName)
{
    if (!World)
    {
        return false;
    }

    const FString MapPath =
        TEXT("/Game/Maps/") + MapName;

    return TravelToMap(World, MapPath);
}

bool UHNMapLoader::LoadAct1(UWorld* World)
{
    return TravelToMap(
        World,
        TEXT("/Game/Maps/Act1/Act1_Main")
    );
}
bool UHNMapLoader::LoadAct1Basement(UWorld* World)
{
    return TravelToMap(
        World,
        TEXT("/Game/Maps/Act1_Basement/Act1_Basement_Main")
    );
}

bool UHNMapLoader::LoadAct1BasementLocation(UWorld* World)
{
    return TravelToMap(
        World,
        TEXT("/Game/Maps/Act1_Basement/Act1_Basement_Location")
    );
}

bool UHNMapLoader::LoadAct1Day(UWorld* World)
{
    return TravelToMap(
        World,
        TEXT("/Game/Maps/Act1/Act1_Day")
    );
}

bool UHNMapLoader::LoadPlayerHouse(UWorld* World)
{
    return TravelToMap(
        World,
        TEXT("/Game/Maps/Act1/PlayerHouse")
    );
}

bool UHNMapLoader::LoadNeighborHouse(UWorld* World)
{
    return TravelToMap(
        World,
        TEXT("/Game/Maps/Act1/NeighborHouseContent")
    );
}

bool UHNMapLoader::LoadAct2(UWorld* World)
{
    return TravelToMap(
        World,
        TEXT("/Game/Maps/Act2/Act2_Main")
    );
}

bool UHNMapLoader::LoadAct3(UWorld* World)
{
    return TravelToMap(
        World,
        TEXT("/Game/Maps/Act3/Act3_Main")
    );
}

bool UHNMapLoader::LoadFinale(UWorld* World)
{
    return TravelToMap(
        World,
        TEXT("/Game/Maps/Finale")
    );
}
