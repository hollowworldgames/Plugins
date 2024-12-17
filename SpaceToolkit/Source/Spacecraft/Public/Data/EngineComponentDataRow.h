// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Actors/Systems/EngineActor.h"
#include "UObject/Object.h"
#include "EngineComponentDataRow.generated.h"

/**
 * 
 */
USTRUCT()
struct SPACECRAFT_API FEngineComponentDataRow : public FTableRowBase
{
	GENERATED_BODY()
public :
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Engine")
	FString Name;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(ClampMax="5", ClampMin="1", UIMin = "1", UIMax = "5", Delta = "1"), Category = "Engine")
	float Level = 1;
	UEngineDefinitionData* MakeEngineDefinitionData() const;
};
