// Copyright (c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DamageableDefinition.h"
#include "Interfaces/Source.h"
#include "BatteryDefinition.generated.h"

/**
 * 
 */
UCLASS()
class FLIGHT_API UBatteryDefinition : public UDamageableDefinition, public ISource
{
	GENERATED_BODY()
public :
	virtual EResource GetProvided() override { return EResource::Power; }
	virtual float Consume(float Amount) override;
	virtual void AddConsumer(TScriptInterface<IConsumer> Consumer) override;
	void AddPower(float Amount);
	float GetAvailable() const { return Power; }
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	float MaxPower = 100;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Status)
	float Power = 100;
};


