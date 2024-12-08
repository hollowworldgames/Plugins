﻿// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ShieldComponentDataRow.generated.h"

class UShieldDefinitionData;
/**
 * 
 */
USTRUCT(BlueprintType)
struct SPACECRAFT_API FShieldComponentDataRow : public FTableRowBase
{
	GENERATED_BODY()
public :
	UShieldDefinitionData * MakeShieldDefinitionData() const;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName Name;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float Level;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float HitPointsBonus;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float PowerToHitPointsBonus;
};
