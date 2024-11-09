// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GalaxyAsset.h"
#include "UObject/Object.h"
#include "Star.generated.h"

/**
 * 
 */
UCLASS()
class GALAXY_API UStar : public UObject
{
	GENERATED_BODY()
public :
	void Generate(const FSystemId& SystemId, UGalaxyAsset * Asset, double NewRadius, int NewRing);
	double GetSize() const { return Size; }
	int GetRing() const { return Ring; }
	double GetRadius() const { return Radius; }
	FSystemId GetSystemId() const { return Id; }
protected :
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Settings)
	FSystemId Id;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Settings)
	float Temperature;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Settings)
	double Size;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Settings)
	int Ring;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Settings)
	double Radius;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generator Settings")
	double MinStarSize = 1000000000;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generator Settings")
	double MaxStarSize = 30000000000;
};
