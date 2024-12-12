// Copyright (c) 2024 Hollow World Games llc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "Interfaces/GravitySourceInterface.h"
#include "PlanetoidGravityComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TERRASUITE_API UPlanetoidGravityComponent : public USphereComponent , public IGravitySourceInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UPlanetoidGravityComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	virtual FVector GetGravityForce(FVector Location) const override;
	virtual double GetDistanceToSurface(FVector Location) const override;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Gravity")
	double GravityForce = 9.8;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Gravity")
	double GravityScale = 1;
};
