// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Attributes/AttributeSetBase.h"
#include "Attributes/ExperienceAttributeSet.h"
#include "Attributes/SkillAttributeSet.h"
#include "FantasySkillAttributeSet.generated.h"


FANTASYCHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(OneHandedTag);
FANTASYCHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(OneHandedExperienceTag);
FANTASYCHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TwoHandedTag);
FANTASYCHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TwoHandedExperienceTag);
FANTASYCHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ShieldTag);
FANTASYCHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ShieldExperienceTag);
FANTASYCHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ArcheryTag);
FANTASYCHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ArcheryExperienceTag);
FANTASYCHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ArmorUseTag);
FANTASYCHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ArmorUseExperienceTag);

FANTASYCHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(MagicTag);
FANTASYCHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(DestructionTag);
FANTASYCHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(MaxDestructionTag);
FANTASYCHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(RestorationTag);
FANTASYCHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(MaxRestorationTag);
FANTASYCHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(AlterationTag);
FANTASYCHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(MaxAlterationTag);
FANTASYCHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(IllusionTag);
FANTASYCHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(MaxIllusionTag);
FANTASYCHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ConjurationTag);
FANTASYCHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(MaxConjurationTag);

UCLASS()
class FANTASYCHARACTER_API UFantasySkillAttributeSet : public USkillAttributeSet
{
	GENERATED_BODY()
public :
	ATTRIBUTE_ACCESSORS(UFantasySkillAttributeSet, OneHanded)
	ATTRIBUTE_ACCESSORS(UFantasySkillAttributeSet, OneHandedExperience)
	ATTRIBUTE_ACCESSORS(UFantasySkillAttributeSet, IncomingOneHandedExperience)
	ATTRIBUTE_ACCESSORS(UFantasySkillAttributeSet, TwoHanded)
	ATTRIBUTE_ACCESSORS(UFantasySkillAttributeSet, TwoHandedExperience)
	ATTRIBUTE_ACCESSORS(UFantasySkillAttributeSet, IncomingTwoHandedExperience)
	ATTRIBUTE_ACCESSORS(UFantasySkillAttributeSet, Shield)
	ATTRIBUTE_ACCESSORS(UFantasySkillAttributeSet, ShieldExperience)
	ATTRIBUTE_ACCESSORS(UFantasySkillAttributeSet, IncomingShieldExperience)
	ATTRIBUTE_ACCESSORS(UFantasySkillAttributeSet, Archery)
	ATTRIBUTE_ACCESSORS(UFantasySkillAttributeSet, ArcheryExperience)
	ATTRIBUTE_ACCESSORS(UFantasySkillAttributeSet, IncomingArcheryExperience)
	ATTRIBUTE_ACCESSORS(UFantasySkillAttributeSet, ArmorUse)
	ATTRIBUTE_ACCESSORS(UFantasySkillAttributeSet, ArmorUseExperience)
	ATTRIBUTE_ACCESSORS(UFantasySkillAttributeSet, IncomingArmorUseExperience)

	ATTRIBUTE_ACCESSORS(UFantasySkillAttributeSet, Destruction)
	ATTRIBUTE_ACCESSORS(UFantasySkillAttributeSet, DestructionExperience)
	ATTRIBUTE_ACCESSORS(UFantasySkillAttributeSet, Restoration)
	ATTRIBUTE_ACCESSORS(UFantasySkillAttributeSet, RestorationExperience)
	ATTRIBUTE_ACCESSORS(UFantasySkillAttributeSet, Alteration)
	ATTRIBUTE_ACCESSORS(UFantasySkillAttributeSet, AlterationExperience)
	ATTRIBUTE_ACCESSORS(UFantasySkillAttributeSet, Illusion)
	ATTRIBUTE_ACCESSORS(UFantasySkillAttributeSet, IllusionExperience)
	ATTRIBUTE_ACCESSORS(UFantasySkillAttributeSet, Conjuration)
	ATTRIBUTE_ACCESSORS(UFantasySkillAttributeSet, ConjurationExperience);
	
