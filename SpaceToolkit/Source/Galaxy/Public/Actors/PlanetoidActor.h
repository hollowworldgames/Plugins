﻿// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlanetoidActor.generated.h"

UCLASS()
class GALAXY_API APlanetoidActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APlanetoidActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
