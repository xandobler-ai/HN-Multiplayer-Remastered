#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "HNMultiplayerCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class HELLONEIGHBORMULTIPLAYER_API AHNMultiplayerCharacter
    : public ACharacter
{
    GENERATED_BODY()

public:

    AHNMultiplayerCharacter();

protected:

    virtual void SetupPlayerInputComponent(
        UInputComponent* PlayerInputComponent
    ) override;

    void MoveForward(float Value);
    void MoveRight(float Value);

    UPROPERTY(VisibleAnywhere)
    USpringArmComponent* CameraBoom;

    UPROPERTY(VisibleAnywhere)
    UCameraComponent* Camera;
};
