// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Data/SensorComponentDataRow.h"

#include "Actors/Systems/SensorActor.h"

USensorDefinitionData* FSensorComponentDataRow::MakeSensorDefinitionData() const
{
	USensorDefinitionData * SensorDefinitionData = NewObject<USensorDefinitionData>();
	SensorDefinitionData->Level;
	SensorDefinitionData->SignalResolution = SignalResolution;
	SensorDefinitionData->SignalStrength = SignalStrength;
	return SensorDefinitionData;
}
