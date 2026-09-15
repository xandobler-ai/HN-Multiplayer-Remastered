#include "HNMultiplayerSubsystem.h"

#include "Engine/Engine.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

bool UHNMultiplayerSubsystem::HostGame()
{
    UWorld* World = GetWorld();

    if (!World)
    {
        return false;
    }

    return World->ServerTravel(
        TEXT("/Game/Maps/MainMenu?listen")
    );
}

bool UHNMultiplayerSubsystem::JoinGame(
    const FString& Address)
{
    UWorld* World = GetWorld();

    if (!World)
    {
        return false;
    }

    APlayerController* PlayerController =
        UGameplayStatics::GetPlayerController(
            World,
            0
        );

    if (!PlayerController)
    {
        return false;
    }

    PlayerController->ClientTravel(
        Address,
        TRAVEL_Absolute
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

    APlayerController* PlayerController =
        UGameplayStatics::GetPlayerController(
            World,
            0
        );

    if (PlayerController)
    {
        PlayerController->ClientTravel(
            TEXT("/Game/Maps/MainMenu"),
            TRAVEL_Absolute
        );
    }
}

bool UHNMultiplayerSubsystem::OpenSession()
{
    return true;
}
