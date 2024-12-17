// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

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
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Reactor Component")
	FName Name;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(ClampMax="5", ClampMin="1", UIMin = "1", UIMax = "5", Delta = "1"), Category = "Reactor Component")
	float Level;
};
