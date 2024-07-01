// Copyright (c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "DamageReceiverComponent.h"
#include "DamageModelComponent.generated.h"

class UDamageableDefinition;

USTRUCT(BlueprintType)
struct FDamageable
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayTag ComponentTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName ComponentBone;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnComponentDestroyed, UDamageableDefinition*, DamageableDefinition);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DAMAGE_API UDamageModelComponent : public UDamageReceiverComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDamageModelComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void AddDamageable(UDamageableDefinition * Definition);
	float GetHealth(FGameplayTag Tag);
	float GetHealthPercent(FGameplayTag Tag);
protected:
	virtual void OnCollision(AActor* Me, AActor* Them, FVector Vector, const FHitResult& HitResult) override;
	virtual void OnDamage(AActor* Me, float X, const UDamageType* Damage, AController* Controller, AActor* Them) override;
	virtual void OnPointDamage(AActor* DamagedActor, float Damage, AController* InstigatedBy, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector ShotFromDirection, const UDamageType* DamageType, AActor* DamageCauser) override;
	virtual void OnRadialDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, FVector Origin, const FHitResult& HitInfo, AController* InstigatedBy, AActor* DamageCauser) override;
	virtual void ApplyDamageToComponent(FGameplayTag Tag, const UDamageType* DamageType, float Damage);
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly)
	TMap<FGameplayTag, TObjectPtr<UDamageableDefinition>> Damageables;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Damage)
	TSubclassOf<UDamageType> CollisionDamageType;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FOnComponentDestroyed OnComponentDestroyed;
};
