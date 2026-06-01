#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DeathBox.generated.h"

class UBoxComponent;

UCLASS()
class PARKOURGAME_API ADeathBox : public AActor
{
    GENERATED_BODY()

public:
    ADeathBox();

protected:
    virtual void BeginPlay() override;

public:

    UPROPERTY(VisibleAnywhere)
    UBoxComponent* CollisionBox;

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