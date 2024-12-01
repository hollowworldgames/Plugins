// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Data/BatteryComponentDataRow.h"

#include "Actors/Systems/BatteryActor.h"

UBatteryDefinitionData* FBatteryComponentDataRow::MakeBatteryDefinitionData() const
{
	UBatteryDefinitionData* BatteryDefinitionData = NewObject<UBatteryDefinitionData>();
	BatteryDefinitionData->Level = Level;
	BatteryDefinitionData->BatteryCapacityBonus = Capacity;
	return BatteryDefinitionData;
}
