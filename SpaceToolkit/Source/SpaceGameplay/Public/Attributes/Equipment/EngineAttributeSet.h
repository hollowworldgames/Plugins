// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeMacros.h"
#include "NativeGameplayTags.h"
#include "AbilitySystemComponent.h"
#include "Attributes/AttributeSetBase.h"
#include "EngineAttributeSet.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEngineDead);


SPACEGAMEPLAY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(EngineThrustTag);
SPACEGAMEPLAY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(EnginePowerTag);
SPACEGAMEPLAY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(EngineDistributionTag);
SPACEGAMEPLAY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(PowerToThrustTag);
SPACEGAMEPLAY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(MaxRCSThrustTag);
SPACEGAMEPLAY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(EngineOnTag);

UCLASS()
class SPACEGAMEPLAY_API UEngineAttributeSet : public UAttributeSetBase
{
	GENERATED_BODY()
public :
	ATTRIBUTE_ACCESSORS(UEngineAttributeSet, EngineThrust);
	ATTRIBUTE_TAG_ACCESSOR(UEngineAttributeSet, EngineThrust);
	ATTRIBUTE_ACCESSORS(UEngineAttributeSet, EnginePower);
	ATTRIBUTE_TAG_ACCESSOR(UEngineAttributeSet, EnginePower);
	ATTRIBUTE_ACCESSORS(UEngineAttributeSet, PowerToThrust);
	ATTRIBUTE_TAG_ACCESSOR(UEngineAttributeSet, PowerToThrust);
	ATTRIBUTE_ACCESSORS(UEngineAttributeSet, MaxRCSThrust);
	ATTRIBUTE_TAG_ACCESSOR(UEngineAttributeSet, MaxRCSThrust);
	ATTRIBUTE_ACCESSORS(UEngineAttributeSet, EngineDistribution);
	ATTRIBUTE_TAG_ACCESSOR(UEngineAttributeSet, EngineDistribution);
	virtual float GetAttributeValue(FGameplayTag AttributeTag) override;
	virtual void SetAttributeValue(FGameplayTag Attribute, float Value) override;
	virtual FGameplayTag GetAttributeTag(FGameplayAttribute Attribute) override;
protected :
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_EngineThrust, Category=Engine)
	FGameplayAttributeData EngineThrust;
	UFUNCTION()
	void OnRep_EngineThrust(const FGameplayAttributeData& OldEngineThrust) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_EngineDistribution, Category=Engine)
	FGameplayAttributeData EngineDistribution;
	UFUNCTION()
	void OnRep_EngineDistribution(const FGameplayAttributeData& OldEngineDistribution) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_EnginePower, Category=Engine)
	FGameplayAttributeData EnginePower;
	UFUNCTION()
	void OnRep_EnginePower(const FGameplayAttributeData& OldEnginePower) const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Engine)
	FGameplayAttributeData PowerToThrust;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Engine)
	FGameplayAttributeData MaxRCSThrust;
};
