// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "Bullet.generated.h"

class ASpaceCraftPawn;
class UProjectileMovementComponent;

UCLASS()
class DAMAGE_API ABullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABullet();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void Launch(const FVector& Location, const FVector& Velocity, const FRotator& Direction, APawn * Firer);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION()
	void OnStop(const FHitResult& ImpactResult);
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Components)
	TObjectPtr<UBoxComponent> Root;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Components)
	TObjectPtr<UProjectileMovementComponent> Movement;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadWrite, Category=Status)
	float MinDamage = 1;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadWrite, Category=Status)
	float MaxDamage = 10;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadWrite, Category=Status)
	UCurveFloat * Falloff;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadWrite, Category=Status)
	float MinRangeMeters = 50.0f;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadWrite, Category=Status)
	float MaxRangeMeters = 800.0f;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Status)
	TSubclassOf<UDamageType> DamageClass;
};
