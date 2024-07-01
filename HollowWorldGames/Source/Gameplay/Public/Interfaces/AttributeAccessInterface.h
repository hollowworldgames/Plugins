// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "UObject/Interface.h"
#include "AttributeAccessInterface.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAttributeChanged, FGameplayAttributeData, Data, float, Value);

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UAttributeAccessInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GAMEPLAY_API IAttributeAccessInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual FAttributeChanged& GetAttributeChangedNotify() = 0;
};
