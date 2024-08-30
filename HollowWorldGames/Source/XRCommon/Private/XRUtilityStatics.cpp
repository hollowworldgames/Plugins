// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "XRUtilityStatics.h"

#include "IXRTrackingSystem.h"

bool UXRUtilityStatics::IsXRRunning()
{
	if (GEngine->XRSystem && GEngine->XRSystem->GetHMDDevice()) //check pointer is valid
	{
		if (GEngine->XRSystem->IsHeadTrackingAllowed()) //check stereo enabled
		{
			return true;
		}
	}
	return false;
}
