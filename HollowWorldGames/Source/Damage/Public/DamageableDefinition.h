// Copyright (c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "UObject/Object.h"
#include "DamageableDefinition.generated.h"

class UDamageModelComponent;
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
	virtual void Initialize(UDamageModelComponent* DamageModelComponent);
protected :
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Health)
	float HitPoints = 100;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Health)
	float MaxHitPoints = 100;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Burning)
	float Flammability = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Burning)
	bool Burning = false;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Burning)
	float BurnDamage = 1.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Leakage)
	bool CanLeak = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Leakage)
	float LeakageChance = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Leakage)
    float Leakage = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Damage)
	FScalableFloat DamageEfficiency;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Settings)
	FGameplayTag ComponentTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Damage)
	TSubclassOf<UDamageResistance> ResistanceClass;
};
