// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Attributes/AttributeSetBase.h"
#include "Attributes/ExperienceAttributeSet.h"
#include "Attributes/SkillAttributeSet.h"
#include "SciFiSkillsAttributeSet.generated.h"

SCIFICHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ArmorUseTag);
SCIFICHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ArmorUseExperienceTag);
SCIFICHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(PistolsTag);
SCIFICHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(PistolsExperienceTag);
SCIFICHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(RiflesTag);
SCIFICHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(RiflesExperienceTag);
SCIFICHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(PersonalShieldsTag);
SCIFICHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(PersonalShieldsExperienceTag);

UCLASS()
class SCIFICHARACTER_API USciFiSkillsAttributeSet : public USkillAttributeSet
{
	GENERATED_BODY()
public :
	ATTRIBUTE_ACCESSORS(USciFiSkillsAttributeSet, ArmorUse);
	ATTRIBUTE_ACCESSORS(USciFiSkillsAttributeSet, ArmorUseExperience);
	ATTRIBUTE_ACCESSORS(USciFiSkillsAttributeSet, IncomingArmorUseExperience);
	ATTRIBUTE_ACCESSORS(USciFiSkillsAttributeSet, Pistols);
	ATTRIBUTE_ACCESSORS(USciFiSkillsAttributeSet, PistolsExperience);
	ATTRIBUTE_ACCESSORS(USciFiSkillsAttributeSet, IncomingPistolsExperience);
	ATTRIBUTE_ACCESSORS(USciFiSkillsAttributeSet, Rifles);
	ATTRIBUTE_ACCESSORS(USciFiSkillsAttributeSet, RiflesExperience);
	ATTRIBUTE_ACCESSORS(USciFiSkillsAttributeSet, IncomingRiflesExperience);
	ATTRIBUTE_ACCESSORS(USciFiSkillsAttributeSet, PersonalShields);
	ATTRIBUTE_ACCESSORS(USciFiSkillsAttributeSet, PersonalShieldsExperience);
	ATTRIBUTE_ACCESSORS(USciFiSkillsAttributeSet, IncomingPersonalShieldsExperience);
	
	virtual float GetAttributeValue(FGameplayTag AttributeTag) override;
	virtual void SetAttributeValue(FGameplayTag Attribute, float Value) override;
	virtual FGameplayTag GetAttributeTag(FGameplayAttribute Attribute) override;
protected :
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	//Ground Skills
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ArmorUse, Category = "Ground Combat")
	FGameplayAttributeData ArmorUse;
	UFUNCTION()
	void OnRep_ArmorUse(const FGameplayAttributeData& OldArmorUse) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ArmorUseExperience, Category = "Ground Combat")
	FGameplayAttributeData ArmorUseExperience;
	UFUNCTION()
	void OnRep_ArmorUseExperience(const FGameplayAttributeData& OldArmorUseExperience) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ground Combat")
	FGameplayAttributeData IncomingArmorUseExperience;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ground Combat")
	FScalableFloat ArmorUseCurve;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Pistols, Category = "Ground Combat")
	FGameplayAttributeData Pistols;
	UFUNCTION()
	void OnRep_Pistols(const FGameplayAttributeData& OldPistols) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_PistolsExperience, Category = "Ground Combat")
	FGameplayAttributeData PistolsExperience;
	UFUNCTION()
	void OnRep_PistolsExperience(const FGameplayAttributeData& OldPistolsExperience) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ground Combat")
	FGameplayAttributeData IncomingPistolsExperience;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ground Combat")
	FScalableFloat PistolsCurve;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Rifles, Category = "Ground Combat")
	FGameplayAttributeData Rifles;
	UFUNCTION()
	void OnRep_Rifles(const FGameplayAttributeData& OldRifles) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_RiflesExperience, Category = "Ground Combat")
	FGameplayAttributeData RiflesExperience;
	UFUNCTION()
	void OnRep_RiflesExperience(const FGameplayAttributeData& OldRiflesExperience) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ground Combat")
	FGameplayAttributeData IncomingRiflesExperience;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ground Combat")
	FScalableFloat RiflesCurve;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_PersonalShields, Category = "Ground Combat")
	FGameplayAttributeData PersonalShields;
	UFUNCTION()
	void OnRep_PersonalShields(const FGameplayAttributeData& OldPersonalShields) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_PersonalShieldsExperience, Category = "Ground Combat")
	FGameplayAttributeData PersonalShieldsExperience;
	UFUNCTION()
	void OnRep_PersonalShieldsExperience(const FGameplayAttributeData& OldPersonalShieldsExperience) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ground Combat")
	FGameplayAttributeData IncomingPersonalShieldsExperience;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ground Combat")
	FScalableFloat PersonalShieldsCurve;
};
