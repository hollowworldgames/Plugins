// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/CapsuleComponent.h"
#include "DamageableCapsuleComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DAMAGE_API UDamageableCapsuleComponent : public UCapsuleComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UDamageableCapsuleComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	FGameplayTag GetComponentTag() const { return ComponentTag; }
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	FGameplayTag ComponentTag;
};
