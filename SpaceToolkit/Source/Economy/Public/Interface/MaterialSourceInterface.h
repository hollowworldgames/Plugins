// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Interface.h"
#include "MaterialSourceInterface.generated.h"

USTRUCT(BlueprintType)
struct FMaterialAvailability
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category = "Materials")
	FGameplayTag Material;
	UPROPERTY(BlueprintReadOnly, Category = "Materials")
	double Qty;
};
// This class does not need to be modified.
UINTERFACE()
class UMaterialSourceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ECONOMY_API IMaterialSourceInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual TArray<FMaterialAvailability> GetMaterialAvailability() = 0;
	virtual TArray<FMaterialAvailability> GetMaterialAvailability(FGameplayTag Resource) = 0;
};
