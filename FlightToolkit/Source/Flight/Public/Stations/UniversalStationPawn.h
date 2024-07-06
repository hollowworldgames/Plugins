﻿// Copyright (c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "StationPawn.h"
#include "UniversalStationPawn.generated.h"

UCLASS()
class FLIGHT_API AUniversalStationPawn : public AStationPawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AUniversalStationPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};