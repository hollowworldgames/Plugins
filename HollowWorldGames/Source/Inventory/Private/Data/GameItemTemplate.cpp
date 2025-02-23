// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.


#include "Data/GameItemTemplate.h"

UE_DEFINE_GAMEPLAY_TAG_COMMENT(ItemTag, "Item", "Item");

UGameItem* UGameItemTemplate::CreateInstance(UObject * Outer) const
{
	UGameItem * GameItem = NewObject<UGameItem>(Outer, ItemTemplate);
	GameItem->Guid = FGuid::NewGuid();
	GameItem->Name = Name;
	GameItem->ItemId = ItemId;
	GameItem->ItemType = ItemType;
	GameItem->StackLimit = StackLimit->GetValue();
	return GameItem;
}

UGameItem* UGameItemTemplate::GetDefaultInstance() const
{
	return ItemTemplate.GetDefaultObject();
}
