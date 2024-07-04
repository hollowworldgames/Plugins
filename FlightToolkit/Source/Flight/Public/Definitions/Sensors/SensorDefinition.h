// Copyright (c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DamageableDefinition.h"
#include "Interfaces/Consumer.h"
#include "Interfaces/Source.h"
#include "SensorDefinition.generated.h"

/**
 * 
 */
UCLASS()
class FLIGHT_API USensorDefinition : public UDamageableDefinition , public IConsumer
{
	GENERATED_BODY()
public :
	void SensorTick(float DeltaTime, AActor * Owner);
	virtual EResource GetNeededResource() override { return EResource::Power; }
	virtual float GetNeeded() override;
	virtual float Provided(float Amount) override;
	virtual FGameplayTag GetComponentTag() override { return GetComponentId(); };
};
