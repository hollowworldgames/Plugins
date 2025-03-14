﻿// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SensorComponentDataRow.generated.h"

class USensorDefinitionData;
/**
 * 
 */
USTRUCT(BlueprintType)
struct SPACECRAFT_API FSensorComponentDataRow : public FTableRowBase
{
	GENERATED_BODY()
public :
	USensorDefinitionData * MakeSensorDefinitionData() const;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sensor")
	FName Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ClampMax="5", ClampMin="1", UIMin = "1", UIMax = "5", Delta = "1"), Category = "Sensor")
	float Level;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sensor")
	float SignalStrength;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sensor")
	float SignalResolution;
};
