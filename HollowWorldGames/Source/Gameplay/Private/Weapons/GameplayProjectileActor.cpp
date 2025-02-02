// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/GameplayProjectileActor.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "Abilities/GameplayAbilityTypes.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Weapons/GameplayWeaponTags.h"


// Sets default values
AGameplayProjectileActor::AGameplayProjectileActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("MovementComponent");
}

// Called when the game starts or when spawned
void AGameplayProjectileActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGameplayProjectileActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Lifetime -= DeltaTime;
	if (Lifetime < 0.0f)
	{
		FGameplayEventData Payload;
		Payload.Instigator = Source;
		Payload.Target = nullptr;
		Payload.OptionalObject = this;
		Payload.EventMagnitude = 0;
		UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(Source, MissEventTag, Payload);
	}
}

void AGameplayProjectileActor::LaunchAt(AActor* Target, AActor * NewSource, float Min, float Max)
{
	LaunchPoint = GetActorLocation();
	Source = NewSource;
	MinDamage = Min;
	MaxDamage = Max;
}

float AGameplayProjectileActor::ComputeDamage(const FVector& Location) const
{
	const double Distance = FMath::Clamp(FVector::Dist(Location, LaunchPoint), 0, 1);
	return Falloff.GetValueAtLevel(Distance / MaxRange) * FMath::RandRange(MinDamage, MaxDamage);
}

void AGameplayProjectileActor::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                              UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	FGameplayEventData Payload;
	Payload.Instigator = Source;
	Payload.Target = OtherActor;
	Payload.OptionalObject = this;
	Payload.EventMagnitude = ComputeDamage(SweepResult.Location);
	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(Source, ImpactEventTag, Payload);
}

void AGameplayProjectileActor::SetCollisionPrimitive(UPrimitiveComponent* NewCollider)
{
	Collider = NewCollider;
	Collider->OnComponentBeginOverlap.AddDynamic(this, &AGameplayProjectileActor::OnBeginOverlap);
}

