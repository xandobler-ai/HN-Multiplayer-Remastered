#include "HNMultiplayerCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "Components/InputComponent.h"

AHNMultiplayerCharacter::AHNMultiplayerCharacter()
{
    bReplicates = true;
    SetReplicateMovement(true);

    GetCharacterMovement()->MaxWalkSpeed = 600.0f;

    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(
        TEXT("CameraBoom")
    );

    CameraBoom->SetupAttachment(
        GetRootComponent()
    );

    CameraBoom->TargetArmLength = 300.0f;
    CameraBoom->bUsePawnControlRotation = true;

    Camera = CreateDefaultSubobject<UCameraComponent>(
        TEXT("Camera")
    );

    Camera->SetupAttachment(
        CameraBoom,
        USpringArmComponent::SocketName
    );

    Camera->bUsePawnControlRotation = false;
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
