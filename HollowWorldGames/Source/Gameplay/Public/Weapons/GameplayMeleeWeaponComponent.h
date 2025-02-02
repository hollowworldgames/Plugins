// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayWeaponMeshComponent.h"
#include "GameplayMeleeWeaponComponent.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class GAMEPLAY_API UGameplayMeleeWeaponComponent : public UGameplayWeaponMeshComponent
{
	GENERATED_BODY()
public :
	UFUNCTION(BlueprintCallable)
	void OnMontageStart();
	UFUNCTION(BlueprintCallable)
	void OnMontageComplete();
protected :
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	virtual void BeginPlay() override;
	bool MontageStarted = false;
};
