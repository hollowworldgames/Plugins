﻿// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "LifeSupportComponentDataRow.generated.h"

class ULifeSupportDefinitionData;
/**
 * 
 */
USTRUCT(BlueprintType)
struct SPACECRAFT_API FLifeSupportComponentDataRow : public FTableRowBase
{
	GENERATED_BODY()
public :
	ULifeSupportDefinitionData * MakeLifeSupportDefinitionData() const;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Level;
};
