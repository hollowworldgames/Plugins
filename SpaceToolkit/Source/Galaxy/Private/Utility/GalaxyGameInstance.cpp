// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "Utility/GalaxyGameInstance.h"

#include "Data/SolarSystem.h"

ULocation* UGalaxyGameInstance::GetLocation() const
{
	if(ensure(GalaxyAsset))
	{
		USolarSystem * SolarSystem = GalaxyAsset->GetSystem(CurrentLcoation);
		if(ensure(SolarSystem))
		{
			return SolarSystem->GetLocation(CurrentLcoation);
		}
	}
	return nullptr;
}

USolarSystem* UGalaxyGameInstance::GetCurrentSolarSystem() const
{
	if(ensure(GalaxyAsset))
	{
		return GalaxyAsset->GetSystem(CurrentLcoation);
	}
	return nullptr;
}
