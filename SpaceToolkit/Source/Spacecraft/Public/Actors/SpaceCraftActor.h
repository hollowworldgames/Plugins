// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AbilitySystemInterface.h"
#include "Actors/ViewableActor.h"
#include "Interface/SpaceCraftInterface.h"
#include "SpaceCraftActor.generated.h"

class UShipSystemComponent;
class UVitalAttributeSet;
class USpaceCraftAttributes;
class UFTLComponent;
class UNavigationSystemComponent;
class UTacticalSystemComponent;
class USpaceFlightModelComponent;


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FToggle);

UCLASS()
class SPACECRAFT_API ASpaceCraftActor : public AViewableActor, public IAbilitySystemInterface, public ISpaceCraftInterface
{
	GENERATED_BODY()
public:	
	// Sets default values for this actor's properties
	ASpaceCraftActor();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual UAbilitySystemComponent * GetAbilitySystemComponent() const override;
	virtual void ToggleGear() override;
	virtual void LowerGear() override;
	virtual void RaiseGear() override;
	virtual EGearState GetGearState() override;
	virtual void TogglePower() override;
	virtual void SetPower(bool On) override;
	virtual bool GetPower() override;
	virtual void ToggleEngines() override;
	virtual void SetEngines(bool On) override;
	virtual bool GetEngines() override;
	virtual void ToggleShields() override;
	virtual void SetShields(bool On) override;
	virtual bool GetShields() override;
	virtual UAbilitySystemComponent * GetSystem(EShipSystem System) override;
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
	TObjectPtr<UVitalAttributeSet> VitalAttributes;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
	TObjectPtr<UShipSystemComponent> Reactor;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
	TObjectPtr<UShipSystemComponent> Battery;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
	TObjectPtr<UShipSystemComponent> Shield;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
	TObjectPtr<UShipSystemComponent> Engine;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
	TObjectPtr<UShipSystemComponent> Fuel;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
	TObjectPtr<UShipSystemComponent> Sensor;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
	TObjectPtr<UShipSystemComponent> LifeSupport;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FToggle OnGearToggle;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FToggle OnPowerToggle;
	UFUNCTION(BlueprintNativeEvent)
	void OnDead();
};
