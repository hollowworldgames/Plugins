// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeMacros.h"
#include "GameplayEffectExecutionCalculation.h"
#include "ThrustExecutionCalculation.generated.h"

/**
 * 
 */
UCLASS()
class SPACEGAMEPLAY_API UThrustExecutionCalculation : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()
public :
	UThrustExecutionCalculation();
	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;
protected :
	DECLARE_ATTRIBUTE_CAPTUREDEF2(Health);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(MaxHealth);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(EnginePower);
	DECLARE_ATTRIBUTE_CAPTUREDEF2(PowerToThrust);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Curves)
	FScalableFloat Efficiency;
};
