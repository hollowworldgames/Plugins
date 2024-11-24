// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/WeaponActor.h"
#include "Components/GameplayAbilitySystemComponent.h"


// Sets default values
AWeaponActor::AWeaponActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UGameplayAbilitySystemComponent>("Ability System");
}

// Called when the game starts or when spawned
void AWeaponActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeaponActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AWeaponActor::SetOwningShip(TObjectPtr<AActor> MyOwner)
{
	OwningShip = MyOwner;
}

UAbilitySystemComponent* AWeaponActor::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AWeaponActor::OnStartFire()
{
}

void AWeaponActor::OnStopFire()
{
}

