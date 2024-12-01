// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Data/SpaceCraftDataRow.h"

#include "Data/USpaceCraftDefinitionData.h"
#include "Kismet/GameplayStatics.h"
#include "Utility/SpaceCraftGameInstance.h"

USpaceCraftDefinitionData* FSpaceCraftDataRow::MakeSpaceCraftDefinitionData(USpaceCraftGameInstance * Instance) const
{
	USpaceCraftDefinitionData * SpaceCraftDefinitionData = NewObject<USpaceCraftDefinitionData>();
	if (ensure(Instance))
	{
		SpaceCraftDefinitionData->BatteryData = Instance->GetBatteryDefinitionData(Battery);
		SpaceCraftDefinitionData->CraftClass = ActorClass;
		SpaceCraftDefinitionData->EngineData = Instance->GetEngineDefinitionData(Engine);
		SpaceCraftDefinitionData->FuelData = Instance->GetFuelDefinitionData(FuelTank);
		SpaceCraftDefinitionData->ReactorData = Instance->GetReactorDefinitionData(Reactor);
		SpaceCraftDefinitionData->SensorData = Instance->GetSensorDefinitionData(Sensor);
		SpaceCraftDefinitionData->FrontShieldData = Instance->GetShieldDefinitionData(FrontShield);
		SpaceCraftDefinitionData->RearShieldData = Instance->GetShieldDefinitionData(RearShield);
		SpaceCraftDefinitionData->LeftShieldData = Instance->GetShieldDefinitionData(LeftShield);
		SpaceCraftDefinitionData->RightShieldData = Instance->GetShieldDefinitionData(RightShield);
		SpaceCraftDefinitionData->LifeSupportData = Instance->GetLifeSupportDefinitionData(LifeSupport);
	}
	return SpaceCraftDefinitionData;
}
