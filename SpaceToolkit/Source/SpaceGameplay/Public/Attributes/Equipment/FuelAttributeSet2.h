// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeMacros.h"
#include "ReactorAttributeSet.h"
#include "Attributes/AttributeSetBase.h"
#include "FuelAttributeSet2.generated.h"



UCLASS()
class SPACEGAMEPLAY_API UFuelAttributeSet2 : public UAttributeSetBase
{
	GENERATED_BODY()
public :
	ATTRIBUTE_ACCESSORS(UFuelAttributeSet2, Fuel);
	ATTRIBUTE_TAG_ACCESSOR(UFuelAttributeSet, Fuel);
	ATTRIBUTE_ACCESSORS(UFuelAttributeSet2, MaxFuel);
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
