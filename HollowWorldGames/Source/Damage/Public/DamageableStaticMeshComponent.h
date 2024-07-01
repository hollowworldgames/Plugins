// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/StaticMeshComponent.h"
#include "DamageableStaticMeshComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DAMAGE_API UDamageableStaticMeshComponent : public UStaticMeshComponent
{
	GENERATED_BODY()
public :
	FGameplayTag GetComponentTag() const { return ComponentTag; }
protected:
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Damage)
	FGameplayTag ComponentTag;
};
