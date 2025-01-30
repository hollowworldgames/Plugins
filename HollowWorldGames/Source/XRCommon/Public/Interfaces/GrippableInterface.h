// Copyright (c) 2024 Hollow World Games llc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GrippableInterface.generated.h"

class UXRGripperComponent;
// This class does not need to be modified.
UINTERFACE()
class UGrippableInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class XRCOMMON_API IGrippableInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void Grip(TObjectPtr<UXRGripperComponent> Gripper) = 0;
	virtual void Release() = 0;
};
