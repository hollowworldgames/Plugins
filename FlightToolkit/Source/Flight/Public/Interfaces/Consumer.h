// Copyright (c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameplayTags.h"
#include "Consumer.generated.h"


enum class EResource : uint8;
// This class does not need to be modified.
UINTERFACE()
class UConsumer : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class FLIGHT_API IConsumer
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual EResource GetNeededResource() = 0;
	virtual float GetNeeded() = 0;
	virtual float Provided(float Amount) = 0;
	virtual FGameplayTag GetComponentTag() = 0;
	virtual bool IsOn() const { return On; }
	virtual void SetOn(bool NewOn);
protected :
	bool On = false;
};
