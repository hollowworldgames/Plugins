// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Data/Star.h"
#include "GameFramework/Actor.h"
#include "StarActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FChangeStar, UStar *, Star);

UCLASS(Blueprintable, BlueprintType)
class GALAXY_API AStarActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AStarActor();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void SetStar(UStar* NewStar);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Star")
	UStar* Star;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category = "Events")
	FChangeStar OnChangeStar;
};
