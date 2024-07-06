// (c) Copyright 2023 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "SpaceCraft/Stations/UniversalStationPawn.h"
#include "SpaceCraftPawn.generated.h"

class UFTLComponent;
class UNavigationSystemComponent;
class UTacticalSystemComponent;
class USpaceFlightModelComponent;
class USpaceCraftAttributes;

UCLASS()
class SPACECRAFT_API ASpaceCraftPawn : public AUniversalStationPawn, public IAbilitySystemInterface
{
	GENERATED_BODY()
public:	
	// Sets default values for this actor's properties
	ASpaceCraftPawn();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual UAbilitySystemComponent * GetAbilitySystemComponent() const override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
	TObjectPtr<USpaceFlightModelComponent> SpaceFlightModelComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
	TObjectPtr<UTacticalSystemComponent> TacticalSystemComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
	TObjectPtr<UNavigationSystemComponent> NavigationSystemComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
	TObjectPtr<UFTLComponent> FTLComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
	TObjectPtr<USpaceCraftAttributes> Attributes;
};
