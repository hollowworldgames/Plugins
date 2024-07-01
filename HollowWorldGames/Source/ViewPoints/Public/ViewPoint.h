// (c) Copyright 2023 Hollow World Games All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ViewPoint.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UViewPoint : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class  VIEWPOINTS_API IViewPoint
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void MakeActive() = 0;
	virtual void MakeInactive() = 0;
	virtual bool IsActive() = 0;
};
