// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/WeaponActorComponent.h"

#include "Weapons/WeaponActor.h"


// Sets default values for this component's properties
UWeaponActorComponent::UWeaponActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWeaponActorComponent::BeginPlay()
{
	Super::BeginPlay();

	AWeaponActor * WeaponActor = Cast<AWeaponActor>(GetChildActor());
	if (ensure(WeaponActor))
	{
		WeaponActor->SetOwningShip(GetOwner());
	}
	
}

void UWeaponActorComponent::SetTriggerPressed() const
{
	AWeaponActor * Weapon = GetWeaponActor();
	if(ensure(Weapon))
	{
		Weapon->OnStartFire();	
	}
}

void UWeaponActorComponent::SetTriggerReleased() const
{
	AWeaponActor * Weapon = GetWeaponActor();
	if(ensure(Weapon))
	{
		Weapon->OnStopFire();	
	}
}

