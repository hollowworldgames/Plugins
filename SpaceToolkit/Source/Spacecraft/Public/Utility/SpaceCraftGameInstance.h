// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Actors/Systems/LifeSupportActor.h"
#include "Data/SpaceCraftDataRow.h"
#include "Settings/SettingsGameInstance.h"
#include "SpaceCraftGameInstance.generated.h"


class USensorDefinitionData;
class UReactorDefinitionData;
class UShieldDefinitionData;
class UFuelDefinitionData;
class UEngineDefinitionData;
class UBatteryDefinitionData;
class USpaceCraftDefinitionData;

UCLASS()
class SPACECRAFT_API USpaceCraftGameInstance : public USettingsGameInstance
{
	GENERATED_BODY()
public :
	UFUNCTION(BlueprintCallable)
	USpaceCraftDefinitionData * GetSpaceCraftDefinitionData(FName ShipName);
	UFUNCTION(BlueprintCallable)
	UBatteryDefinitionData * GetBatteryDefinitionData(FName ComponentName);
	UFUNCTION(BlueprintCallable)
	UEngineDefinitionData * GetEngineDefinitionData(FName ComponentName);
	UFUNCTION(BlueprintCallable)
	UFuelDefinitionData * GetFuelDefinitionData(FName ComponentName) const;
	UFUNCTION(BlueprintCallable)
	UShieldDefinitionData * GetShieldDefinitionData(FName ComponentName) const;
	UFUNCTION(BlueprintCallable)
	UReactorDefinitionData * GetReactorDefinitionData(FName ComponentName) const;
	UFUNCTION(BlueprintCallable)
	USensorDefinitionData * GetSensorDefinitionData(FName ComponentName) const;
	UFUNCTION(BlueprintCallable)
	ULifeSupportDefinitionData * GetLifeSupportDefinitionData(FName ComponentName) const;
protected :
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spacecraft")
	TObjectPtr<UDataTable> CraftDefinitions;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UDataTable> ReactorDefinitions;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UDataTable> BatteryDefinitions;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UDataTable> LiftSupportDefinitions;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UDataTable> SensorDefinitions;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UDataTable> EngineDefinitions;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UDataTable> ShieldDefinitions;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UDataTable> FuelDefinitions;
};
