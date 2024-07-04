// Copyright (c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Damage/Public/DamageableDefinition.h"
#include "Interfaces/Consumer.h"
#include "Interfaces/Source.h"
#include "FuelTankDefinition.generated.h"

/**
 * 
 */
UCLASS()
class FLIGHT_API UFuelTankDefinition : public UDamageableDefinition, public IConsumer, public ISource
{
	GENERATED_BODY()
public :
	float GetMaxFuel() const { return MaxFuel; }
	float GetFuel() const { return Fuel; }
	float GetPercent() const;
	FGameplayTag GetSource() const { return Source; }
	FGameplayTag GetTarget() const { return Target; }
	virtual EResource GetProvided() override;
	virtual float Consume(float Amount) override;
	virtual void AddConsumer(TScriptInterface<IConsumer> Consumer) override;
	virtual EResource GetNeededResource() override;
	virtual float GetNeeded() override;
	virtual float Provided(float Amount) override;
	virtual FGameplayTag GetComponentTag() override;
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	float MaxFuel = 100;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Settings)
	float Fuel = 100;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	FGameplayTag Source;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	FGameplayTag Target;
};
