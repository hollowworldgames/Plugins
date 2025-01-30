// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InventoryReceiver.generated.h"

class IInventoryStorable;
// This class does not need to be modified.
UINTERFACE()
class UInventoryReceiver : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class INVENTORY_API IInventoryReceiver
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual TArray<TScriptInterface<IInventoryStorable>> GetInventory() = 0;
	virtual void TransferFrom(TScriptInterface<IInventoryStorable> Item, int Slot) = 0;
	virtual void TransferTo(TScriptInterface<IInventoryStorable> Item, int Slot) = 0;
};
