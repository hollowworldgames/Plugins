// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "GalaxyGameMode.generated.h"

struct FSystemId;
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
	virtual void SetCurrentLocation(const FSystemId& SystemId);
	virtual void AddTraffic(AActor * Actor);
	virtual void RemoveTraffic(AActor * Actor);
	virtual TArray<AActor*> GetTraffic() const;
protected :
	virtual void DespawnTraffic();
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Galaxy Classes")
	TSubclassOf<class AGalaxyActor> GalaxyActorClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Galaxy Classes")
	TSubclassOf<class ALocationActor> LocationActorClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Galaxy Classes")
	TSubclassOf<class ASolarSystemActor> SolarSystemActorClass;
	UPROPERTY()
	TObjectPtr<ALocationActor> LocationActor;
	UPROPERTY()
	TObjectPtr<ASolarSystemActor> SolarSystemActor;
	UPROPERTY()
	TObjectPtr<AGalaxyActor> GalaxyActor;
	UPROPERTY()
	TArray<AActor*> Traffic;
};
