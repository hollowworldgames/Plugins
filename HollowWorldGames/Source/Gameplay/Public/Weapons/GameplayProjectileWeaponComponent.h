// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayRangedWeaponComponent.h"
#include "GameplayProjectileWeaponComponent.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPLAY_API UGameplayProjectileWeaponComponent : public UGameplayRangedWeaponComponent
{
	GENERATED_BODY()
public :
	virtual void LaunchProjectile(AActor* ProjectileTarget, AActor * NewSource) override;
	UFUNCTION(Server, Reliable)
	void LaunchProjectile_Server(AActor * ProjectileTarget, AActor * NewSource, FVector Location, FRotator Rotation);
protected :
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	TSubclassOf<AGameplayProjectileActor> ProjectileClass;
};
