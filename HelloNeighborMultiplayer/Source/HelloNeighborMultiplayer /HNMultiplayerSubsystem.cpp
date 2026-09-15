#include "HNMultiplayerSubsystem.h"

#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

bool UHNMultiplayerSubsystem::HostGame(
    const FString& MapPath)
{
    UWorld* World = GetWorld();

    if (!World || MapPath.IsEmpty())
    {
        return false;
    }

    const FString ListenMap =
        MapPath + TEXT("?listen");

    World->ServerTravel(ListenMap);

    bHosting = true;
    bConnected = true;

    UE_LOG(
        LogTemp,
        Log,
        TEXT("[HNMP] Hosting on %s"),
        *ListenMap
    );

    return true;
}

bool UHNMultiplayerSubsystem::JoinGame(
    const FString& Address)
{
    UWorld* World = GetWorld();

    if (!World || Address.IsEmpty())
    {
        return false;
    }

    APlayerController* Controller =
        World->GetFirstPlayerController();

    if (!Controller)
    {
        return false;
    }

    Controller->ClientTravel(
        Address,
        TRAVEL_Absolute
    );

    bHosting = false;
    bConnected = true;

    UE_LOG(
        LogTemp,
        Log,
        TEXT("[HNMP] Joining %s"),
        *Address
    );

    return true;
}

void UHNMultiplayerSubsystem::LeaveGame()
{
    UWorld* World = GetWorld();

    if (!World)
    {
        return;
    }

    APlayerController* Controller =
        World->GetFirstPlayerController();

    if (Controller)
    {
        Controller->ClientTravel(
            TEXT("/Game/Maps/MainMenu"),
            TRAVEL_Absolute
        );
    }

    bHosting = false;
    bConnected = false;

    UE_LOG(
        LogTemp,
        Log,
        TEXT("[HNMP] Left multiplayer session")
    );
}

bool UHNMultiplayerSubsystem::IsHosting() const
{
    return bHosting;
}

bool UHNMultiplayerSubsystem::IsConnected() const
{
    return bConnected;
}
