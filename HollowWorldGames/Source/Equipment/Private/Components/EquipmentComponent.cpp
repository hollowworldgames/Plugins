// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/EquipmentComponent.h"

#include "NativeGameplayTags.h"
#include "Interfaces/EquippableInterface.h"
#include "Components/EquipmentSlotComponent.h"


// Sets default values for this component's properties
UEquipmentComponent::UEquipmentComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UEquipmentComponent::EquipInSlot(const FGameplayTag SlotToAdd, TScriptInterface<IEquippableInterface> Item)
{
	for (const auto Slot : EquipmentSlots)
	{
		if (Slot->GetSlotTag().MatchesTag(SlotToAdd))
		{
			Slot->SetEquippedItem(Item);
			break;
		}
	}
}

TScriptInterface<IEquippableInterface> UEquipmentComponent::GetEquipmentInSlot(const FGameplayTag SlotToAdd) const
{
	TScriptInterface<IEquippableInterface> EquipmentInSlot;
	for (const auto Slot : EquipmentSlots)
	{
		if (Slot->GetSlotTag().MatchesTag(SlotToAdd))
		{
			EquipmentInSlot = Slot;
			break;
		}
	}
	return EquipmentInSlot;
}

float UEquipmentComponent::GetAttributeFromGear(const FGameplayTag& Tag)
{
	float Attribute = 0.0f;
	for (const auto Slot : EquipmentSlots)
	{
		if (const TScriptInterface<IEquippableInterface> Equipment = Slot->GetEquippedItem())
		{
			Attribute += Equipment->GetAttribute(Tag);
		}
	}
	return Attribute;
}


// Called when the game starts
void UEquipmentComponent::BeginPlay()
{
	Super::BeginPlay();

	GetOwner()->GetComponents(EquipmentSlots);
	
}


