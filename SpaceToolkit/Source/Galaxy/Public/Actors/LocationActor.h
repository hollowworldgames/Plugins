// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Data/GalaxyAsset.h"
#include "Data/Orbital.h"
#include "GameFramework/Actor.h"
#include "LocationActor.generated.h"

UCLASS()
class GALAXY_API ALocationActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ALocationActor();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void AddComet();
	void SetLocation(const FSystemId& SystemId);
	UFUNCTION(BlueprintPure, Category = "Location")
	ULocation * GetLocation() const { return Location;}
	void ClearLocation();
protected:
	UFUNCTION(NetMulticast, Reliable)
	void Multicast_SetLocation(const FSystemId& SystemId);
	void AddPlanetoid(UPlanetoid* Cast);
	void AddAsteroid(UAsteroidOrbital* Cast);
	void AddCloud(UCloudOrbital* Cast);
	void AddAsteroidField();
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Data")
	TObjectPtr<class ULocationClasses> LocationClasses;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Data")
	TObjectPtr<class ULocation> Location;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Spawns)
	TMap<FSystemId, TObjectPtr<AActor>> Spawns;
	
};
