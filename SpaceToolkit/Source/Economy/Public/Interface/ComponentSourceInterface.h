// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Interface.h"
#include "ComponentSourceInterface.generated.h"


USTRUCT(BlueprintType)
struct FComponentAvailability
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category = "Components")
	FGameplayTag Material;
	UPROPERTY(BlueprintReadOnly, Category = "Components")
	int Qty;
};
// This class does not need to be modified.
UINTERFACE()
class UComponentSourceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ECONOMY_API IComponentSourceInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual TArray<FComponentAvailability> GetResourceAvailability() = 0;
	virtual TArray<FComponentAvailability> GetResourceAvailability(FGameplayTag Resource) = 0;
};
