// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Abilities/GameplayAbilityTypes.h"
#include "GameFramework/Actor.h"
#include "GameplayProjectileActor.generated.h"

UCLASS()
class GAMEPLAY_API AGameplayProjectileActor : public AActor
{
	GENERATED_BODY()
public:
	// Sets default values for this actor's properties
	AGameplayProjectileActor();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable)
	virtual void LaunchAt(AActor* Target, AActor* NewSource, float Min, float Max);
	virtual FGameplayTag GetComponentFromBone(FName BoneName);
protected:
	float ComputeDamage(const FVector& Location) const;
	UFUNCTION(BlueprintCallable)
	virtual void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION(BlueprintCallable)
	void SetCollisionPrimitive(UPrimitiveComponent * NewCollider);
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Components)
	TObjectPtr<class UProjectileMovementComponent> MovementComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Components)
	TObjectPtr<UPrimitiveComponent> Collider;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Settings)
	float Velocity = 100.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Settings)
	float Lifetime = 2.0f;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Status)
	TObjectPtr<AActor> Source;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Status)
	FVector LaunchPoint;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Settings)
	FScalableFloat Falloff;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Settings)
	float MinDamage = 10;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Settings)
	float MaxDamage = 20;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Settings)
	float MaxRange = 10000.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Settings)
	bool SendEvent = true;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Settings)
	TSubclassOf<UGameplayEffect> ImpactEffect;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Settings)
	float ImpactLevel = 1;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Settings)
	FGameplayTag DamageType;
};
