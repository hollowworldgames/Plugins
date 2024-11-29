// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeMacros.h"
#include "AttributeSet.h"
#include "GameplayTags.h"
#include "AbilitySystemComponent.h"
#include "Attributes/AttributeSetBase.h"
#include "PilotAttributeSet.generated.h"

SPACEGAMEPLAY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(GForceToleranceTag);
SPACEGAMEPLAY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(GForceEnduranceTag);
SPACEGAMEPLAY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ThrusterPowerTag);
SPACEGAMEPLAY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ThrusterResponseTag);
SPACEGAMEPLAY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(JumpPowerTag);
SPACEGAMEPLAY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(JumpRangeTag);
SPACEGAMEPLAY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(JumpSpeedTag);
SPACEGAMEPLAY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(JumpTimeTag);

UCLASS()
class SPACEGAMEPLAY_API UPilotAttributeSet : public UAttributeSetBase
{
	GENERATED_BODY()
public :
	//Secondary Attributes
	ATTRIBUTE_ACCESSORS(UPilotAttributeSet, GForceTolerance);
	ATTRIBUTE_TAG_ACCESSOR(UPilotAttributeSet, GForceTolerance);
	ATTRIBUTE_ACCESSORS(UPilotAttributeSet, GForceEndurance);
	ATTRIBUTE_TAG_ACCESSOR(UPilotAttributeSet, GForceEndurance);
	ATTRIBUTE_ACCESSORS(UPilotAttributeSet, ThrusterPower);
	ATTRIBUTE_TAG_ACCESSOR(UPilotAttributeSet, ThrusterPower);
	ATTRIBUTE_ACCESSORS(UPilotAttributeSet, ThrusterResponse);
	ATTRIBUTE_TAG_ACCESSOR(UPilotAttributeSet, ThrusterResponse);
	ATTRIBUTE_ACCESSORS(UPilotAttributeSet, JumpPower);
	ATTRIBUTE_TAG_ACCESSOR(UPilotAttributeSet, JumpPower);
	ATTRIBUTE_ACCESSORS(UPilotAttributeSet, JumpRange);
	ATTRIBUTE_TAG_ACCESSOR(UPilotAttributeSet, JumpRange);
	ATTRIBUTE_ACCESSORS(UPilotAttributeSet, JumpSpeed);
	ATTRIBUTE_TAG_ACCESSOR(UPilotAttributeSet, JumpSpeed);
	ATTRIBUTE_ACCESSORS(UPilotAttributeSet, JumpTime);
	ATTRIBUTE_TAG_ACCESSOR(UPilotAttributeSet, JumpTime);
	virtual float GetAttributeValue(FGameplayTag AttributeTag) override;
	virtual void SetAttributeValue(FGameplayTag Attribute, float Value) override;
	virtual FGameplayTag GetAttributeTag(FGameplayAttribute Attribute) override;
protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	//Secondary Attributes
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_GForceTolerance, Category=Health)
	FGameplayAttributeData GForceTolerance;
	UFUNCTION()
	void OnRep_GForceTolerance(const FGameplayAttributeData& OldGForceTolerance) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_GForceEndurance, Category=Health)
	FGameplayAttributeData GForceEndurance;
	UFUNCTION()
	void OnRep_GForceEndurance(const FGameplayAttributeData& OldGForceEndurance) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ThrusterPower, Category=Health)
	FGameplayAttributeData ThrusterPower;
	UFUNCTION()
	void OnRep_ThrusterPower(const FGameplayAttributeData& OldThrusterPower) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_ThrusterResponse, Category=Health)
	FGameplayAttributeData ThrusterResponse;
	UFUNCTION()
	void OnRep_ThrusterResponse(const FGameplayAttributeData& OldThrusterResponse) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_JumpPower, Category=Health)
	FGameplayAttributeData JumpPower;
	UFUNCTION()
	void OnRep_JumpPower(const FGameplayAttributeData& OldJumpPower) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_JumpRange, Category=Health)
	FGameplayAttributeData JumpRange;
	UFUNCTION()
	void OnRep_JumpRange(const FGameplayAttributeData& OldJumpRange) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_JumpSpeed, Category=Health)
	FGameplayAttributeData JumpSpeed;
	UFUNCTION()
	void OnRep_JumpSpeed(const FGameplayAttributeData& OldJumpSpeed) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_JumpTime, Category=Health)
	FGameplayAttributeData JumpTime;
	UFUNCTION()
	void OnRep_JumpTime(const FGameplayAttributeData& OldJumpTime) const;
};
