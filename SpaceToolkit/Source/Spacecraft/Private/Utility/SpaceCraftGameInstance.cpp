// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Utility/SpaceCraftGameInstance.h"
#include "Data/FuelComponentDataRow.h"
#include "Data/BatteryComponentDataRow.h"
#include "Data/EngineComponentDataRow.h"
#include "Data/LifeSupportComponentDataRow.h"
#include "Data/ReactorComponentDataRow.h"
#include "Data/SensorComponentDataRow.h"
#include "Data/ShieldComponentDataRow.h"
#include "Data/SpaceCraftDataRow.h"

struct FFuelComponentDataRow;
struct FEngineComponentDataRow;

USpaceCraftDefinitionData* USpaceCraftGameInstance::GetSpaceCraftDefinitionData(FName ShipName)
{
	FString Context;
	if (const FSpaceCraftDataRow * Row = CraftDefinitions->FindRow<FSpaceCraftDataRow>(ShipName, Context))
	{
		return Row->MakeSpaceCraftDefinitionData(this);
	}
	return nullptr;
}

UBatteryDefinitionData* USpaceCraftGameInstance::GetBatteryDefinitionData(FName ShipName)
{
	FString Context;
	if (FBatteryComponentDataRow * Row = BatteryDefinitions->FindRow<FBatteryComponentDataRow>(ShipName, Context))
	{
		return Row->MakeBatteryDefinitionData();
	}
	return nullptr;
}

UEngineDefinitionData* USpaceCraftGameInstance::GetEngineDefinitionData(FName ComponentName)
{
	FString Context;
	if (FEngineComponentDataRow * Row = EngineDefinitions->FindRow<FEngineComponentDataRow>(ComponentName, Context))
	{
		return Row->MakeEngineDefinitionData();
	}
	return nullptr;
}

UFuelDefinitionData* USpaceCraftGameInstance::GetFuelDefinitionData(FName ComponentName) const
{
	FString Context;
	if (FFuelComponentDataRow * Row = FuelDefinitions->FindRow<FFuelComponentDataRow>(ComponentName, Context))
	{
		return Row->MakeFuelDefinitionData();
	}
	return nullptr;
}

UShieldDefinitionData* USpaceCraftGameInstance::GetShieldDefinitionData(FName ComponentName) const
{
	FString Context;
	if (FShieldComponentDataRow * Row = ShieldDefinitions->FindRow<FShieldComponentDataRow>(ComponentName, Context))
	{
		return Row->MakeShieldDefinitionData();
	}
	return nullptr;
}

UReactorDefinitionData* USpaceCraftGameInstance::GetReactorDefinitionData(FName ComponentName) const
{
	FString Context;
	if (FReactorComponentDataRow * Row = ReactorDefinitions->FindRow<FReactorComponentDataRow>(ComponentName, Context))
	{
		return Row->MakeReactorDefinitionData();
	}
	return nullptr;
}

USensorDefinitionData* USpaceCraftGameInstance::GetSensorDefinitionData(FName ComponentName) const
{
	FString Context;
	if (FSensorComponentDataRow * Row = SensorDefinitions->FindRow<FSensorComponentDataRow>(ComponentName, Context))
	{
		return Row->MakeSensorDefinitionData();
	}
	return nullptr;
}

ULifeSupportDefinitionData* USpaceCraftGameInstance::GetLifeSupportDefinitionData(FName ComponentName) const
{
	FString Context;
	if (FLifeSupportComponentDataRow * Row = SensorDefinitions->FindRow<FLifeSupportComponentDataRow>(ComponentName, Context))
	{
		return Row->MakeLifeSupportDefinitionData();
	}
	return nullptr;
}
