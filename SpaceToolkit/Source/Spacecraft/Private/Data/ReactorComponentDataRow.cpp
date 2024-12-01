// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Data/ReactorComponentDataRow.h"

#include "Actors/Systems/ReactorActor.h"

UReactorDefinitionData* FReactorComponentDataRow::MakeReactorDefinitionData() const
{
	UReactorDefinitionData * ReactorData = NewObject<UReactorDefinitionData>();
	ReactorData->Level = Level;
	return ReactorData;
}
