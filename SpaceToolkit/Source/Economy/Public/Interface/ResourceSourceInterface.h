// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Interface.h"
#include "ResourceSourceInterface.generated.h"

USTRUCT(BlueprintType)
struct FResourceAvailability
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category = "Resource")
	FGameplayTag Resource;
	UPROPERTY(BlueprintReadOnly, Category = "Resource")
	double Qty;
};

// This class does not need to be modified.
UINTERFACE()
class UResourceSourceInterface : public UInterface
{
	GENERATED_BODY()
};



class ECONOMY_API IResourceSourceInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual TArray<FResourceAvailability> GetResourceAvailability() = 0;
	virtual TArray<FResourceAvailability> GetResourceAvailability(FGameplayTag Resource) = 0;
};
