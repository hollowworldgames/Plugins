// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.


#include "Weapons/GameplayRangedWeaponComponent.h"

#include "Weapons/GameplayProjectileActor.h"

float UGameplayRangedWeaponComponent::ComputeDamage(const FVector HitLocation) const
{
	return RangeFalloff.GetValueAtLevel(FMath::Clamp(FVector::Dist(GetComponentLocation(), HitLocation) / MaxRange, 0 , 1)) * GetDamage();
}

void UGameplayRangedWeaponComponent::LaunchProjectile(AActor* ProjectileTarget, AActor * NewSource)
{
	Source = NewSource;
}

