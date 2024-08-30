// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SellerInterface.generated.h"

class IBuyerInterface;

// This class does not need to be modified.
UINTERFACE(BlueprintType, NotBlueprintable)
class USellerInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class FANTASYECONOMY_API ISellerInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual TArray<UObject*> GetBuyableItems() = 0;
	virtual void BuyItemFrom(TScriptInterface<IBuyerInterface> Seller, UObject* Item, int Qty) = 0;
	virtual void SellItemTo(TScriptInterface<IBuyerInterface> Seller, UObject* Item, int Qty) = 0;
};
