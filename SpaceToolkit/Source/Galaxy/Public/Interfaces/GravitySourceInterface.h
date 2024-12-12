// Copyright (c) 2024 Hollow World Games llc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GravitySourceInterface.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UGravitySourceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GALAXY_API IGravitySourceInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual FVector GetGravityForce(FVector Location) const = 0;
	virtual double GetDistanceToSurface(FVector Location) const = 0;
};
