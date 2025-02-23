// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "EquipmentComponent.generated.h"


class IEquippableInterface;
class UEquipmentSlotComponent;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class EQUIPMENT_API UEquipmentComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UEquipmentComponent();
	void EquipInSlot(FGameplayTag SlotToAdd, TScriptInterface<IEquippableInterface> Item);
	TScriptInterface<IEquippableInterface> GetEquipmentInSlot(FGameplayTag SlotToAdd) const;
	float GetAttributeFromGear(const FGameplayTag& StrengthTag);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
	TArray<TObjectPtr<UEquipmentSlotComponent>> EquipmentSlots;
};
