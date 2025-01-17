// Copyright (c) 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "VariableAsset.h"
#include "FloatVariableAsset.generated.h"

/**
 * 
 */
UCLASS()
class COMMON_API UFloatVariableAsset : public UVariableAsset
{
	GENERATED_BODY()
public :
	float GetValue() const { return Value; }
	void SetValue(const float NewValue) { Value = NewValue; }
protected :
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Value")
	float Value = 0.0f;
};
