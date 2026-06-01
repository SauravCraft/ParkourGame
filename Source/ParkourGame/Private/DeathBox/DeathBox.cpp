#include "DeathBox/DeathBox.h"
#include "Components/BoxComponent.h"
#include "ParkourGameCharacter.h"

ADeathBox::ADeathBox()
{
    PrimaryActorTick.bCanEverTick = false;

    CollisionBox =
        CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));

    RootComponent = CollisionBox;

    CollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    CollisionBox->SetCollisionResponseToAllChannels(ECR_Overlap);
}

void ADeathBox::BeginPlay()
{
    Super::BeginPlay();

    CollisionBox->OnComponentBeginOverlap.AddDynamic(
        this,
        &ADeathBox::OnOverlapBegin
    );
}

void ADeathBox::OnOverlapBegin(
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

    if (Player)
    {
        Player->Die();
    }
}