// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.


#include "Data/EquipmentAsset.h"

#include "UtilityStatics.h"
#include "Components/EquipmentSlotComponent.h"

USkeletalMesh* UEquipmentItem::GetSkeletalMesh() const
{
	return Mesh;
}

void UEquipmentItem::Equip(UEquipmentSlotComponent* Component)
{
	if (EquipmentSlots.HasTag(Component->GetSlotTag()))
	{
		Component->SetEquippedItem(TObjectPtr<UEquipmentItem>(this));
	}
}

void UEquipmentItem::Remove(UEquipmentSlotComponent* Component)
{
	if (Component->GetEquippedItem() == this)
	{
		Component->SetEquippedItem(nullptr);
	}
}

bool UEquipmentItem::CanBeUsedInSlot(FGameplayTag Slot) const
{
	return EquipmentSlots.HasTag(Slot);
}

TArray<FEquipmentEffect> UEquipmentItem::GetEquipmentEffects() const
{
	return EquipmentEffects;
}

float UEquipmentItem::GetAttribute(const FGameplayTag Tag)
{
	float Value = 0;
	for (FEquipmentEffect Effect : EquipmentEffects)
	{
		if (Effect.AttributeTag.MatchesTagExact(Tag))
		{
			Value += Effect.EffectAmount;
		}
	}
	return Value;
}


UGameItem* UEquipmentAsset::CreateInstance(UObject* Outer) const
{
	UEquipmentItem * Item = Cast<UEquipmentItem>(Super::CreateInstance(Outer));
	if (IsValidEnsure(Item))
	{
		Item->EquipmentEffects = EquipmentEffects;
		Item->EquipmentSlots = EquipmentSlots;
		Item->Mesh = Mesh;
	}
	return Item;
}
