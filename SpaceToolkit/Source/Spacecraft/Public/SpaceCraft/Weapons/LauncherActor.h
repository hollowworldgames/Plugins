// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeaponActor.h"
#include "LauncherActor.generated.h"

UCLASS()
class SPACECRAFT_API ALauncherActor : public AWeaponActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ALauncherActor();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void OnStopFire() override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
