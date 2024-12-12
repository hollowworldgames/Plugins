// Copyright (c) 2024 Hollow World Games llc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GravityReceiverInterface.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UGravityReceiverInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GALAXY_API IGravityReceiverInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void ApplyGravityForce(FVector GravityForce) = 0;
};
