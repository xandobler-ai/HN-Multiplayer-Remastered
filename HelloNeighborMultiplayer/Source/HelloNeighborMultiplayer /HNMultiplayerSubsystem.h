#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "HNMultiplayerSubsystem.generated.h"

UCLASS()
class HELLONEIGHBORMULTIPLAYER_API UHNMultiplayerSubsystem
    : public UGameInstanceSubsystem
{
    GENERATED_BODY()

public:

    UFUNCTION(BlueprintCallable)
    bool HostGame();

    UFUNCTION(BlueprintCallable)
    bool JoinGame(const FString& Address);

    UFUNCTION(BlueprintCallable)
    void LeaveGame();

private:

    bool OpenSession();
};
