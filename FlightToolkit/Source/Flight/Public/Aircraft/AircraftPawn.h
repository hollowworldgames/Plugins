// Copyright (c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Stations/UniversalStationPawn.h"
#include "AircraftPawn.generated.h"

class UFireControlComponent;
class UPowerSystemComponent;
class UFuelSystemComponent;
class UFlightModelComponent;



UCLASS()
class FLIGHT_API AAircraftPawn : public AUniversalStationPawn
{
	GENERATED_BODY()
public:
	// Sets default values for this pawn's properties
	AAircraftPawn();
// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
	TObjectPtr<UFlightModelComponent> FlightModelComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
	TObjectPtr<UFuelSystemComponent> FuelSystemComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
	TObjectPtr<UPowerSystemComponent> PowerSystemComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
	TObjectPtr<UFireControlComponent> FireControlComponent;
};
