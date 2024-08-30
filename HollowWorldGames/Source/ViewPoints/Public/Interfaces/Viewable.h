// (c) Copyright 2023 Hollow World Games All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Viewable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UViewable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class VIEWPOINTS_API IViewable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void ChangeViewPoint() = 0;
	virtual void MakeActiveViewable() = 0;
	virtual void MakeInactive() = 0;
	virtual void ResetToMain() = 0;
	virtual bool IsLocalPlayer() = 0;
};
