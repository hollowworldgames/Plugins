// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "USpaceCraftDefinitionData.generated.h"

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
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<ASpaceCraftActor> CraftClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UBatteryDefinitionData> BatteryData;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UReactorDefinitionData> ReactorData;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UEngineDefinitionData> EngineData;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UShieldDefinitionData> FrontShieldData;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UShieldDefinitionData> RearShieldData;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UShieldDefinitionData> RightShieldData;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UShieldDefinitionData> LeftShieldData;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UFuelDefinitionData> FuelData;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<USensorDefinitionData> SensorData;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<ULifeSupportDefinitionData> LifeSupportData;
};
