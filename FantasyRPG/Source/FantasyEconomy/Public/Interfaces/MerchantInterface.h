// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MerchantInterface.generated.h"

class IBuyerInterface;

// This class does not need to be modified.
UINTERFACE(BlueprintType, NotBlueprintable)
class UMerchantInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class FANTASYECONOMY_API IMerchantInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable)
	virtual TArray<UObject*> GetBuyableItems() = 0;
	UFUNCTION(BlueprintCallable)
	virtual float GetBuyFromPrice(UObject * Item) = 0;
	UFUNCTION(BlueprintCallable)
	virtual float GetSellToPrice(UObject * Item) = 0;
	virtual void BuyItemFrom(TScriptInterface<IBuyerInterface> Seller, UObject* Item, int Qty) = 0;
	virtual void SellItemTo(TScriptInterface<IBuyerInterface> Seller, UObject* Item, int Qty) = 0;
};
