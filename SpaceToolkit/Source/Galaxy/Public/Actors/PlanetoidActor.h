// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlanetoidActor.generated.h"

class UPlanetoid;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCreateNotify, UPlanetoid*, Planetoid);

UCLASS()
class GALAXY_API APlanetoidActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APlanetoidActor();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void SetPlanetoid( UPlanetoid* Planetoid);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category=Orbital)
	TObjectPtr<UPlanetoid> Planetoid;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FCreateNotify OnCreate;
};
