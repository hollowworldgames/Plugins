// Copyright (c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DamageableDefinition.h"
#include "Components/HydraulicSystemComponent.h"
#include "HydraulicReservoirDefinition.generated.h"

/**
 * 
 */
UCLASS()
class FLIGHT_API UHydraulicReservoirDefinition : public UDamageableDefinition
{
	GENERATED_BODY()
public :
	void TickReservoir(float DeltaTime, float Power);
};
