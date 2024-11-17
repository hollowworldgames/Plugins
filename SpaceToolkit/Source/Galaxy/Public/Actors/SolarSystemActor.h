// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Data/GalaxyAsset.h"
#include "GameFramework/Actor.h"
#include "SolarSystemActor.generated.h"

class USolarSystem;

UCLASS()
class GALAXY_API ASolarSystemActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASolarSystemActor();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void SetSolarSystem(const FSystemId& SystemId);
	void ClearSystem();
	FSystemId GetSystemId() const;
protected:
	UFUNCTION(NetMulticast, Reliable)
	void Multicast_SetSolarSystem(const FSystemId& SystemId);
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY()
	TObjectPtr<USolarSystem> SolarSystem;
	UPROPERTY()
	TArray<TObjectPtr<class AStarActor>> Stars;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Classes)
	TSubclassOf<AStarActor> StarClass;
};
