// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SpaceCraftDataRow.generated.h"

class USpaceCraftGameInstance;
class ASpaceCraftActor;
class USpaceCraftDefinitionData;
class UShipComponentsLibrary;

USTRUCT()
struct SPACECRAFT_API FSpaceCraftDataRow : public FTableRowBase
{
	GENERATED_BODY()
public :
	USpaceCraftDefinitionData* MakeSpaceCraftDefinitionData(USpaceCraftGameInstance * Instance) const;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FString Name;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float Level;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<ASpaceCraftActor> ActorClass;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName Reactor;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName Battery;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName LifeSupport;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName FuelTank;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName Engine;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName Sensor;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName FrontShield;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName RearShield;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName RightShield;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName LeftShield;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UShipComponentsLibrary> Library;
};
