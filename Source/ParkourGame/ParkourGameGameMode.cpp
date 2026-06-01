#include "ParkourGameGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerStart.h"
#include "GameFramework/Pawn.h"

void AParkourGameGameMode::BeginPlay()
{
    Super::BeginPlay();

    AActor* Start =
        UGameplayStatics::GetActorOfClass(
            this,
            APlayerStart::StaticClass()
        );

    if (Start)
    {
        CurrentCheckpoint = Start->GetActorTransform();
    }
}

void AParkourGameGameMode::SetCheckpoint(FTransform NewCheckpoint)
{
    CurrentCheckpoint = NewCheckpoint;

    UE_LOG(LogTemp, Warning, TEXT("Checkpoint Saved"));
}

void AParkourGameGameMode::RespawnPlayer(AController* PlayerController)
{
    if (!PlayerController)
        return;

    APawn* OldPawn = PlayerController->GetPawn();

    FVector SpawnLocation = CurrentCheckpoint.GetLocation();
    FRotator SpawnRotation = CurrentCheckpoint.GetRotation().Rotator();

    if (OldPawn)
    {
        OldPawn->Destroy();
    }

    FActorSpawnParameters SpawnParams;
    SpawnParams.Owner = PlayerController;

    APawn* NewPawn = GetWorld()->SpawnActor<APawn>(
        DefaultPawnClass,
        SpawnLocation,
        SpawnRotation,
        SpawnParams
    );

    if (NewPawn)
    {
        PlayerController->Possess(NewPawn);

        UE_LOG(LogTemp, Warning, TEXT("Player Respawned"));
    }
}