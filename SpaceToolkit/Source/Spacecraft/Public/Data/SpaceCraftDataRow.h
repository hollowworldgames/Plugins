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
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Settings)
	FString Name;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Settings)
	float Level;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Settings)
	TSubclassOf<ASpaceCraftActor> ActorClass;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Components)
	FName Reactor;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Components)
	FName Battery;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Components)
	FName LifeSupport;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Components)
	FName FuelTank;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Components)
	FName Engine;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Components)
	FName Sensor;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Components)
	FName FrontShield;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Components)
	FName RearShield;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Components)
	FName RightShield;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Components)
	FName LeftShield;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Components)
	TObjectPtr<UShipComponentsLibrary> Library;
};
