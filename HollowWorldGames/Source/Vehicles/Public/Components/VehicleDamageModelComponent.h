// Copyright (c) 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "DamageModelComponent.h"
#include "Components/ActorComponent.h"
#include "VehicleDamageModelComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class VEHICLES_API UVehicleDamageModelComponent : public UDamageModelComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UVehicleDamageModelComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
