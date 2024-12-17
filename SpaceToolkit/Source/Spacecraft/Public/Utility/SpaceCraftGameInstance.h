// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Actors/Systems/LifeSupportActor.h"
#include "Data/SpaceCraftDataRow.h"
#include "Settings/SettingsGameInstance.h"
#include "Utility/GalaxyGameInstance.h"
#include "SpaceCraftGameInstance.generated.h"


class USensorDefinitionData;
class UReactorDefinitionData;
class UShieldDefinitionData;
class UFuelDefinitionData;
class UEngineDefinitionData;
class UBatteryDefinitionData;
class UShipComponentsLibrary;
class USpaceCraftDefinitionData;

UCLASS()
class SPACECRAFT_API USpaceCraftGameInstance : public UGalaxyGameInstance
{
	GENERATED_BODY()
public :
	UFUNCTION(BlueprintCallable, Category = "Spacecraft GameInstance")
	USpaceCraftDefinitionData * GetSpaceCraftDefinitionData(FName ShipName);
	UFUNCTION(BlueprintCallable, Category = "Spacecraft GameInstance")
	UBatteryDefinitionData * GetBatteryDefinitionData(FName ComponentName);
	UFUNCTION(BlueprintCallable, Category = "Spacecraft GameInstance")
	UEngineDefinitionData * GetEngineDefinitionData(FName ComponentName);
	UFUNCTION(BlueprintCallable, Category = "Spacecraft GameInstance")
	UFuelDefinitionData * GetFuelDefinitionData(FName ComponentName) const;
	UFUNCTION(BlueprintCallable, Category = "Spacecraft GameInstance")
	UShieldDefinitionData * GetShieldDefinitionData(FName ComponentName) const;
	UFUNCTION(BlueprintCallable, Category = "Spacecraft GameInstance")
	UReactorDefinitionData * GetReactorDefinitionData(FName ComponentName) const;
	UFUNCTION(BlueprintCallable, Category = "Spacecraft GameInstance")
	USensorDefinitionData * GetSensorDefinitionData(FName ComponentName) const;
	UFUNCTION(BlueprintCallable, Category = "Spacecraft GameInstance")
	ULifeSupportDefinitionData * GetLifeSupportDefinitionData(FName ComponentName) const;
protected :
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spacecraft")
	TObjectPtr<UDataTable> CraftDefinitions;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UShipComponentsLibrary> ComponentLibrary;
};
