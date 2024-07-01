// Copyright (c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "UObject/Object.h"
#include "DamageableDefinition.generated.h"

class UDamageResistance;
/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class DAMAGE_API UDamageableDefinition : public UObject
{
	GENERATED_BODY()
public :
	FGameplayTag GetComponentId() const { return ComponentTag; }
	bool IsBurning() const { return Burning; }
	bool IsLeaking() const { return Leakage > 0; }
	virtual bool ApplyDamage(const UDamageType * DamageType, float Damage);
	void RepairDamage(float Repair);
	float GetDamage() const { return HitPoints; }
	float GetDamagePercent() const { return HitPoints / MaxHitPoints; }
	bool IsDestroyed() const { return HitPoints == 0; }
	float GetEfficiency() const { return DamageEfficiency.GetValueAtLevel(GetDamagePercent()); }
	virtual bool DoDamageTick(float DeltaTime);
	virtual void ApplyLeakage(float DeltaTime);
protected :
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Settings)
	float HitPoints = 100;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Settings)
	float MaxHitPoints = 100;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Settings)
	float Flammability = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Settings)
	bool Burning = false;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	float BurnDamage = 1.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Settings)
	bool CanLeak = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Settings)
    float Leakage = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Settings)
	FScalableFloat DamageEfficiency;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Settings)
	FGameplayTag ComponentTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	TSubclassOf<UDamageResistance> ResistanceClass;
};
