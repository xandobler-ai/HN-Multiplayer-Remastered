#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "HNMultiplayerGameMode.generated.h"

UCLASS()
class HELLONEIGHBORMULTIPLAYER_API AHNMultiplayerGameMode
    : public AGameModeBase
{
    GENERATED_BODY()

public:

    AHNMultiplayerGameMode();

protected:

    virtual void PostLogin(
        APlayerController* NewPlayer
    ) override;
};
