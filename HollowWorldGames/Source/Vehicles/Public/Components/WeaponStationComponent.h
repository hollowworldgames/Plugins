// Copyright (c) 2024 Hollow World Games llc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ChildActorComponent.h"
#include "WeaponStationComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class VEHICLES_API UWeaponStationComponent : public UChildActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UWeaponStationComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	void SetTriggerPressed();
	void SetTriggerReleased();
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
};
