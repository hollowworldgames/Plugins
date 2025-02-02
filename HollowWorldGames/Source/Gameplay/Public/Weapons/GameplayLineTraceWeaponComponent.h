// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayRangedWeaponComponent.h"
#include "GameplayLineTraceWeaponComponent.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPLAY_API UGameplayLineTraceWeaponComponent : public UGameplayRangedWeaponComponent
{
	GENERATED_BODY()
public :
	virtual void LaunchProjectile(AActor* ProjectileTarget, AActor * NewSource) override;
protected:
	UFUNCTION(Server, Reliable)
	void ReportHit(AActor * Target, float Damage);
	UFUNCTION(Server, Reliable)
	void ReportMiss();
};
