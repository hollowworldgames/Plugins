// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Interface.h"
#include "EquippableInterface.generated.h"

class UEquipmentSlotComponent;
// This class does not need to be modified.
UINTERFACE()
class UEquippableInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class EQUIPMENT_API IEquippableInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual USkeletalMesh * GetSkeletalMesh() = 0;
	virtual void Equip(UEquipmentSlotComponent * Component) = 0;
	virtual void Remove(UEquipmentSlotComponent * Component) = 0;
	virtual bool CanBeUsedInSlot(FGameplayTag Slot) = 0;
};
