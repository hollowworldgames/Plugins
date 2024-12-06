// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AbilitySystemInterface.h"
#include "Actors/ViewableActor.h"
#include "Components/GameplayAbilitySystemComponent.h"
#include "Interface/SpaceCraftInterface.h"
#include "Interfaces/ComponentContainerInterface.h"
#include "Interfaces/DamageReportInterface.h"
#include "SpaceCraftActor.generated.h"

class USpaceCombatAttributeSet;
class UGameplayEffect;
class UShipSystemComponent;
class UVitalAttributeSet;
class USpaceCraftAttributes;
class UFTLComponent;
class UNavigationSystemComponent;
class UTacticalSystemComponent;
class USpaceFlightModelComponent;
class UGameplayAbilitySystemComponent;


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FToggle);

USTRUCT(BlueprintType)
struct FInitialComponentEffects
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTag Component;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UGameplayEffect> EffectClass;
};

UCLASS()
class SPACECRAFT_API ASpaceCraftActor : public AViewableActor, public IAbilitySystemInterface,
	public ISpaceCraftInterface, public IComponentContainerInterface, public IDamageReportInterface
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
	virtual void Initialize(USpaceCraftDefinitionData * Craft) override;
	virtual void Initialize(FName Craft) override;
	virtual UGameplayAbilitySystemComponent * GetSystem(FGameplayTag System) const override;
	virtual TArray<FGameplayTag> GetComponentTags() const override;
	virtual void ApplyEffectToComponent(FGameplayTag Component, TSubclassOf<UGameplayEffect> Effect, float Level, const AActor * Source) override;
	virtual void ApplyDamageToComponent(FGameplayTag Component, float Damage, const AActor * Source) override;
	virtual void ReportDamage(const AActor * Source, float EnergyDamage, float KineticDamage, int ShieldFace, EDamageReportType Type) override;
	virtual void ReportDamage(const AActor * Source, float EnergyDamage, float KineticDamage, EDamageReportType Type) override;
	virtual void ReportComponentDamage(const AActor * Source, float EnergyDamage, float KineticDamage,FGameplayTag Component, EDamageReportType Type) override;
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
	TObjectPtr<UGameplayAbilitySystemComponent> AbilitySystemComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
	TObjectPtr<UVitalAttributeSet> VitalAttributes;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attributes)
	TObjectPtr<class USpaceCombatAttributeSet> CombatAttributes;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
	TObjectPtr<UShipSystemComponent> Reactor;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
	TObjectPtr<UShipSystemComponent> Battery;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
	TObjectPtr<UShipSystemComponent> FrontShield;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
	TObjectPtr<UShipSystemComponent> RearShield;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
    TObjectPtr<UShipSystemComponent> RightShield;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
	TObjectPtr<UShipSystemComponent> LeftShield;
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
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=Tags)
	FGameplayTagContainer ComponentTags;
	UPROPERTY()
	TMap<FGameplayTag, TObjectPtr<UShipSystemComponent>> Components;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=Effects)
	TSubclassOf<UGameplayEffect> ComponentDamageEffect;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=Effects)
	TArray<FInitialComponentEffects> InitialEffects;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=Abilities)
	TArray<FAbilityData> InitialAbilities;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Defaults)
	FName DefaultDefinition = NAME_None;
};
