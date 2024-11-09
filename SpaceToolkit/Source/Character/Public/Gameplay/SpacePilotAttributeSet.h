// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeMacros.h"
#include "AttributeSet.h"
#include "GameplayTags.h"
#include "AbilitySystemComponent.h"
#include "SpacePilotAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class CHARACTER_API USpacePilotAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public :
	ATTRIBUTE_ACCESSORS(USpacePilotAttributeSet, GForceTolerance);
	ATTRIBUTE_TAG_ACCESSOR(USpacePilotAttributeSet, GForceTolerance);
	ATTRIBUTE_ACCESSORS(USpacePilotAttributeSet, GForceEndurance);
	ATTRIBUTE_TAG_ACCESSOR(USpacePilotAttributeSet, GForceEndurance);
protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_GForceTolerance, Category=Health)
	FGameplayAttributeData GForceTolerance;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Health)
	FGameplayTag GForceToleranceTag;
	UFUNCTION()
	void OnRep_GForceTolerance(const FGameplayAttributeData& OldGForceTolerance) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_GForceEndurance, Category=Health)
	FGameplayAttributeData GForceEndurance;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Health)
	FGameplayTag GForceEnduranceTag;
	UFUNCTION()
	void OnRep_GForceEndurance(const FGameplayAttributeData& OldGForceEndurance) const;
};
