// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Missile.generated.h"

class UMissileDefinition;
class USphereComponent;
class UProjectileMovementComponent;

UCLASS()
class DAMAGE_API AMissile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMissile();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void FireAt(FVector location, FVector Momentum, AActor * target);
	
protected:
	UFUNCTION()
	void OnStop(const FHitResult& result);
	UFUNCTION(BlueprintImplementableEvent)
	void OnBoom(FVector location, FRotator rotation);
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Components)
	TObjectPtr<USphereComponent> Root;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Components)
	TObjectPtr<UProjectileMovementComponent> MovementComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Status)
	AActor * Target;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Status)
	float Power = 10;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Status)
	float PowerBurn = 1;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Status)
	float MaxThrustKN = 1;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Status)
	float KillVelocity = 1.0f;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Status)
	float ArmTime = 0.1f;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Status)
	float MaxDamage = 1000.0f;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Status)
	TSubclassOf<UDamageType> DamageClass;
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
