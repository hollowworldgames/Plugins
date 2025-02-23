// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Attributes/VitalAttributeSet.h"
#include "FantasyVitalAttributeSet.generated.h"

FANTASYCHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(MagicTag);
FANTASYCHARACTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(MaxMagicTag);

UCLASS()
class FANTASYCHARACTER_API UFantasyVitalAttributeSet : public UVitalAttributeSet
{
	GENERATED_BODY()
public :
	ATTRIBUTE_ACCESSORS(UFantasyVitalAttributeSet, Magic);
	ATTRIBUTE_ACCESSORS(UFantasyVitalAttributeSet, MaxMagic);
	
	virtual float GetAttributeValue(FGameplayTag AttributeTag) override;
	virtual void SetAttributeValue(FGameplayTag Attribute, float Value) override;
	virtual FGameplayTag GetAttributeTag(FGameplayAttribute Attribute) override;
protected :
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_Magic, Category=Vital)
	FGameplayAttributeData Magic;
	
	UFUNCTION()
	void OnRep_Magic(const FGameplayAttributeData& OldMagic) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, ReplicatedUsing=OnRep_MaxMagic, Category=Vital)
	FGameplayAttributeData MaxMagic;
	
	UFUNCTION()
	void OnRep_MaxMagic(const FGameplayAttributeData& OldMaxMagic) const;
};
