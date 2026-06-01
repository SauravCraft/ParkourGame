#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CheckpointActor.generated.h"

class UBoxComponent;

UCLASS()
class PARKOURGAME_API ACheckpointActor : public AActor
{
    GENERATED_BODY()

public:
    ACheckpointActor();

protected:
    virtual void BeginPlay() override;

public:

    UPROPERTY(VisibleAnywhere)
    UBoxComponent* CollisionBox;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bActivated = false;

    UFUNCTION()
    void OnOverlapBegin(
        UPrimitiveComponent* OverlappedComponent,
        AActor* OtherActor,
        UPrimitiveComponent* OtherComp,
        int32 OtherBodyIndex,
        bool bFromSweep,
        const FHitResult& SweepResult
    );
};