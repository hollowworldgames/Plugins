// Copyright (c) 2024 Hollow World Games llc All Rights Reserved


#include "Utility/XRGameMode.h"
#include "Utility/XRUtilityStatics.h"

UClass* AXRGameMode::GetDefaultPawnClassForController_Implementation(AController* InController)
{
	if (UXRUtilityStatics::IsXRRunning())
	{
		return PlayerXRPawn;
	}
	return Super::GetDefaultPawnClassForController_Implementation(InController);
}
