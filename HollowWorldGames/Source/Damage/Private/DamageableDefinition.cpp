// Copyright (c) 2024 Hollow World Games llc All Rights Reserved.


#include "DamageableDefinition.h"

#include "DamageBase.h"
#include "DamageModelComponent.h"
#include "DamageReceiverComponent.h"

bool UDamageableDefinition::ApplyDamage(const UDamageType * DamageType, float Damage)
{
	bool Destroyed = false;
	if(DamageType && DamageType->IsA(UDamageBase::StaticClass()))
	{
		const UDamageBase * DamageBase = Cast<UDamageBase>(DamageType);
		if(ensure(DamageBase))
		{
			Damage = DamageBase->ApplyDamage(ResistanceClass, Damage);
		}
	}
	if(HitPoints > 0)
	{
		HitPoints = FMath::Clamp(HitPoints - Damage, 0, MaxHitPoints);
		Destroyed = HitPoints == 0;
	}
	
	if(Flammability > 0 && !Burning)
	{
		Burning = FMath::RandRange(0, 100) < Flammability;
	}
	if(CanLeak)
	{
		Leakage += 1.0f;
	}
	return Destroyed;
}

void UDamageableDefinition::RepairDamage(float Repair)
{
	HitPoints = FMath::Clamp(HitPoints + Repair, 0, MaxHitPoints);
	Burning = false;
	Leakage = 0;
}

bool UDamageableDefinition::DoDamageTick(float DeltaTime)
{
	if(Leakage > 0)
	{
		ApplyLeakage(DeltaTime);
	}
	if(Burning)
	{
		return ApplyDamage(nullptr, BurnDamage * DeltaTime);
	}
	return false;
}

void UDamageableDefinition::ApplyLeakage(float DeltaTime)
{
	
}

void UDamageableDefinition::Initialize(UDamageModelComponent* DamageModelComponent)
{
	DamageModelComponent->AddDamageable(this);
}
