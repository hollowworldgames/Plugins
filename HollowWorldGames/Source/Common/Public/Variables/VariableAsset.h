// Copyright (c) 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "VariableAsset.generated.h"

/**
 * 
 */
UCLASS()
class COMMON_API UVariableAsset : public UDataAsset
{
	GENERATED_BODY()
public :
	FName GetVariableName() const { return VariableName; }
	FName GetCategory() const { return Category; }
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Setting)
	FName VariableName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Setting)
	FName Category;
};
