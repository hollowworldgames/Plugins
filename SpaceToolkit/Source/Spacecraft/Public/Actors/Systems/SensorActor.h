﻿// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SystemActor.h"
#include "SensorActor.generated.h"

class USensorAttributeSet;

UCLASS(BlueprintType)
class USensorDefinitionData : public USystemDefinitionData
{
	GENERATED_BODY()
public :
	
};

UCLASS()
class SPACECRAFT_API ASensorActor : public ASystemActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASensorActor();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void InitializeAttributes(ASpaceCraftActor* SystemOwner, USystemDefinitionData* SystemData) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Attributes")
	TObjectPtr<USensorAttributeSet> SensorAttributes;
};
