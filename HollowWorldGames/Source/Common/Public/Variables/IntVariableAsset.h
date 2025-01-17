// Copyright (c) 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "VariableAsset.h"
#include "IntVariableAsset.generated.h"

UCLASS()
class COMMON_API UIntVariableAsset : public UVariableAsset
{
	GENERATED_BODY()
public :
	int GetValue() const { return Value; }
	void SetValue(const int NewValue) { Value = NewValue; }
protected :
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Value")
	int Value = 0;
};
