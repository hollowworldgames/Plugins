// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeaponActor.h"
#include "Components/ChildActorComponent.h"
#include "WeaponActorComponent.generated.h"


class AWeaponActor;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SPACECRAFT_API UWeaponActorComponent : public UChildActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UWeaponActorComponent();
	void SetTriggerPressed() const;
	void SetTriggerReleased() const;
	AWeaponActor * GetWeaponActor() const { return Cast<AWeaponActor>(GetChildActor()); }
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
};
