// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameplayWeaponInterface.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UGameplayWeaponInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GAMEPLAY_API IGameplayWeaponInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual float GetMinDamage() = 0;
	virtual float GetMaxDamage() = 0;
	virtual float ComputeFalloff(double Distance, float Damage) = 0;
};
