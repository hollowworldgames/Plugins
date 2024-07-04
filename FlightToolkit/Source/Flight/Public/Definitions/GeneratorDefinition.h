// Copyright (c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DamageableDefinition.h"
#include "Interfaces/Source.h"
#include "GeneratorDefinition.generated.h"

/**
 * 
 */
UCLASS()
class FLIGHT_API UGeneratorDefinition : public UDamageableDefinition, public ISource
{
	GENERATED_BODY()
public :
	virtual EResource GetProvided() override { return EResource::Power; }
	FGameplayTag GetEngineTag() const { return EngineTag; }
	virtual float Consume(float Amount) override;
	virtual void AddConsumer(TScriptInterface<IConsumer> Consumer) override;
	void Generate(float RPM);
	float GetPowerAvailable() const { return Power; }
protected :
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Status)
	float Power = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	float PowerOutput = 100;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	float NeededRPM = 1000;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	FGameplayTag EngineTag;
};
