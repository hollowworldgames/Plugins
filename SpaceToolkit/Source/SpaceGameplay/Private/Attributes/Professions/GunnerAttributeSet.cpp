// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Attributes/Professions/GunnerAttributeSet.h"
#include "Net/UnrealNetwork.h"

UE_DEFINE_GAMEPLAY_TAG_COMMENT(RangeTag,"Gunner.Attributes.Range","Range");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(AccuracyTag,"Gunner.Attributes.Accuracy","Accuracy");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(FireRateTag,"Gunner.Attributes.FireRate","FireRate");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(EfficiencyTag,"Gunner.Attributes.Efficiency","Efficiency");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ReflexesTag,"Gunner.Attributes.Reflexes","Reflexes");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(TargetAnalysisTag,"Gunner.Attributes.TargetAnalysis","Target Analysis");

float UGunnerAttributeSet::GetAttributeValue(FGameplayTag AttributeTag)
{
	GET_IF_TAGMATCHES(Range, AttributeTag);
	GET_IF_TAGMATCHES(Accuracy, AttributeTag);
	GET_IF_TAGMATCHES(FireRate, AttributeTag);
	GET_IF_TAGMATCHES(Efficiency, AttributeTag);
	GET_IF_TAGMATCHES(Reflexes, AttributeTag);
	GET_IF_TAGMATCHES(TargetAnalysis, AttributeTag);
	return Super::GetAttributeValue(AttributeTag);
}

void UGunnerAttributeSet::SetAttributeValue(FGameplayTag Attribute, float Value)
{
	SET_IF_TAGMATCHES(Range, Attribute, Value);
	SET_IF_TAGMATCHES(Accuracy, Attribute, Value);
	SET_IF_TAGMATCHES(FireRate, Attribute, Value);
	SET_IF_TAGMATCHES(Efficiency, Attribute, Value);
	SET_IF_TAGMATCHES(Reflexes, Attribute, Value);
	SET_IF_TAGMATCHES(TargetAnalysis, Attribute, Value);
	Super::SetAttributeValue(Attribute, Value);
}

FGameplayTag UGunnerAttributeSet::GetAttributeTag(FGameplayAttribute Attribute)
{
	CHECK_IF_ATTRIBUTE(Range, Attribute);
	CHECK_IF_ATTRIBUTE(Accuracy, Attribute);
	CHECK_IF_ATTRIBUTE(FireRate, Attribute);
	CHECK_IF_ATTRIBUTE(Efficiency, Attribute);
	CHECK_IF_ATTRIBUTE(Reflexes, Attribute);
	CHECK_IF_ATTRIBUTE(TargetAnalysis, Attribute);
	return Super::GetAttributeTag(Attribute);
}

void UGunnerAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UGunnerAttributeSet, Range, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGunnerAttributeSet, Accuracy, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGunnerAttributeSet, FireRate, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGunnerAttributeSet, Efficiency, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGunnerAttributeSet, Reflexes, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGunnerAttributeSet, TargetAnalysis, COND_None, REPNOTIFY_Always);
}

void UGunnerAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}

ATTRIBUTE_IMPLEMENT(UGunnerAttributeSet, Range);
ATTRIBUTE_IMPLEMENT(UGunnerAttributeSet, Accuracy);
ATTRIBUTE_IMPLEMENT(UGunnerAttributeSet, FireRate);
ATTRIBUTE_IMPLEMENT(UGunnerAttributeSet, Efficiency);
ATTRIBUTE_IMPLEMENT(UGunnerAttributeSet, Reflexes);
ATTRIBUTE_IMPLEMENT(UGunnerAttributeSet, TargetAnalysis);
