// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FuelComponentDataRow.generated.h"

class UFuelDefinitionData;
/**
 * 
 */
USTRUCT(BlueprintType)
struct SPACECRAFT_API FFuelComponentDataRow : public FTableRowBase
{
	GENERATED_BODY()
public :
	UFuelDefinitionData* MakeFuelDefinitionData() const;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(ClampMax="5", ClampMin="1", UIMin = "1", UIMax = "5", Delta = "1"), Category = "Fuel")
	float Level;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Fuel")
	float MaxFuel;
};
