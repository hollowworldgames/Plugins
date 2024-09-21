// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SolarSystemAsset.generated.h"

/**
 * 
 */
UCLASS()
class GALAXY_API USolarSystemAsset : public UDataAsset
{
	GENERATED_BODY()
public :
	TObjectPtr<USolarSystem> MakeSystem() const;
protected :
	UPROPERTY()
	TArray<TObjectPtr<ULocation>> Locations;
};
