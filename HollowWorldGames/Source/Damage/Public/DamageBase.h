// (c) Copyright 2023 Hollow World Games All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/DamageType.h"
#include "DamageBase.generated.h"

class UDamageResistance;
UCLASS(Blueprintable, BlueprintType)
class DAMAGE_API UDamageBase : public UDamageType
{
	GENERATED_BODY()
public:
	UDamageBase();
	~UDamageBase();
	float ApplyDamage(TSubclassOf<UDamageResistance> resistance, float damage) const;
protected :
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Damage)
	TArray<float> Damage;
};
