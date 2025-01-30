// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DataComponentInterface.generated.h"

class UDataAccessComponent;
// This class does not need to be modified.
UINTERFACE()
class DATAACCESS_API UDataComponentInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class DATAACCESS_API IDataComponentInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual UDataAccessComponent * GetDataAccessComponent() const = 0;
	virtual void Load(int64 ActorId) = 0;
};
