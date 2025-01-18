// Copyright (c) 2024 Hollow World Games llc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ShieldedVehicleInterface.generated.h"

class UDamageResistance;
// This class does not need to be modified.
UINTERFACE()
class UShieldedVehicleInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class VEHICLES_API IShieldedVehicleInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual TObjectPtr<UDamageResistance> GetShieldDamageResistance() = 0;
	virtual TObjectPtr<UDamageResistance> GetArmorDamageResistance() = 0;
};
