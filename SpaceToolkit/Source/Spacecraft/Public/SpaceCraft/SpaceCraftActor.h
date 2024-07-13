// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AbilitySystemInterface.h"
#include "Interface/SpaceCraftInterface.h"
#include "SpaceCraftActor.generated.h"

class USpaceCraftAttributes;
class UFTLComponent;
class UNavigationSystemComponent;
class UTacticalSystemComponent;
class USpaceFlightModelComponent;


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FToggle);

UCLASS()
class SPACECRAFT_API ASpaceCraftActor : public AActor, public IAbilitySystemInterface, public ISpaceCraftInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpaceCraftActor();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual UAbilitySystemComponent * GetAbilitySystemComponent() const override;
	virtual void ToggleGear() override;
	virtual void TogglePower() override;
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
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FToggle OnGearToggle;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FToggle OnPowerToggle;
};
