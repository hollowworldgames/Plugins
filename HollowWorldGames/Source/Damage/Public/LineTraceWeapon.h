// (c) Copyright 2023 Hollow World Games All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "LineTraceWeapon.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FHitNotify, AActor*, Actor, FVector, Location, FVector, Normal );

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DAMAGE_API ULineTraceWeapon : public USceneComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	ULineTraceWeapon();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
							   FActorComponentTickFunction* ThisTickFunction) override;
	virtual void Fire();
	virtual bool CanFire();
	void SetTrigger(bool NewTrigger) { Trigger = NewTrigger; }
	virtual void DoDamage(AActor * Actor, const FHitResult& HitResult);
	UFUNCTION(BlueprintImplementableEvent)
	void OnFireAt(FVector Origin, FVector Destination);
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, Transient, Category=Status)
	bool Trigger = false;
	UPROPERTY(VisibleAnywhere, Transient, Category=Status)
	double Cooldown = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Attributes)
	double FireRate = 0.1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Damage)
	TSubclassOf<UDamageType> DamageClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Damage)
	float MaxDamage = 10;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FHitNotify OnImpact;
	UPROPERTY(VisibleAnywhere, Transient, Category=Status)
	double MaxRangeKM = 2;
};
