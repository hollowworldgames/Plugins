// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Data/EngineComponentDataRow.h"

UEngineDefinitionData* FEngineComponentDataRow::MakeEngineDefinitionData() const
{
	UEngineDefinitionData * EngineDefinitionData = NewObject<UEngineDefinitionData>();
	EngineDefinitionData->Level = Level;
	return EngineDefinitionData;
}
