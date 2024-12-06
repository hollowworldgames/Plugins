// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Gameplay/SystemGameplayAbility.h"

#include "Actors/SpaceCraftActor.h"
#include "Components/GameplayAbilitySystemComponent.h"

UGameplayAbilitySystemComponent* USystemGameplayAbility::GetSystemAbilityComponent(FGameplayTag System)
{
	ASpaceCraftActor * Actor = Cast<ASpaceCraftActor>(GetCurrentActorInfo()->AvatarActor);
	if (ensure(Actor))
	{
		return Actor->GetSystem(System);
	}
	return nullptr;
}

void USystemGameplayAbility::ApplyEffectToSystem(FGameplayTag System, TSubclassOf<UGameplayEffect> Effect)
{
	UGameplayAbilitySystemComponent * AbilitySystemComponent = GetSystemAbilityComponent(System);
	if (ensure(AbilitySystemComponent))
	{
		if (UGameplayAbilitySystemComponent * SourceComponent = Cast<UGameplayAbilitySystemComponent>(GetCurrentActorInfo()->AbilitySystemComponent))
		{
			SourceComponent->ApplyGameplayEffect(Effect,static_cast<float>(GetAbilityLevel(GetCurrentAbilitySpecHandle(), GetCurrentActorInfo())),
				GetCurrentActorInfo()->AvatarActor.Get());
		}
	}
}

void USystemGameplayAbility::ApplyEffectsToSystem()
{
	for (TSubclassOf<UGameplayEffect> Effect : EffectsToApply)
	{
		ApplyEffectToSystem(SystemTag, Effect);
	}
}

void USystemGameplayAbility::RemoveEffectFromSystem(FGameplayTag System, TSubclassOf<UGameplayEffect> Effect)
{
	UGameplayAbilitySystemComponent * AbilitySystemComponent = GetSystemAbilityComponent(System);
	if (ensure(AbilitySystemComponent))
	{
		if (UGameplayAbilitySystemComponent * SourceComponent = Cast<UGameplayAbilitySystemComponent>(GetCurrentActorInfo()->AbilitySystemComponent))
		{
			FGameplayTagContainer Tags;
			Tags.AddTag(System);
			SourceComponent->RemoveGameplayEffect(Effect);
		}
	}
}

void USystemGameplayAbility::RemoveEffectsFromSystem()
{
	for (TSubclassOf<UGameplayEffect> Effect : EffectsToApply)
	{
		RemoveEffectFromSystem(SystemTag, Effect);
	}
}
