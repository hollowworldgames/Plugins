// Copyright (c) 2024 Hollow World Games llc. All Rights Reserved.


#include "Data/SpaceCraftDataAsset.h"

#include "Data/BatteryComponentDataRow.h"
#include "Data/EngineComponentDataRow.h"
#include "Data/FuelComponentDataRow.h"
#include "Data/LifeSupportComponentDataRow.h"
#include "Data/ReactorComponentDataRow.h"
#include "Data/SensorComponentDataRow.h"
#include "Data/ShieldComponentDataRow.h"
#include "Data/ShipComponentsLibrary.h"
#include "Data/SpaceCraftDefinitionData.h"


TArray<FName> USpaceCraftDataAsset::GetReactorChoices() const
{
	if(Library && Library->ReactorDefinitions)
	{
		return Library->ReactorDefinitions->GetRowNames();	
	}
	return TArray<FName>();
}

UReactorDefinitionData* USpaceCraftDataAsset::GetReactorData() const
{
	if(Library && Library->ReactorDefinitions)
	{
		FString Context;
		FReactorComponentDataRow * Row = Library->ReactorDefinitions->FindRow<FReactorComponentDataRow>(Battery, Context);
		if(Row)
		{
			return Row->MakeReactorDefinitionData();
		}
	}
	return nullptr;
}

UBatteryDefinitionData* USpaceCraftDataAsset::GetBatteryData() const
{
	if(Library && Library->BatteryDefinitions)
	{
		FString Context;
		FBatteryComponentDataRow * Row = Library->BatteryDefinitions->FindRow<FBatteryComponentDataRow>(Battery, Context);
		if(Row)
		{
			return Row->MakeBatteryDefinitionData();
		}
	}
	return nullptr;
}

UEngineDefinitionData* USpaceCraftDataAsset::GetEngineData() const
{
	if(Library && Library->EngineDefinitions)
	{
		FString Context;
		FEngineComponentDataRow * Row = Library->EngineDefinitions->FindRow<FEngineComponentDataRow>(Battery, Context);
		if(Row)
		{
			return Row->MakeEngineDefinitionData();
		}
	}
	return nullptr;
}

TArray<FName> USpaceCraftDataAsset::GetBatteryChoices() const
{
	if(Library && Library->BatteryDefinitions)
	{
		return Library->BatteryDefinitions->GetRowNames();	
	}
	return TArray<FName>();
}

TArray<FName> USpaceCraftDataAsset::GetEngineChoices() const
{
	if(Library && Library->EngineDefinitions)
	{
		return Library->EngineDefinitions->GetRowNames();	
	}
	return TArray<FName>();
}

TArray<FName> USpaceCraftDataAsset::GetShieldChoices() const
{
	if(Library && Library->ShieldDefinitions)
	{
		return Library->ShieldDefinitions->GetRowNames();	
	}
	return TArray<FName>();
}

UShieldDefinitionData* USpaceCraftDataAsset::GetShieldData(FName Shield) const
{
	if(Library && Library->ShieldDefinitions)
	{
		FString Context;
		if(FShieldComponentDataRow * Row = Library->ShieldDefinitions->FindRow<FShieldComponentDataRow>(Shield, Context))
		{
			return Row->MakeShieldDefinitionData();
		}
	}
	return nullptr;
}

TArray<FName> USpaceCraftDataAsset::GetSensorChoices() const
{
	if(Library && Library->SensorDefinitions)
	{
		return Library->SensorDefinitions->GetRowNames();	
	}
	return TArray<FName>();
}

USensorDefinitionData* USpaceCraftDataAsset::GetSensorData() const
{
	if(Library && Library->SensorDefinitions)
	{
		FString Context;
		if(FSensorComponentDataRow * Row = Library->SensorDefinitions->FindRow<FSensorComponentDataRow>(Sensor, Context))
		{
			return Row->MakeSensorDefinitionData();
		}
	}
	return nullptr;
}

TArray<FName> USpaceCraftDataAsset::GetLifeSupportChoices() const
{
	if(Library && Library->LifeSupportDefinitions)
	{
		return Library->LifeSupportDefinitions->GetRowNames();	
	}
	return TArray<FName>();
}

ULifeSupportDefinitionData* USpaceCraftDataAsset::GetLifeSupportData() const
{
	if(Library && Library->LifeSupportDefinitions)
	{
		FString Context;
		if(FLifeSupportComponentDataRow * Row = Library->LifeSupportDefinitions->FindRow<FLifeSupportComponentDataRow>(Sensor, Context))
		{
			return Row->MakeLifeSupportDefinitionData();
		}
	}
	return nullptr;
}

TArray<FName> USpaceCraftDataAsset::GetFuelChoices() const
{
	if(Library && Library->FuelDefinitions)
	{
		return Library->FuelDefinitions->GetRowNames();	
	}
	return TArray<FName>();
}

UFuelDefinitionData* USpaceCraftDataAsset::GetFuelData() const
{
	if(Library && Library->SensorDefinitions)
	{
		FString Context;
		if(FFuelComponentDataRow * Row = Library->SensorDefinitions->FindRow<FFuelComponentDataRow>(Sensor, Context))
		{
			return Row->MakeFuelDefinitionData();
		}
	}
	return nullptr;
}

USpaceCraftDefinitionData* USpaceCraftDataAsset::CreateDefinitionData() const
{
	USpaceCraftDefinitionData * SpaceCraftDefinitionData = NewObject<USpaceCraftDefinitionData>();
 	if (ensure(SpaceCraftDefinitionData))
 	{
 		SpaceCraftDefinitionData->BatteryData = GetBatteryData();
 		SpaceCraftDefinitionData->CraftClass = ActorClass;
 		SpaceCraftDefinitionData->EngineData = GetEngineData();
 		SpaceCraftDefinitionData->FuelData = GetFuelData();
 		SpaceCraftDefinitionData->ReactorData = GetReactorData();
 		SpaceCraftDefinitionData->SensorData = GetSensorData();
 		SpaceCraftDefinitionData->FrontShieldData = GetShieldData(FrontShield);
 		SpaceCraftDefinitionData->RearShieldData = GetShieldData(RearShield);
 		SpaceCraftDefinitionData->LeftShieldData = GetShieldData(LeftShield);
 		SpaceCraftDefinitionData->RightShieldData = GetShieldData(RightShield);
 		SpaceCraftDefinitionData->LifeSupportData = GetLifeSupportData();
 	}
 	return SpaceCraftDefinitionData;
}
