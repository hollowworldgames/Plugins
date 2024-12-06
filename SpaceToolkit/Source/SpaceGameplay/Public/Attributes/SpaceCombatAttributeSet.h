// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SpaceGameplayTags.h"
#include "Attributes/AttributeSetBase.h"
#include "Attributes/RPGCombatAttributeSet.h"
#include "SpaceCombatAttributeSet.generated.h"


UCLASS()
class SPACEGAMEPLAY_API USpaceCombatAttributeSet : public URPGCombatAttributeSet
{
	GENERATED_BODY()
public :
	ATTRIBUTE_ACCESSORS(USpaceCombatAttributeSet, FrontShield);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, FrontShield);
	ATTRIBUTE_ACCESSORS(USpaceCombatAttributeSet, MaxFrontShield);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, MaxFrontShield);
	ATTRIBUTE_ACCESSORS(USpaceCombatAttributeSet, FrontMitigation1);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, FrontMitigation1);
	ATTRIBUTE_ACCESSORS(USpaceCombatAttributeSet, FrontMitigation2);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, FrontMitigation2);
	ATTRIBUTE_ACCESSORS(USpaceCombatAttributeSet, FrontMitigation3);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, FrontMitigation3);
	ATTRIBUTE_ACCESSORS(USpaceCombatAttributeSet, FrontMitigation4);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, FrontMitigation4);

	ATTRIBUTE_ACCESSORS(USpaceCombatAttributeSet, BackShield);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, BackShield);
	ATTRIBUTE_ACCESSORS(USpaceCombatAttributeSet, MaxBackShield);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, MaxBackShield);
	ATTRIBUTE_ACCESSORS(USpaceCombatAttributeSet, BackMitigation1);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, BackMitigation1);
	ATTRIBUTE_ACCESSORS(USpaceCombatAttributeSet, BackMitigation2);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, BackMitigation2);
	ATTRIBUTE_ACCESSORS(USpaceCombatAttributeSet, BackMitigation3);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, BackMitigation3);
	ATTRIBUTE_ACCESSORS(USpaceCombatAttributeSet, BackMitigation4);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, BackMitigation4);

	ATTRIBUTE_ACCESSORS(USpaceCombatAttributeSet, RightShield);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, RightShield);
	ATTRIBUTE_ACCESSORS(USpaceCombatAttributeSet, MaxRightShield);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, MaxRightShield);
	ATTRIBUTE_ACCESSORS(USpaceCombatAttributeSet, RightMitigation1);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, RightMitigation1);
	ATTRIBUTE_ACCESSORS(USpaceCombatAttributeSet, RightMitigation2);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, RightMitigation2);
	ATTRIBUTE_ACCESSORS(USpaceCombatAttributeSet, RightMitigation3);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, RightMitigation3);
	ATTRIBUTE_ACCESSORS(USpaceCombatAttributeSet, RightMitigation4);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, RightMitigation4);

	ATTRIBUTE_ACCESSORS(USpaceCombatAttributeSet, LeftShield);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, LeftShield);
	ATTRIBUTE_ACCESSORS(USpaceCombatAttributeSet, MaxLeftShield);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, MaxLeftShield);
	ATTRIBUTE_ACCESSORS(USpaceCombatAttributeSet, LeftMitigation1);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, LeftMitigation1);
	ATTRIBUTE_ACCESSORS(USpaceCombatAttributeSet, LeftMitigation2);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, LeftMitigation2);
	ATTRIBUTE_ACCESSORS(USpaceCombatAttributeSet, LeftMitigation3);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, LeftMitigation3);
	ATTRIBUTE_ACCESSORS(USpaceCombatAttributeSet, LeftMitigation4);
	ATTRIBUTE_TAG_ACCESSOR(UCombatAttributeSet, LeftMitigation4);
	ATTRIBUTE_ACCESSORS(USpaceCombatAttributeSet, ShieldFaces);	
	
	virtual float GetAttributeValue(FGameplayTag AttributeTag) override;
	virtual void SetAttributeValue(FGameplayTag Attribute, float Value) override;
	virtual FGameplayTag GetAttributeTag(FGameplayAttribute Attribute) override;
