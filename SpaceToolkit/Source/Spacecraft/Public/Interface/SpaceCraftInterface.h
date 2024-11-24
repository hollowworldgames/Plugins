// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SpaceCraftInterface.generated.h"

class UAbilitySystemComponent;
// This class does not need to be modified.
UINTERFACE()
class USpaceCraftInterface : public UInterface
{
	GENERATED_BODY()
};

UENUM(BlueprintType)
enum class EGearState : uint8
{
	Raised UMETA(DisplayName = "Raised"),
	Raising UMETA(DisplayName = "Raising"),
	Lowered UMETA(DisplayName = "Lowered"),
	Lowering UMETA(DisplayName = "Lowering"),
};

UENUM(BlueprintType)
enum class EShipSystem : uint8
{
	Reactor UMETA(DisplayName = "Reactor"),
	Engine UMETA(DisplayName = "Engine"),
	Shield UMETA(DisplayName = "Shield"),
	Battery UMETA(DisplayName = "Battery"),
	Fuel UMETA(DisplayName = "Fuel"),
	Sensor UMETA(DisplayName = "Sensor"),
};

class SPACECRAFT_API ISpaceCraftInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void ToggleGear() = 0;
	virtual void LowerGear() = 0;
	virtual void RaiseGear() = 0;
	virtual EGearState GetGearState() = 0;
	virtual void TogglePower() = 0;
	virtual void SetPower(bool On) = 0;
	virtual bool GetPower() = 0;
	virtual void ToggleEngines() = 0;
	virtual void SetEngines(bool On) = 0;
	virtual bool GetEngines() = 0;
	virtual void ToggleShields() = 0;
	virtual void SetShields(bool On) = 0;
	virtual bool GetShields() = 0;
	virtual UAbilitySystemComponent * GetSystem(EShipSystem System) = 0;
};
