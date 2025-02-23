// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.


#include "Weapons/GameplayMeleeWeaponComponent.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "GameplayUtilities.h"

#include "Abilities/GameplayAbilityTypes.h"
#include "Interfaces/GameplayActorInterface.h"
#include "Weapons/GameplayWeaponTags.h"


void UGameplayMeleeWeaponComponent::OnMontageStart()
{
	MontageStarted = true;
}

void UGameplayMeleeWeaponComponent::OnMontageComplete()
{
	if (MontageStarted)
	{
		FGameplayEventData Payload;
		Payload.Instigator = GetOwner();
		Payload.Target = nullptr;
		Payload.OptionalObject = this;
		UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(GetOwner(), MissEventTag, Payload);
	}
}

void UGameplayMeleeWeaponComponent::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
                                          UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor->Implements<UGameplayActorInterface>())
	{
		if (AbilityLaunchOnImpact)
		{
			UGameplayUtilities::RunAbility(CurrentAbility, OtherActor, GetOwner(), FMath::RandRange(MinDamage, MaxDamage));
		}
		else
		{
			if (MontageStarted)
			{
				FGameplayEventData Payload;
				Payload.Instigator = GetOwner();
				Payload.Target = OtherActor;
				Payload.OptionalObject = this;
				Payload.EventMagnitude = FMath::RandRange(MinDamage, MaxDamage); 
				UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(GetOwner(), ImpactEventTag, Payload);
				MontageStarted = false;//avoid sending miss and further hits
			}
		}
		
	}
}

void UGameplayMeleeWeaponComponent::BeginPlay()
{
	Super::BeginPlay();

	OnComponentHit.AddDynamic(this, &UGameplayMeleeWeaponComponent::OnHit);
}
