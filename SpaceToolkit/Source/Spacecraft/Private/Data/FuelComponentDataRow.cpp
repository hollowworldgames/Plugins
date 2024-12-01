// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Data/FuelComponentDataRow.h"

#include "Actors/Systems/FuelActor.h"

UFuelDefinitionData* FFuelComponentDataRow::MakeFuelDefinitionData() const
{
	UFuelDefinitionData * FuelDefinitionData = NewObject<UFuelDefinitionData>();
	FuelDefinitionData->Level = Level;
	FuelDefinitionData->MaxFuelBonus = MaxFuel;
	return FuelDefinitionData;
}
