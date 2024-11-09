// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AsteroidActor.generated.h"

class UAsteroidOrbital;

UCLASS()
class GALAXY_API AAsteroidActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAsteroidActor();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void SetOrbital(UAsteroidOrbital* NewOrbital) { Orbital = NewOrbital; }
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(Transient, VisibleAnywhere, BlueprintReadOnly, Category=Orbital)
	TObjectPtr<UAsteroidOrbital> Orbital;
};
