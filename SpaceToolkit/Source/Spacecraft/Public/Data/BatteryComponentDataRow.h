// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "BatteryComponentDataRow.generated.h"

class UBatteryDefinitionData;
/**
 * 
 */
USTRUCT(BlueprintType)
struct SPACECRAFT_API FBatteryComponentDataRow : public FTableRowBase
{
	GENERATED_BODY()
public :
	UBatteryDefinitionData * MakeBatteryDefinitionData() const;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FString Name;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(ClampMax="5", ClampMin="1", UIMin = "1", UIMax = "5", Delta = "1"))
	float Level = 1;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float Capacity = 0;
};
