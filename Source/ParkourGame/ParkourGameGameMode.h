#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ParkourGameGameMode.generated.h"

UCLASS()
class PARKOURGAME_API AParkourGameGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:

    UPROPERTY(BlueprintReadWrite)
    FTransform CurrentCheckpoint;

    UFUNCTION(BlueprintCallable)
    void SetCheckpoint(FTransform NewCheckpoint);

    UFUNCTION(BlueprintCallable)
    void RespawnPlayer(AController* PlayerController);

protected:
    virtual void BeginPlay() override;
};