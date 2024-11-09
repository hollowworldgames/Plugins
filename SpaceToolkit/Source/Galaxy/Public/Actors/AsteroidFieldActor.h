// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AsteroidFieldActor.generated.h"

class UAsteroidField;

UCLASS()
class GALAXY_API AAsteroidFieldActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAsteroidFieldActor();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void SetAsteroidField(UAsteroidField * NewAsteroidField) { AsteroidField = NewAsteroidField; }
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Orbital)
	TObjectPtr<UAsteroidField> AsteroidField;
};
