// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeMacros.h"
#include "ReactorAttributeSet.h"
#include "Attributes/AttributeSetBase.h"
#include "FuelAttributeSet.generated.h"

SPACEGAMEPLAY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(FuelTag);
SPACEGAMEPLAY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(MaxFuelTag);
SPACEGAMEPLAY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(FuelOnTag);

UCLASS()
class SPACEGAMEPLAY_API UFuelAttributeSet : public UAttributeSetBase
{
	GENERATED_BODY()
public :
	ATTRIBUTE_ACCESSORS(UFuelAttributeSet, Fuel);
	ATTRIBUTE_TAG_ACCESSOR(UFuelAttributeSet, Fuel);
	ATTRIBUTE_ACCESSORS(UFuelAttributeSet, MaxFuel);
	ATTRIBUTE_TAG_ACCESSOR(UFuelAttributeSet, MaxFuel);
protected :
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Fuel, Category=Reactor)
	FGameplayAttributeData Fuel;
	UFUNCTION()
	void OnRep_Fuel(const FGameplayAttributeData& OldFuel) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_MaxFuel, Category=Reactor)
	FGameplayAttributeData MaxFuel;
	UFUNCTION()
	void OnRep_MaxFuel(const FGameplayAttributeData& OldMaxFuel) const;
};