	virtual float GetAttributeValue(FGameplayTag AttributeTag) override;
	virtual void SetAttributeValue(FGameplayTag Attribute, float Value) override;
	virtual FGameplayTag GetAttributeTag(FGameplayAttribute Attribute) override;
protected :
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Vital)
	FGameplayAttributeData IncomingOneHandedExperience;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Vital)
	FGameplayAttributeData IncomingTwoHandedExperience;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Vital)
	FGameplayAttributeData IncomingShieldExperience;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Vital)
	FGameplayAttributeData IncomingArmorUseExperience;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Vital)
	FGameplayAttributeData IncomingArcheryExperience;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_OneHanded, Category=Vital)
	FGameplayAttributeData OneHanded;
	
	UFUNCTION()
	void OnRep_OneHanded(const FGameplayAttributeData& OldOneHanded) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_OneHandedExperience, Category=Vital)
	FGameplayAttributeData OneHandedExperience;
	
	UFUNCTION()
	void OnRep_OneHandedExperience(const FGameplayAttributeData& OldOneHandedExperience) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_TwoHanded, Category=Vital)
	FGameplayAttributeData TwoHanded;
	
	UFUNCTION()
	void OnRep_TwoHanded(const FGameplayAttributeData& OldTwoHanded) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_TwoHandedExperience, Category=Vital)
	FGameplayAttributeData TwoHandedExperience;
	
	UFUNCTION()
	void OnRep_TwoHandedExperience(const FGameplayAttributeData& OldMaxTwoHanded) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Archery, Category=Vital)
	FGameplayAttributeData Archery;
	
	UFUNCTION()
	void OnRep_Archery(const FGameplayAttributeData& OldArchery) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ArcheryExperience, Category=Vital)
	FGameplayAttributeData ArcheryExperience;
	
	UFUNCTION()
	void OnRep_ArcheryExperience(const FGameplayAttributeData& OldArcheryExperience) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Shield, Category=Vital)
	FGameplayAttributeData Shield;
	
	UFUNCTION()
	void OnRep_Shield(const FGameplayAttributeData& OldShield) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ShieldExperience, Category=Vital)
	FGameplayAttributeData ShieldExperience;
	
	UFUNCTION()
	void OnRep_ShieldExperience(const FGameplayAttributeData& OldShieldExperience) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ArmorUse, Category=Vital)
	FGameplayAttributeData ArmorUse;
	
	UFUNCTION()
	void OnRep_ArmorUse(const FGameplayAttributeData& OldArmorUse) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ArmorUseExperience, Category=Vital)
	FGameplayAttributeData ArmorUseExperience;
	
	UFUNCTION()
	void OnRep_ArmorUseExperience(const FGameplayAttributeData& OldArmorUseExperience) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Destruction, Category=Vital)
	FGameplayAttributeData Destruction;
	
	UFUNCTION()
	void OnRep_Destruction(const FGameplayAttributeData& OldDestruction) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_DestructionExperience, Category=Vital)
	FGameplayAttributeData DestructionExperience;
	
	UFUNCTION()
	void OnRep_DestructionExperience(const FGameplayAttributeData& OldDestructionExperience) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Restoration, Category=Vital)
	FGameplayAttributeData Restoration;
	
	UFUNCTION()
	void OnRep_Restoration(const FGameplayAttributeData& OldRestoration) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_RestorationExperience, Category=Vital)
	FGameplayAttributeData RestorationExperience;
	
	UFUNCTION()
	void OnRep_RestorationExperience(const FGameplayAttributeData& OldRestorationExperience) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Alteration, Category=Vital)
	FGameplayAttributeData Alteration;
	
	UFUNCTION()
	void OnRep_Alteration(const FGameplayAttributeData& OldAlteration) const;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_AlterationExperience, Category=Vital)
	FGameplayAttributeData AlterationExperience;
	
	UFUNCTION()
	void OnRep_AlterationExperience(const FGameplayAttributeData& OldAlterationExperience) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Illusion, Category=Vital)
	FGameplayAttributeData Illusion;
	
	UFUNCTION()
	void OnRep_Illusion(const FGameplayAttributeData& OldIllusion) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_IllusionExperience, Category=Vital)
	FGameplayAttributeData IllusionExperience;
	
	UFUNCTION()
	void OnRep_IllusionExperience(const FGameplayAttributeData& OldIllusionExperience) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Conjuration, Category=Vital)
	FGameplayAttributeData Conjuration;
	
	UFUNCTION()
	void OnRep_Conjuration(const FGameplayAttributeData& OldConjuration) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ConjurationExperience, Category=Vital)
	FGameplayAttributeData ConjurationExperience;

	UFUNCTION()
	void OnRep_ConjurationExperience(const FGameplayAttributeData& OldIllusionExperience) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Vital)
	FGameplayAttributeData IncomingDestructionExperience;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Vital)
	FGameplayAttributeData IncomingRestorationExperience;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Vital)
	FGameplayAttributeData IncomingAlterationExperience;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Vital)
	FGameplayAttributeData IncomingConjurationExperience;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Vital)
	FGameplayAttributeData IncomingIllusionExperience;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Curves)
	FScalableFloat DestructionCurve;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Curves)
	FScalableFloat RestorationCurve;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Curves)
	FScalableFloat AlterationCurve;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Curves)
	FScalableFloat ConjurationCurve;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Curves)
	FScalableFloat IllusionCurve;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Curves)
	FScalableFloat OneHandedCurve;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Curves)
	FScalableFloat TwoHandedCurve;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Curves)
	FScalableFloat ShieldCurve;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Curves)
	FScalableFloat ArmorUseCurve;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Curves)
	FScalableFloat ArcheryCurve;
};
