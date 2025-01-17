// Copyright (c) 2024 Hollow World Games llc All Rights Reserved.


#include "DamageModelComponent.h"
#include "DamageableSkeletalMeshComponent.h"
#include "DamageableDefinition.h"

// Sets default values for this component's properties
UDamageModelComponent::UDamageModelComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDamageModelComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UDamageModelComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	for(TPair<FGameplayTag, TObjectPtr<UDamageableDefinition>> Damage : Damageables)
	{
		Damage.Value->DoDamageTick(DeltaTime);
	}
}

void UDamageModelComponent::AddDamageable(UDamageableDefinition* Definition)
{
	Damageables.Add(Definition->GetComponentId(), Definition);
	
}

float UDamageModelComponent::GetHealth(FGameplayTag Tag)
{
	if(Damageables.Contains(Tag))
	{
		return Damageables[Tag]->GetDamage();
	}
	return 0;
}

float UDamageModelComponent::GetHealthPercent(FGameplayTag Tag)
{
	if(Damageables.Contains(Tag))
	{
		return Damageables[Tag]->GetDamagePercent();
	}
	return 0;
}

void UDamageModelComponent::ReportHit_Multicast_Implementation(FVector Location, FVector Normal, float Damage, FGameplayTag Component,
	const AActor* Victim)
{
	
}

void UDamageModelComponent::OnCollision(AActor* Me, AActor* Them, FVector Vector, const FHitResult& HitResult)
{
	float Damage = 0;
	if(UPrimitiveComponent * FHitComponent = HitResult.GetComponent())
	{
		FGameplayTag ComponentTag;
		if(FHitComponent->IsA(UDamageableSkeletalMeshComponent::StaticClass()))
		{
			ComponentTag = GetComponentTag(FHitComponent, HitResult.BoneName);
		}
		else
		{
			ComponentTag = GetComponentTag(FHitComponent);
		}
		ApplyDamageToComponent(ComponentTag, CollisionDamageType.GetDefaultObject(), Damage);
	}
}

void UDamageModelComponent::OnDamage(AActor* Me, float X, const UDamageType* Damage, AController* Controller,
	AActor* Them)
{
	Super::OnDamage(Me, X, Damage, Controller, Them);
	ensure(false);
}

void UDamageModelComponent::OnPointDamage(AActor* DamagedActor, float Damage, AController* InstigatedBy,
	FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector ShotFromDirection,
	const UDamageType* DamageType, AActor* DamageCauser)
{
	FGameplayTag ComponentTag;
	if(FHitComponent->IsA(UDamageableSkeletalMeshComponent::StaticClass()))
	{
		UDamageableSkeletalMeshComponent * DamageableSkeletalMeshComponent = Cast<UDamageableSkeletalMeshComponent>(FHitComponent);
		if(DamageableSkeletalMeshComponent)
		{
			ComponentTag = DamageableSkeletalMeshComponent->GetTagFromBone(BoneName);
		}
	}
	else
	{
		ComponentTag = GetComponentTag(FHitComponent);
	}

	ApplyDamageToComponent(ComponentTag, DamageType, Damage);
}

void UDamageModelComponent::OnRadialDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType,
	FVector Origin, const FHitResult& HitInfo, AController* InstigatedBy, AActor* DamageCauser)
{
	if(UPrimitiveComponent * FHitComponent = HitInfo.GetComponent())
	{
		FGameplayTag ComponentTag;
		if(FHitComponent->IsA(UDamageableSkeletalMeshComponent::StaticClass()))
		{
			UDamageableSkeletalMeshComponent * DamageableSkeletalMeshComponent = Cast<UDamageableSkeletalMeshComponent>(FHitComponent);
			if(DamageableSkeletalMeshComponent)
			{
				ComponentTag = DamageableSkeletalMeshComponent->GetTagFromBone(HitInfo.BoneName);
			}
		}
		else
		{
			ComponentTag = GetComponentTag(FHitComponent);
		}

		ApplyDamageToComponent(ComponentTag, DamageType, Damage);
	}
}

void UDamageModelComponent::ApplyDamageToComponent(FGameplayTag Tag, const UDamageType* DamageType, float Damage)
{
	if(Damageables.Contains(Tag))
	{
		if(Damageables[Tag]->ApplyDamage(DamageType, Damage))
		{
			OnComponentDestroyed.Broadcast(Damageables[Tag]);
		}
	}
}

