// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Weapons/GameplayWeaponMeshComponent.h"
#include "GameplayRangedWeaponComponent.generated.h"

class AGameplayProjectileActor;
/**
 * 
 */
UCLASS()
class GAMEPLAY_API UGameplayRangedWeaponComponent : public UGameplayWeaponMeshComponent
{
	GENERATED_BODY()
public :
	UFUNCTION(BlueprintCallable)
	float ComputeDamage(FVector HitLocation) const;
	void SetMaxRange(const float Range) { MaxRange = Range; }
	void SetRangeFalloff(const FScalableFloat& Range) { RangeFalloff = Range; }
	virtual void LaunchProjectile(AActor * ProjectileTarget, AActor * NewSource);
protected :
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	FScalableFloat RangeFalloff;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	float MaxRange = 30000.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	FName Socket;
	UPROPERTY()
	TObjectPtr<AActor> Source;
};
