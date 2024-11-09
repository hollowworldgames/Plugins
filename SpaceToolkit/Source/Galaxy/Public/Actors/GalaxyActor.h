// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Data/GalaxyAsset.h"
#include "GameFramework/Actor.h"
#include "GalaxyActor.generated.h"

UCLASS()
class GALAXY_API AGalaxyActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGalaxyActor();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
