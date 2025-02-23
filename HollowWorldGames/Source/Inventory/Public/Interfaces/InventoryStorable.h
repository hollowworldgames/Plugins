// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameplayTags.h"
#include "UObject/Interface.h"
#include "InventoryStorable.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UInventoryStorable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class INVENTORY_API IInventoryStorable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual FGameplayTag GetItemType() = 0;
	virtual FGameplayTag GetItemId() = 0;
	virtual int GetQty() = 0;
};
