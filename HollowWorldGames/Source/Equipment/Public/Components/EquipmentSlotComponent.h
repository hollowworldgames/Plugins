// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/SkeletalMeshComponent.h"
#include "EquipmentSlotComponent.generated.h"

class IEquippableInterface;
/**
 * 
 */
UCLASS()
class EQUIPMENT_API UEquipmentSlotComponent : public USkeletalMeshComponent
{
	GENERATED_BODY()
	TScriptInterface<IEquippableInterface> GetEquippedItem() const { return Equipped; }
	void SetEquippedItem(TScriptInterface<IEquippableInterface> Item);
	FGameplayTag GetSlotTag() const { return SlotTag; }
protected :
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	FGameplayTag SlotTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Item)
	TScriptInterface<IEquippableInterface> Equipped;
};
