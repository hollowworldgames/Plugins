// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SpaceCraftActor.h"
#include "SpaceCraftSkeletalMeshActor.generated.h"

UCLASS()
class SPACECRAFT_API ASpaceCraftSkeletalMeshActor : public ASpaceCraftActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASpaceCraftSkeletalMeshActor();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Components)
	TObjectPtr<USkeletalMeshComponent> Root;
};