protected :
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_FrontShield, Category=Combat)
	FGameplayAttributeData FrontShield;
	UFUNCTION()
	void OnRep_FrontShield(const FGameplayAttributeData& OldFrontShield) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_MaxFrontShield, Category=Combat)
	FGameplayAttributeData MaxFrontShield;
	UFUNCTION()
	void OnRep_MaxFrontShield(const FGameplayAttributeData& OldMaxFrontShield) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_FrontMitigation1, Category=Combat)
	FGameplayAttributeData FrontMitigation1;
	UFUNCTION()
	void OnRep_FrontMitigation1(const FGameplayAttributeData& OldFrontMitigation) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_FrontMitigation2, Category=Combat)
	FGameplayAttributeData FrontMitigation2;
	UFUNCTION()
	void OnRep_FrontMitigation2(const FGameplayAttributeData& OldFrontMitigation2) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_FrontMitigation3, Category=Combat)
	FGameplayAttributeData FrontMitigation3;
	UFUNCTION()
	void OnRep_FrontMitigation3(const FGameplayAttributeData& OldFrontMitigation3) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_FrontMitigation4, Category=Combat)
	FGameplayAttributeData FrontMitigation4;
	UFUNCTION()
	void OnRep_FrontMitigation4(const FGameplayAttributeData& OldFrontMitigation4) const;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_BackShield, Category=Combat)
	FGameplayAttributeData BackShield;
	UFUNCTION()
	void OnRep_BackShield(const FGameplayAttributeData& OldBackShield) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_MaxBackShield, Category=Combat)
	FGameplayAttributeData MaxBackShield;
	UFUNCTION()
	void OnRep_MaxBackShield(const FGameplayAttributeData& OldMaxBackShield) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_BackMitigation1, Category=Combat)
	FGameplayAttributeData BackMitigation1;
	UFUNCTION()
	void OnRep_BackMitigation1(const FGameplayAttributeData& OldBackMitigation) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_BackMitigation2, Category=Combat)
	FGameplayAttributeData BackMitigation2;
	UFUNCTION()
	void OnRep_BackMitigation2(const FGameplayAttributeData& OldBackMitigation2) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_BackMitigation3, Category=Combat)
	FGameplayAttributeData BackMitigation3;
	UFUNCTION()
	void OnRep_BackMitigation3(const FGameplayAttributeData& OldBackMitigation3) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_BackMitigation4, Category=Combat)
	FGameplayAttributeData BackMitigation4;
	UFUNCTION()
	void OnRep_BackMitigation4(const FGameplayAttributeData& OldBackMitigation4) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_RightShield, Category=Combat)
	FGameplayAttributeData RightShield;
	UFUNCTION()
	void OnRep_RightShield(const FGameplayAttributeData& OldRightShield) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_MaxRightShield, Category=Combat)
	FGameplayAttributeData MaxRightShield;
	UFUNCTION()
	void OnRep_MaxRightShield(const FGameplayAttributeData& OldMaxRightShield) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_RightMitigation1, Category=Combat)
	FGameplayAttributeData RightMitigation1;
	UFUNCTION()
	void OnRep_RightMitigation1(const FGameplayAttributeData& OldRightMitigation) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_RightMitigation2, Category=Combat)
	FGameplayAttributeData RightMitigation2;
	UFUNCTION()
	void OnRep_RightMitigation2(const FGameplayAttributeData& OldRightMitigation2) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_RightMitigation3, Category=Combat)
	FGameplayAttributeData RightMitigation3;
	UFUNCTION()
	void OnRep_RightMitigation3(const FGameplayAttributeData& OldRightMitigation3) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_RightMitigation4, Category=Combat)
	FGameplayAttributeData RightMitigation4;
	UFUNCTION()
	void OnRep_RightMitigation4(const FGameplayAttributeData& OldRightMitigation4) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_LeftShield, Category=Combat)
	FGameplayAttributeData LeftShield;
	UFUNCTION()
	void OnRep_LeftShield(const FGameplayAttributeData& OldLeftShield) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_MaxLeftShield, Category=Combat)
	FGameplayAttributeData MaxLeftShield;
	UFUNCTION()
	void OnRep_MaxLeftShield(const FGameplayAttributeData& OldMaxLeftShield) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_LeftMitigation1, Category=Combat)
	FGameplayAttributeData LeftMitigation1;
	UFUNCTION()
	void OnRep_LeftMitigation1(const FGameplayAttributeData& OldLeftMitigation) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_LeftMitigation2, Category=Combat)
	FGameplayAttributeData LeftMitigation2;
	UFUNCTION()
	void OnRep_LeftMitigation2(const FGameplayAttributeData& OldLeftMitigation2) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_LeftMitigation3, Category=Combat)
	FGameplayAttributeData LeftMitigation3;
	UFUNCTION()
	void OnRep_LeftMitigation3(const FGameplayAttributeData& OldLeftMitigation3) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_LeftMitigation4, Category=Combat)
	FGameplayAttributeData LeftMitigation4;
	UFUNCTION()
	void OnRep_LeftMitigation4(const FGameplayAttributeData& OldLeftMitigation4) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ShieldFaces, Category=Combat)
	FGameplayAttributeData ShieldFaces;
	UFUNCTION()
	void OnRep_ShieldFaces(const FGameplayAttributeData& OldShieldFaces) const;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Combat)
	FGameplayAttributeData IncomingFrontKineticDamage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Combat)
	FGameplayAttributeData IncomingFrontEnergyDamage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Combat)
	FGameplayAttributeData IncomingBackKineticDamage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Combat)
	FGameplayAttributeData IncomingBackEnergyDamage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Combat)
	FGameplayAttributeData IncomingRightKineticDamage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Combat)
	FGameplayAttributeData IncomingRightEnergyDamage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Combat)
	FGameplayAttributeData IncomingLeftKineticDamage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Combat)
	FGameplayAttributeData IncomingLeftEnergyDamage;
};
