// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Data/GalaxyAsset.h"
#include "Data/Location.h"
#include "Settings/SettingsGameInstance.h"
#include "GalaxyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class GALAXY_API UGalaxyGameInstance : public USettingsGameInstance
{
	GENERATED_BODY()
public :
	UFUNCTION(BlueprintPure)
	UGalaxyAsset * GetGalaxyAsset() const { return GalaxyAsset; }
	UFUNCTION(BlueprintPure)
	FSystemId GetCurrentLocation() const { return CurrentLcoation; }
	UFUNCTION(BlueprintCallable)
	void SetCurrentLocation(FSystemId Location) { CurrentLcoation = Location; }
	UFUNCTION(BlueprintPure)
	ULocation* GetLocation() const;
	USolarSystem* GetCurrentSolarSystem() const;

protected :
	UPROPERTY(Transient, BlueprintReadOnly, Category = "Location")
	FSystemId CurrentLcoation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	TObjectPtr<UGalaxyAsset> GalaxyAsset;
};