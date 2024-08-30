// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "BuyerInterface.generated.h"

class ISellerInterface;
// This class does not need to be modified.
UINTERFACE()
class UBuyerInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class FANTASYECONOMY_API IBuyerInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void SellerAvailable(TScriptInterface<ISellerInterface> Seller) = 0;
	virtual void SellerUnavailable(TScriptInterface<ISellerInterface> Seller) = 0;
};
