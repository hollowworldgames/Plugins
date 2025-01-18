// Copyright (c) 2024 Hollow World Games llc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VehicleMovementSystemComponent.h"
#include "SpaceCraftMovementComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class VEHICLES_API USpaceCraftMovementComponent : public UVehicleMovementSystemComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	USpaceCraftMovementComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
};
