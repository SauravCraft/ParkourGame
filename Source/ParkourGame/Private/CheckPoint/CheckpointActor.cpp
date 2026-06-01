#include "CheckPoint/CheckpointActor.h"
#include "Components/BoxComponent.h"
#include "ParkourGameCharacter.h"
#include "ParkourGameGameMode.h"
#include "Kismet/GameplayStatics.h"

ACheckpointActor::ACheckpointActor()
{
    PrimaryActorTick.bCanEverTick = false;

    CollisionBox =
        CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));

    RootComponent = CollisionBox;

    CollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    CollisionBox->SetCollisionResponseToAllChannels(ECR_Overlap);
}

void ACheckpointActor::BeginPlay()
{
    Super::BeginPlay();

    CollisionBox->OnComponentBeginOverlap.AddDynamic(
        this,
        &ACheckpointActor::OnOverlapBegin
    );
}

void ACheckpointActor::OnOverlapBegin(
    UPrimitiveComponent* OverlappedComponent,
    AActor* OtherActor,
    UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex,
    bool bFromSweep,
    const FHitResult& SweepResult
)
{
    AParkourGameCharacter* Player =
        Cast<AParkourGameCharacter>(OtherActor);

    if (Player && !bActivated)
    {
        bActivated = true;

        AParkourGameGameMode* GM =
            Cast<AParkourGameGameMode>(
                UGameplayStatics::GetGameMode(this)
            );

        if (GM)
        {
            GM->SetCheckpoint(GetActorTransform());
        }

        UE_LOG(LogTemp, Warning, TEXT("Checkpoint Activated"));
    }
}