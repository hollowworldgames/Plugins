﻿// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ReactorComponentDataRow.generated.h"

class UReactorDefinitionData;

USTRUCT(BlueprintType)
struct SPACECRAFT_API FReactorComponentDataRow : public FTableRowBase
{
	GENERATED_BODY()
public :
	UReactorDefinitionData * MakeReactorDefinitionData() const;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName Name;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float Level;
};
