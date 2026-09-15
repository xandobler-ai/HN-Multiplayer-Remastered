#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HNMultiplayerPlayer.generated.h"

UCLASS()
class HELLONEIGHBORMULTIPLAYER_API AHNMultiplayerPlayer
    : public AActor
{
    GENERATED_BODY()

public:

    AHNMultiplayerPlayer();

protected:

    virtual void GetLifetimeReplicatedProps(
        TArray<FLifetimeProperty>& OutLifetimeProps
    ) const override;

public:

    UPROPERTY(Replicated, BlueprintReadOnly)
    FString PlayerName;

    UPROPERTY(Replicated, BlueprintReadOnly)
    int32 PlayerID;

    UFUNCTION(Server, Reliable)
    void ServerSetPlayerName(const FString& NewName);

private:

    void ServerSetPlayerName_Implementation(
        const FString& NewName
    );
};
