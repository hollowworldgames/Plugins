// (c) Copyright 2023 Hollow World Games All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "DamageReceiverComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDamageDead, AActor *, Victim, AActor *, Killer);
USTRUCT(BlueprintType)
struct DAMAGE_API FComponentHealth
{
	GENERATED_BODY()
	UPROPERTY()
	FGameplayTag Name;
	UPROPERTY()
	float Health = 100;
	UPROPERTY()
	float MaxHealth = 100;
	bool IsDestroyed() const { return Health == 0; }
	float GetHealthPercent() const;
	void ApplyDamage(float Damage);
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FComponentDamaged, const FComponentHealth&, Health);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DAMAGE_API UDamageReceiverComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDamageReceiverComponent();
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FDamageDead OnDead;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FComponentDamaged OnComponentDamaged;
protected:
	FGameplayTag GetComponentTag(UPrimitiveComponent * PrimitiveComponent, FName BoneName);
	FGameplayTag GetComponentTag(UPrimitiveComponent * PrimitiveComponent);
	UFUNCTION()
	virtual void OnCollision(AActor* Me, AActor* Them, FVector Vector, const FHitResult& HitResult);
	UFUNCTION()
	virtual void OnDamage(AActor* Me, float X, const UDamageType* Damage, AController* Controller, AActor* Them);
	UFUNCTION()
	virtual void OnPointDamage(AActor* DamagedActor, float Damage, AController* InstigatedBy, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName,
	                   FVector ShotFromDirection, const UDamageType* DamageType, AActor* DamageCauser);
	UFUNCTION()
	virtual void OnRadialDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, FVector Origin, const FHitResult& HitInfo, AController* InstigatedBy,
	                    AActor* DamageCauser);
	// Called when the game starts
	virtual void BeginPlay() override;
};
