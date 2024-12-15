// Copyright (c) 2024 Hollow World Games llc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SpaceCraftDataAsset.generated.h"


class UBatteryDefinitionData;
class UReactorDefinitionData;
class UEngineDefinitionData;
class UShieldDefinitionData;
class USensorDefinitionData;
class ULifeSupportDefinitionData;
class UFuelDefinitionData;

class USpaceCraftDefinitionData;

UCLASS()
class SPACECRAFT_API USpaceCraftDataAsset : public UDataAsset
{
	GENERATED_BODY()
public :
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spacecraft Data")
	FName Name;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(ClampMax="5", ClampMin="1", UIMin = "1", UIMax = "5", Delta = "1"), Category="Spacecraft Data")
	float Level = 1;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Spacecraft Data")
	TSubclassOf<class ASpaceCraftActor> ActorClass;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Meta = (GetOptions="GetReactorChoices"), Category="Spacecraft Data")
	FName Reactor;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Meta = (GetOptions="GetBatteryChoices"), Category="Spacecraft Data")
	FName Battery;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Meta = (GetOptions="GetLifeSupportChoices"), Category="Spacecraft Data")
	FName LifeSupport;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Meta = (GetOptions="GetFuelChoices"), Category="Spacecraft Data")
	FName FuelTank;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Meta = (GetOptions="GetEngineChoices"), Category="Spacecraft Data")
	FName Engine;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Meta = (GetOptions="GetSensorChoices"), Category="Spacecraft Data")
	FName Sensor;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Meta = (GetOptions="GetShieldChoices"), Category="Spacecraft Data")
	FName FrontShield;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Meta = (GetOptions="GetShieldChoices"), Category="Spacecraft Data")
	FName RearShield;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Meta = (GetOptions="GetShieldChoices"), Category="Spacecraft Data")
	FName RightShield;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Meta = (GetOptions="GetShieldChoices"), Category="Spacecraft Data")
	FName LeftShield;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Spacecraft Data")
	TObjectPtr<class UShipComponentsLibrary> Library;
	UFUNCTION(CallInEditor)
	TArray<FName> GetReactorChoices() const;
	UReactorDefinitionData * GetReactorData() const;
	UFUNCTION(CallInEditor)
	TArray<FName> GetBatteryChoices() const;
	UBatteryDefinitionData * GetBatteryData() const;
	UFUNCTION(CallInEditor)
	TArray<FName> GetEngineChoices() const;
	UEngineDefinitionData * GetEngineData() const;
	UFUNCTION(CallInEditor)
	TArray<FName> GetShieldChoices() const;
	UShieldDefinitionData * GetShieldData(FName Shield) const;
	UFUNCTION(CallInEditor)
	TArray<FName> GetSensorChoices() const;
	USensorDefinitionData * GetSensorData() const;
	UFUNCTION(CallInEditor)
	TArray<FName> GetLifeSupportChoices() const;
	ULifeSupportDefinitionData * GetLifeSupportData() const;
	UFUNCTION(CallInEditor)
	TArray<FName> GetFuelChoices() const;
	UFuelDefinitionData * GetFuelData() const;
	USpaceCraftDefinitionData * CreateDefinitionData() const;
};
