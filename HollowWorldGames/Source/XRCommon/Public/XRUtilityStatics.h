// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Actors/XRHandActor.h"
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
	UFUNCTION(BlueprintPure, Category="XR Utility")
	static bool IsXRRunning();
	UFUNCTION(BlueprintPure,Meta = (WorldContext = "WorldContext"), Category="XR Utility")
	static AXRHandActor* GetXRHandActor(const UObject * WorldContext, EHand Hand);
	UFUNCTION(BlueprintPure,Meta = (WorldContext = "WorldContext"), Category="XR Utility")
	static UMotionControllerComponent* GetMotionControllerComponent(const UObject * WorldContext, const EHand Hand);
};
