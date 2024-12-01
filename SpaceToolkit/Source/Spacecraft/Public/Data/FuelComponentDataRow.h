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
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float Level;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float MaxFuel;
};
