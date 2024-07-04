// Copyright (c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "JetEngineDefinition.h"
#include "AfterburningJetEngineDefinition.generated.h"

/**
 * 
 */
UCLASS()
class FLIGHT_API UAfterburningJetEngineDefinition : public UJetEngineDefinition
{
	GENERATED_BODY()
public :
	virtual void TickEngine(float DeltaTime, float Airpressure, float Airspeed) override;
	virtual float GetNeeded() override;
	virtual float Provided(float Amount) override;
protected :
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	FScalableFloat BurnerNeed;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	FScalableFloat BurnerThrust;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Status)
	float BurnerFuel;
};
