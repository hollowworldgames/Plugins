// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Data/ShieldComponentDataRow.h"

#include "Actors/Systems/ShieldActor.h"

UShieldDefinitionData* FShieldComponentDataRow::MakeShieldDefinitionData() const
{
	UShieldDefinitionData * ShieldDefinitionData = NewObject<UShieldDefinitionData>();
	ShieldDefinitionData->Level = Level;
	ShieldDefinitionData->HitPoints = HitPointsBonus;
	ShieldDefinitionData->PowerToHitPoints = PowerToHitPointsBonus;
	return ShieldDefinitionData;
}
