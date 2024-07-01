// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CharacterStatics.generated.h"

/**
 * 
 */
UCLASS()
class COMMON_API UCharacterStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public :
	//FPS Movement Functions
	UFUNCTION(BlueprintCallable, Category="FPS Character Movement")
	static void MovePawn(const FVector2D MovementVector, APawn * MyPawn, APlayerController * MyController);
	UFUNCTION(BlueprintCallable, Category="FPS Character Movement")
	static void TurnPawn(const FVector2D LookAxisVector, APawn * MyPawn);
	UFUNCTION(BlueprintCallable, Category="FPS Character Movement")
	static void StartJump(APawn * MyPawn);
	UFUNCTION(BlueprintCallable, Category="FPS Character Movement")
	static void StopJump(APawn * MyPawn);
	//Top Down Movement Functions
};
