#include "HNMultiplayerCharacter.h"

#include "GameFramework/Controller.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/InputComponent.h"

AHNMultiplayerCharacter::AHNMultiplayerCharacter()
{
    bReplicates = true;

    SetReplicateMovement(true);

    GetCharacterMovement()->MaxWalkSpeed = 600.0f;
}

void AHNMultiplayerCharacter::SetupPlayerInputComponent(
    UInputComponent* PlayerInputComponent
)
{
    Super::SetupPlayerInputComponent(
        PlayerInputComponent
    );

    PlayerInputComponent->BindAxis(
        TEXT("MoveForward"),
        this,
        &AHNMultiplayerCharacter::MoveForward
    );

    PlayerInputComponent->BindAxis(
        TEXT("MoveRight"),
        this,
        &AHNMultiplayerCharacter::MoveRight
    );
}

void AHNMultiplayerCharacter::MoveForward(float Value)
{
    if (Controller && Value != 0.0f)
    {
        const FRotator Rotation =
            Controller->GetControlRotation();

        const FRotator YawRotation(
            0.0f,
            Rotation.Yaw,
            0.0f
        );

        const FVector Direction =
            FRotationMatrix(YawRotation)
            .GetUnitAxis(EAxis::X);

        AddMovementInput(Direction, Value);
    }
}

void AHNMultiplayerCharacter::MoveRight(float Value)
{
    if (Controller && Value != 0.0f)
    {
        const FRotator Rotation =
            Controller->GetControlRotation();

        const FRotator YawRotation(
            0.0f,
            Rotation.Yaw,
            0.0f
        );

        const FVector Direction =
            FRotationMatrix(YawRotation)
            .GetUnitAxis(EAxis::Y);

        AddMovementInput(Direction, Value);
    }
}
