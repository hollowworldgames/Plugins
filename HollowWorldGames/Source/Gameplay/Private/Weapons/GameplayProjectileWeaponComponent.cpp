// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.


#include "Weapons/GameplayProjectileWeaponComponent.h"
#include "Weapons/GameplayProjectileActor.h"

void UGameplayProjectileWeaponComponent::LaunchProjectile(AActor* ProjectileTarget, AActor * NewSource)
{
	Super::LaunchProjectile(ProjectileTarget, NewSource);
	LaunchProjectile_Server(ProjectileTarget, Source, GetSocketLocation(Socket), GetSocketRotation(Socket));
}

void UGameplayProjectileWeaponComponent::LaunchProjectile_Server_Implementation(AActor* ProjectileTarget, AActor* NewSource, FVector Location,
	FRotator Rotation)
{
	FTransform Transform;
	Transform.SetLocation(Location);
	Transform.SetRotation(Rotation.Quaternion());
	Transform.SetScale3D(FVector(1, 1, 1));
	if (AGameplayProjectileActor * Actor = GetWorld()->SpawnActorDeferred<AGameplayProjectileActor>(ProjectileClass, Transform))
	{
		Actor->FinishSpawning(Transform);
		Actor->LaunchAt(ProjectileTarget, Source);
	}
}