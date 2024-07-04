// Copyright (c) 2024 Hollow World Games llc All Rights Reserved.


#include "Definitions/Engines/JetEngineDefinition.h"

#include "UtilityStatics.h"

void UJetEngineDefinition::TickEngine(float DeltaTime, float Airpressure, float Airspeed)
{
	Super::TickEngine(DeltaTime, Airpressure, Airspeed);

	//update RPM
	switch(State)
	{
	case EEngineState::Running :
		{
			//compress air
			Airpressure = Compression.GetValueAtLevel(Airspeed) * Airpressure;
			if(Fuel > 0)
			{
				//TODO : This should be more sophisticated
				float TargetRPM = (Fuel / MaxFuel) * (Airpressure / MaxPressure) * MaxRPM + IdleRPM;
				RPM = UUtilityStatics::MoveTowardTargetValue(RPM, TargetRPM, RPMGain, DeltaTime, IdleRPM, MaxRPM);
				float NormalRPM = (RPM - IdleRPM) / (MaxRPM - IdleRPM);
				Force = ThrustFromRPM.GetValueAtLevel(NormalRPM);
				//Compute FTIT Here
				Temperature = TemperatureFromRPM.GetValueAtLevel(NormalRPM);
			}
			else
			{
				State = EEngineState::Stopping;
			}
			break;
		}
	case EEngineState::Starting :
		{
			RPM = UUtilityStatics::MoveTowardTargetValue(RPM,StartRPM, RPMGain,DeltaTime, 0, StartRPM);
			if(RPM == StartRPM && Fuel > 0)
			{
				State = EEngineState::Running;
			}
			break;
		}
	case EEngineState::Off :
	case EEngineState::Stopping :
		{
			RPM = UUtilityStatics::MoveTowardTargetValue(RPM,0, RPMGain,DeltaTime, 0, MaxRPM);
			Temperature = UUtilityStatics::MoveTowardTargetValue(Temperature, 0, 10, DeltaTime, 0, Temperature);
			if(RPM == 0 && State == EEngineState::Stopping)
			{
				State = EEngineState::Off;
			}
			break;
		}
	}
}
