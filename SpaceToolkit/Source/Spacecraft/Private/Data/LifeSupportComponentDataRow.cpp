// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Data/LifeSupportComponentDataRow.h"

#include "Actors/Systems/LifeSupportActor.h"

ULifeSupportDefinitionData* FLifeSupportComponentDataRow::MakeLifeSupportDefinitionData() const
{
	ULifeSupportDefinitionData * DefinitionData = NewObject<ULifeSupportDefinitionData>();
	DefinitionData->Level = Level;
	return DefinitionData;
}
