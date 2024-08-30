// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "XRUtilityStatics.generated.h"

/**
 * 
 */
UCLASS()
class XRCOMMON_API UXRUtilityStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public :
	UFUNCTION(BlueprintPure)
	static bool IsXRRunning();
};
