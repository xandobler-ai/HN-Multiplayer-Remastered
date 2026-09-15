#include "HNPlayerAdapter.h"

bool UHNPlayerAdapter::AttachToPlayer(AActor* Player)
{
    if (!IsValid(Player))
    {
        return false;
    }

    PlayerActor = Player;

    UE_LOG(
        LogTemp,
        Log,
        TEXT("[HNMP] Attached to player: %s"),
        *Player->GetName()
    );

    return true;
}

AActor* UHNPlayerAdapter::GetPlayer() const
{
    return PlayerActor;
}

void UHNPlayerAdapter::UpdateNetworkState()
{
    if (!IsValid(PlayerActor))
    {
        return;
    }

    const FVector Location =
        PlayerActor->GetActorLocation();

    const FRotator Rotation =
        PlayerActor->GetActorRotation();

    UE_LOG(
        LogTemp,
        VeryVerbose,
        TEXT(
            "[HNMP] Player position: %s | Rotation: %s"
        ),
        *Location.ToString(),
        *Rotation.ToString()
    );
}
