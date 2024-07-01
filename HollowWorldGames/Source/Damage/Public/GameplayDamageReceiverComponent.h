// Copyright (c) 2024 Hollow World Games llc. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "DamageReceiverComponent.h"
#include "GameplayDamageReceiverComponent.generated.h"

class UGameplayEffect;
/**
 * 
 */
UCLASS()
class DAMAGE_API UGameplayDamageReceiverComponent : public UDamageReceiverComponent
{
	GENERATED_BODY()
public :
	virtual void OnCollision(AActor* Me, AActor* Them, FVector Vector, const FHitResult& HitResult) override;
	virtual void OnDamage(AActor* Me, float X, const UDamageType* Damage, AController* Controller, AActor* Them) override;
	virtual void OnPointDamage(AActor* DamagedActor, float Damage, AController* InstigatedBy, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector ShotFromDirection, const UDamageType* DamageType, AActor* DamageCauser) override;
	virtual void OnRadialDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, FVector Origin, const FHitResult& HitInfo, AController* InstigatedBy, AActor* DamageCauser) override;
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=ImpactDamage)
	TSubclassOf<UGameplayEffect> ImpactEffect;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=ImpactDamage)
	float LevelFactor = 100;
};
