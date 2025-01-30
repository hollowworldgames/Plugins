// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.


#include "Data/GameItemTemplate.h"

UGameItem* UGameItemTemplate::CreateInstance(UObject * Outer) const
{
	return NewObject<UGameItem>(Outer, ItemTemplate);
}

UGameItem* UGameItemTemplate::GetDefaultInstance() const
{
	return ItemTemplate.GetDefaultObject();
}
