// Copyright (c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PhysicStatics.generated.h"

/**
 * 
 */
UCLASS()
class COMMON_API UPhysicStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public :
	static FVector GetRotationFromForce(FVector Location, FVector Center, FVector Force); 
};
