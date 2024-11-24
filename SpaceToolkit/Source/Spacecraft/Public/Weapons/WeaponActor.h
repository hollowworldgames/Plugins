// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Actor.h"
#include "WeaponActor.generated.h"

class UGameplayAbilitySystemComponent;

UCLASS(Blueprintable, BlueprintType)
class SPACECRAFT_API AWeaponActor : public AActor, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AWeaponActor();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void SetOwningShip(TObjectPtr<AActor> MyOwner);
	virtual UAbilitySystemComponent * GetAbilitySystemComponent() const override;
	virtual void OnStartFire();
	virtual void OnStopFire();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category=Owner)
	TObjectPtr<AActor> OwningShip;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Abilities)
	TObjectPtr<UGameplayAbilitySystemComponent> AbilitySystemComponent;
};
