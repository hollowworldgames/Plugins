﻿// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "AttributeSetBase.h"
#include "ScalableFloat.h"
#include "ExperienceAttributeSet.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FExperienceLevelChange, float , NewLevel);
GAMEPLAY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ExperienceTag);

UCLASS()
class GAMEPLAY_API UExperienceAttributeSet : public UAttributeSetBase
{
	GENERATED_BODY()
public :
	ATTRIBUTE_ACCESSORS(UExperienceAttributeSet, Experience);
	ATTRIBUTE_ACCESSORS(UExperienceAttributeSet, IncomingExperience);
	virtual float GetAttributeValue(FGameplayTag AttributeTag) override;
	virtual void SetAttributeValue(FGameplayTag Attribute, float Value) override;
	virtual FGameplayTag GetAttributeTag(FGameplayAttribute Attribute) override;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category = "Events")
	FExperienceLevelChange OnLevelChanged;
protected :
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Level)
	FScalableFloat LevelFromXP;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Experience, Category=Experience)
	FGameplayAttributeData Experience;
	UFUNCTION()
	void OnRep_Experience(const FGameplayAttributeData& OldExperience) const;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Experience)
	FGameplayAttributeData IncomingExperience;
};