// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CometActor.generated.h"

UCLASS()
class GALAXY_API ACometActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACometActor();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
};
