// (c) Copyright 2023 Hollow World Games All Rights Reserved


#include "ProjectileWeapon.h"

#include "ConverterStatics.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Bullet.h"


// Sets default values for this component's properties
UProjectileWeapon::UProjectileWeapon()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UProjectileWeapon::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UProjectileWeapon::TickComponent(float DeltaTime, ELevelTick TickType,
                                      FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	Cooldown = FMath::Clamp(Cooldown - DeltaTime, 0.0, FireRate);
	if(CanFire())
	{
		Fire();
	}
	
}

void UProjectileWeapon::Fire()
{
	Cooldown = FireRate;
	const USceneComponent * Muzzle = GetChildComponent(0);
	if(ensure(Muzzle))
	{
		const FVector Location = Muzzle->GetComponentLocation();
		const FRotator Rotation = Muzzle->GetComponentRotation();
		if(ABullet * Bullet = GetWorld()->SpawnActor<ABullet>(BulletClass, Location, Rotation))
		{
			UProjectileMovementComponent * Movement = Bullet->GetComponentByClass<UProjectileMovementComponent>();
			Movement->Velocity = (Muzzle->GetForwardVector() * UConverterStatics::MetersToUUnits(MuzzleVelocityMPS)) + GetOwner()->GetVelocity();
			Movement->MaxSpeed = UConverterStatics::MetersToUUnits(MuzzleVelocityMPS);
			Bullet->SetInstigator(GetOwner<APawn>());
		}
	}
}

bool UProjectileWeapon::CanFire()
{
	return Trigger && Cooldown == 0;
}

