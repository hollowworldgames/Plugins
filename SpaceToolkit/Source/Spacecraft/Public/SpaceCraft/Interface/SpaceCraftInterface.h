// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SpaceCraftInterface.generated.h"

// This class does not need to be modified.
UINTERFACE()
class USpaceCraftInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SPACECRAFT_API ISpaceCraftInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void ToggleGear() = 0;
	virtual void TogglePower() = 0;
};
