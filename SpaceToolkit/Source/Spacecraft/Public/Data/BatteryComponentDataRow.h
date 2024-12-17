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
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Battery")
	FString Name;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(ClampMax="5", ClampMin="1", UIMin = "1", UIMax = "5", Delta = "1"), Category = "Battery")
	float Level = 1;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Battery")
	float Capacity = 0;
};
