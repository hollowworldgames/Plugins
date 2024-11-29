// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "Attributes/WeaponAttributeSet.h"
#include "Net/UnrealNetwork.h"

UE_DEFINE_GAMEPLAY_TAG_COMMENT(WeaponAccuracyTag,"Weapon.Attributes.Accuracy","Weapon Accuracy");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(WeaponMinDamageTag,"Weapon.Attributes.MinDamage","Weapon Min Damage");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(WeaponMaxDamageTag,"Weapon.Attributes.MaxDamage","Weapon Max Damage");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(WeaponMinRangeTag,"Weapon.Attributes.MinRange","Weapon Min Range");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(WeaponMaxRangeTag,"Weapon.Attributes.MaxRange","Weapon Max Range");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(WeaponCriticalChanceTag,"Weapon.Attributes.CriticalChance","Weapon Critical Chance");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(WeaponCriticalDamageTag,"Weapon.Attributes.CriticalDamage","Weapon Critical Damage");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(WeaponCooldownTag,"Weapon.Attributes.Cooldown","Weapon Cooldown");

float UWeaponAttributeSet::GetAttributeValue(FGameplayTag AttributeTag)
{
	GET_IF_TAGMATCHES(WeaponAccuracy, AttributeTag);
	GET_IF_TAGMATCHES(WeaponMinDamage, AttributeTag);
	GET_IF_TAGMATCHES(WeaponMaxDamage, AttributeTag);
	GET_IF_TAGMATCHES(WeaponMinRange, AttributeTag);
	GET_IF_TAGMATCHES(WeaponMaxRange, AttributeTag);
	GET_IF_TAGMATCHES(WeaponCriticalChance, AttributeTag);
	GET_IF_TAGMATCHES(WeaponCriticalDamage, AttributeTag);
	GET_IF_TAGMATCHES(WeaponCooldown, AttributeTag);
	return Super::GetAttributeValue(AttributeTag);
}

void UWeaponAttributeSet::SetAttributeValue(FGameplayTag Attribute, float Value)
{
	SET_IF_TAGMATCHES(WeaponAccuracy, Attribute, Value);
	SET_IF_TAGMATCHES(WeaponMinDamage, Attribute, Value);
	SET_IF_TAGMATCHES(WeaponMaxDamage, Attribute, Value);
	SET_IF_TAGMATCHES(WeaponMinRange, Attribute, Value);
	SET_IF_TAGMATCHES(WeaponMaxRange, Attribute, Value);
	SET_IF_TAGMATCHES(WeaponCriticalChance, Attribute, Value);
	SET_IF_TAGMATCHES(WeaponCriticalDamage, Attribute, Value);
	SET_IF_TAGMATCHES(WeaponCriticalDamage, Attribute, Value);
	SET_IF_TAGMATCHES(WeaponCooldown, Attribute, Value);
	Super::SetAttributeValue(Attribute, Value);
}

FGameplayTag UWeaponAttributeSet::GetAttributeTag(FGameplayAttribute Attribute)
{
	CHECK_IF_ATTRIBUTE(WeaponAccuracy, Attribute);
	CHECK_IF_ATTRIBUTE(WeaponMinDamage, Attribute);
	CHECK_IF_ATTRIBUTE(WeaponMaxDamage, Attribute);
	CHECK_IF_ATTRIBUTE(WeaponMinRange, Attribute);
	CHECK_IF_ATTRIBUTE(WeaponMaxRange, Attribute);
	CHECK_IF_ATTRIBUTE(WeaponCriticalChance, Attribute);
	CHECK_IF_ATTRIBUTE(WeaponCriticalDamage, Attribute);
	CHECK_IF_ATTRIBUTE(WeaponCooldown, Attribute);
	return Super::GetAttributeTag(Attribute);
}

void UWeaponAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UWeaponAttributeSet, WeaponMinDamage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UWeaponAttributeSet, WeaponMaxDamage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UWeaponAttributeSet, WeaponMinRange, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UWeaponAttributeSet, WeaponMaxRange, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UWeaponAttributeSet, WeaponAccuracy, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UWeaponAttributeSet, WeaponCriticalChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UWeaponAttributeSet, WeaponCriticalDamage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UWeaponAttributeSet, WeaponCooldown, COND_None, REPNOTIFY_Always);
}

void UWeaponAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}

ATTRIBUTE_IMPLEMENT(UWeaponAttributeSet, WeaponMinDamage);
ATTRIBUTE_IMPLEMENT(UWeaponAttributeSet, WeaponMaxDamage);
ATTRIBUTE_IMPLEMENT(UWeaponAttributeSet, WeaponMinRange);
ATTRIBUTE_IMPLEMENT(UWeaponAttributeSet, WeaponMaxRange);
ATTRIBUTE_IMPLEMENT(UWeaponAttributeSet, WeaponAccuracy);
ATTRIBUTE_IMPLEMENT(UWeaponAttributeSet, WeaponCriticalChance);
ATTRIBUTE_IMPLEMENT(UWeaponAttributeSet, WeaponCriticalDamage);
ATTRIBUTE_IMPLEMENT(UWeaponAttributeSet, WeaponCooldown);