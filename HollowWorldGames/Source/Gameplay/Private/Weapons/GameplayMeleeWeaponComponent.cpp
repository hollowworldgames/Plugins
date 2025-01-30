// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.


#include "Weapons/GameplayMeleeWeaponComponent.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "NativeGameplayTags.h"
#include "Abilities/GameplayAbilityTypes.h"
#include "Interfaces/GameplayActorInterface.h"

UE_DEFINE_GAMEPLAY_TAG_COMMENT(ImpactEventTag, "Combat.Event.Impact", "Combat Impact Event");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(MissEventTag, "Combat.Event.Miss", "Combat Miss Event");

void UGameplayMeleeWeaponComponent::SetCurrentAbility(FGameplayTag Ability)
{
	AbilityTag = Ability;
}

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
			if (UGameplayAbilitySystemComponent * SourceComponent =Cast<UGameplayAbilitySystemComponent>(
				UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetOwner())))
			{
				SourceComponent->OnAbilityInputPressed(AbilityTag);
				SourceComponent->OnAbilityInputReleased(AbilityTag);
				FGameplayEventData Payload;
				Payload.Instigator = GetOwner();
				Payload.Target = OtherActor;
				Payload.OptionalObject = this;
				UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(GetOwner(), ImpactEventTag, Payload);
			}
		}
		else
		{
			if (MontageStarted)
			{
				FGameplayEventData Payload;
				Payload.Instigator = GetOwner();
				Payload.Target = OtherActor;
				Payload.OptionalObject = this;
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
