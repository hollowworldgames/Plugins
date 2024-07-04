// Copyright (c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Source.generated.h"

class IConsumer;

UENUM(BlueprintType)
enum class EResource : uint8
{
	Fuel,
	Power,
	Hydraulic,
};

// This class does not need to be modified.
UINTERFACE()
class USource : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class FLIGHT_API ISource
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual EResource GetProvided() = 0;
	virtual float Consume(float Amount) = 0;
	virtual void AddConsumer(TScriptInterface<IConsumer> Consumer) = 0;
};
