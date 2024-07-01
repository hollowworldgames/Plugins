// (c) Copyright 2023 Hollow World Games All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "ProjectileWeapon.generated.h"


class ABullet;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DAMAGE_API UProjectileWeapon : public USceneComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UProjectileWeapon();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
							   FActorComponentTickFunction* ThisTickFunction) override;
	virtual void Fire();
	virtual bool CanFire();
	void SetTrigger(bool NewTrigger) { Trigger = NewTrigger; }
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, Transient, Category=Status)
	bool Trigger = false;
	UPROPERTY(VisibleAnywhere, Transient, Category=Status)
	double Cooldown = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Attributes)
	double FireRate = 0.1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Attributes)
	double MuzzleVelocityMPS = 500;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Attributes)
	TSubclassOf<ABullet> BulletClass;
};
