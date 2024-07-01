// (c) Copyright 2023 Hollow World Games All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DamageResistance.generated.h"

/**
 * 
 */
UCLASS()
class DAMAGE_API UDamageResistance : public UObject
{
	GENERATED_BODY()
public :
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Damage)
	TArray<float> Resistance;
};
