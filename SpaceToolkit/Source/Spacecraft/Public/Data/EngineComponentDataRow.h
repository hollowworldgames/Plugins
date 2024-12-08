﻿// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

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
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FString Name;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float Level = 1;
	UEngineDefinitionData* MakeEngineDefinitionData() const;
};
