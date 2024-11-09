// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "GalaxyGameMode.generated.h"

class ASolarSystemActor;
class ALocationActor;
/**
 * 
 */
UCLASS()
class GALAXY_API AGalaxyGameMode : public AGameMode
{
	GENERATED_BODY()
public :
protected :
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Galaxy Classes")
	TSubclassOf<ALocationActor> LocationActorClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Galaxy Classes")
	TSubclassOf<ASolarSystemActor> SolarSystemActorClass;
	UPROPERTY()
	TObjectPtr<ALocationActor> LocationActor;
	UPROPERTY()
	TObjectPtr<ASolarSystemActor> SolarSystemActor;
};
