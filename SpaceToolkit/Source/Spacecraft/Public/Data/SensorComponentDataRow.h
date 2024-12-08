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
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Level;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SignalStrength;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SignalResolution;
};
