// Copyright (c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EngineDefinition.h"
#include "JetEngineDefinition.generated.h"

/**
 * 
 */
UCLASS()
class FLIGHT_API UJetEngineDefinition : public UEngineDefinition
{
	GENERATED_BODY()
public :
	virtual void TickEngine(float DeltaTime, float AirPressure, float AirSpeed) override;
	virtual void TickEngine(float DeltaTime, float AirPressure, TObjectPtr<USkeletalMeshComponent> Root) override;
protected :
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	FScalableFloat Compression;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	FScalableFloat ThrustFromRPM;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	FScalableFloat TemperatureFromRPM;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	float StartRPM = 500;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	float IdleRPM = 1000;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	float MaxRPM = 3000;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	float RPMGain = 1000;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	float MaxFuel = 5;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	float MaxPressure = 5;
};
