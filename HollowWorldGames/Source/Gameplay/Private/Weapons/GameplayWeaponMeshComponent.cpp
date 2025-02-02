// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.


#include "Weapons/GameplayWeaponMeshComponent.h"

bool UGameplayWeaponMeshComponent::AbilityLaunchOnImpact = true;

float UGameplayWeaponMeshComponent::GetDamage() const
{
	return FMath::RandRange(MinDamage, MaxDamage);
}
