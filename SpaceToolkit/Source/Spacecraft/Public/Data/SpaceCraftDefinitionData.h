// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SpaceCraftDefinitionData.generated.h"

class UReactorDefinitionData;
class UEngineDefinitionData;
class UShieldDefinitionData;
class UFuelDefinitionData;
class USensorDefinitionData;
class UBatteryDefinitionData;
class ULifeSupportDefinitionData;
class ASpaceCraftActor;

UCLASS()
class SPACECRAFT_API USpaceCraftDefinitionData : public UObject
{
	GENERATED_BODY()
public :
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spacecraft")
	FName Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spacecraft")
	TSubclassOf<ASpaceCraftActor> CraftClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UBatteryDefinitionData> BatteryData;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UReactorDefinitionData> ReactorData;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UEngineDefinitionData> EngineData;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UShieldDefinitionData> FrontShieldData;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UShieldDefinitionData> RearShieldData;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UShieldDefinitionData> RightShieldData;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UShieldDefinitionData> LeftShieldData;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UFuelDefinitionData> FuelData;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USensorDefinitionData> SensorData;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<ULifeSupportDefinitionData> LifeSupportData;
	
};
