// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CloudActor.generated.h"

class UCloudOrbital;

UCLASS()
class GALAXY_API ACloudActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACloudActor();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void SetCloud(UCloudOrbital* NewCloud);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category = Cloud)
	UCloudOrbital* Cloud = nullptr;
};
