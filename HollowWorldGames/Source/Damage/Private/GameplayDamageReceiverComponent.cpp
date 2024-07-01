// Copyright (c) 2024 Hollow World Games llc. All Rights Reserved


#include "GameplayDamageReceiverComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "Components/GameplayAbilitySystemComponent.h"
#include "GameplayDamageType.h"

void UGameplayDamageReceiverComponent::OnCollision(AActor* Me, AActor* Them, FVector Vector,
                                                   const FHitResult& HitResult)
{
	Super::OnCollision(Me, Them, Vector, HitResult);

	if(UGameplayAbilitySystemComponent * Component = Cast<UGameplayAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Me)))
	{
		Component->ApplyGameplayEffect(ImpactEffect, FMath::Floor(Vector.Length() / LevelFactor));
	}
}

void UGameplayDamageReceiverComponent::OnDamage(AActor* Me, float X, const UDamageType* Damage, AController* Controller,
	AActor* Them)
{
	if(const UGameplayDamageType * Type = Cast<UGameplayDamageType>(Damage))
	{
		if(UGameplayAbilitySystemComponent * Component = Cast<UGameplayAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Me)))
		{
			for(int x = 0;x < FMath::Min(Type->Effects.Num(), Type->EffectLevels.Num()); x++)
			{
				Component->ApplyGameplayEffect(Type->Effects[x], Type->EffectLevels[x], Them);
			}
		}
	}
	else
	{
		//TODO : do something here
	}
}

void UGameplayDamageReceiverComponent::OnPointDamage(AActor* DamagedActor, float Damage, AController* InstigatedBy,
	FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector ShotFromDirection,
	const UDamageType* DamageType, AActor* DamageCauser)
{
	if(const UGameplayDamageType * Type = Cast<UGameplayDamageType>(DamageType))
	{
		if(UGameplayAbilitySystemComponent * Component = Cast<UGameplayAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(DamagedActor)))
		{
			for(int x = 0;x < FMath::Min(Type->Effects.Num(), Type->EffectLevels.Num()); x++)
			{
				Component->ApplyGameplayEffect(Type->Effects[x], Type->EffectLevels[x], DamageCauser);
			}
		}
	}
	else
	{
		//TODO : do something here
	}
}

void UGameplayDamageReceiverComponent::OnRadialDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType,
	FVector Origin, const FHitResult& HitInfo, AController* InstigatedBy, AActor* DamageCauser)
{
	if(const UGameplayDamageType * Type = Cast<UGameplayDamageType>(DamageType))
	{
		if(UGameplayAbilitySystemComponent * Component = Cast<UGameplayAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(DamagedActor)))
		{
			for(int x = 0;x < FMath::Min(Type->Effects.Num(), Type->EffectLevels.Num()); x++)
			{
				Component->ApplyGameplayEffect(Type->Effects[x], Type->EffectLevels[x], DamageCauser);
			}
		}
	}
	else
	{
		//TODO : do something here
	}
}
