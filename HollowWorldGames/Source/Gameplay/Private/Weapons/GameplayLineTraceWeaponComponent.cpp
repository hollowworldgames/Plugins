// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.


#include "Weapons/GameplayLineTraceWeaponComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "Abilities/GameplayAbilityTypes.h"
#include "Weapons/GameplayWeaponTags.h"

void UGameplayLineTraceWeaponComponent::LaunchProjectile(AActor* ProjectileTarget, AActor * NewSource)
{
	Super::LaunchProjectile(ProjectileTarget, NewSource);
	FHitResult Hit;
	const FVector Start = GetSocketLocation(Socket);
	const FVector End = Start + GetSocketRotation(Socket).RotateVector(FVector(MaxRange, 0, 0));
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(Source);
	if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_WorldDynamic, Params))
	{
		FGameplayEventData Payload;
		Payload.Instigator = Source;
		Payload.Target = Hit.GetActor();
		Payload.OptionalObject = this;
		Payload.EventMagnitude = ComputeDamage(Hit.ImpactPoint);
		UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(Source, ImpactEventTag, Payload);
	}
}

void UGameplayLineTraceWeaponComponent::ReportMiss_Implementation()
{
	FGameplayEventData Payload;
	Payload.Instigator = Source;
	Payload.Target = nullptr;
	Payload.OptionalObject = this;
	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(GetOwner(), MissEventTag, Payload);
}

void UGameplayLineTraceWeaponComponent::ReportHit_Implementation(AActor* Target, const float Damage)
{
	FGameplayEventData Payload;
	Payload.Instigator = Source;
	Payload.Target = Target;
	Payload.OptionalObject = this;
	Payload.EventMagnitude = Damage;
	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(GetOwner(), ImpactEventTag, Payload);
}
