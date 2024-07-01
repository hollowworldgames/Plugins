// (c) Copyright 2023 Hollow World Games All Rights Reserved


#include "DamageReceiverComponent.h"

#include "DamageableSkeletalMeshComponent.h"
#include "DamageableStaticMeshComponent.h"


float FComponentHealth::GetHealthPercent() const
{
	return Health / MaxHealth;
}

void FComponentHealth::ApplyDamage(float Damage)
{
	Health = FMath::Clamp(Health - Damage, 0.0f, MaxHealth);
}

// Sets default values for this component's properties
UDamageReceiverComponent::UDamageReceiverComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

FGameplayTag UDamageReceiverComponent::GetComponentTag(UPrimitiveComponent* PrimitiveComponent, FName BoneName)
{
	if(UDamageableSkeletalMeshComponent * DamageableSkeletalMeshComponent = Cast<UDamageableSkeletalMeshComponent>(PrimitiveComponent))
	{
		return DamageableSkeletalMeshComponent->GetTagFromBone(BoneName);
	}
	return FGameplayTag();
}

FGameplayTag UDamageReceiverComponent::GetComponentTag(UPrimitiveComponent* PrimitiveComponent)
{
	
	return FGameplayTag();
}

void UDamageReceiverComponent::OnCollision(AActor* Actor, AActor* Actor1, FVector Vector,
                                           const FHitResult& HitResult)
{
	
}

void UDamageReceiverComponent::OnDamage(AActor* Actor, float X, const UDamageType* Damage, AController* Controller,
	AActor* Actor1)
{
	
}

void UDamageReceiverComponent::OnPointDamage(AActor* DamagedActor, float Damage, AController* InstigatedBy,
	FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector ShotFromDirection,
	const UDamageType* DamageType, AActor* DamageCauser)
{
	
}

void UDamageReceiverComponent::OnRadialDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType,
	FVector Origin, const FHitResult& HitInfo, AController* InstigatedBy, AActor* DamageCauser)
{
	
}


// Called when the game starts
void UDamageReceiverComponent::BeginPlay()
{
	Super::BeginPlay();

	GetOwner()->OnActorHit.AddDynamic(this, &UDamageReceiverComponent::OnCollision);
	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UDamageReceiverComponent::OnDamage);
	GetOwner()->OnTakePointDamage.AddDynamic(this, &UDamageReceiverComponent::OnPointDamage);
	GetOwner()->OnTakeRadialDamage.AddDynamic(this, &UDamageReceiverComponent::OnRadialDamage);
}


