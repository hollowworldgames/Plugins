// Copyright (C) 2024 Hollow World Games llc All Rights Reserved.


#include "Attributes/FantasyCombatAttributeSet.h"
#include "Net/UnrealNetwork.h"

UE_DEFINE_GAMEPLAY_TAG_COMMENT(PhysicalMitigationTag, "Combat.Attribute.PhysicalMitigation", "Physical Mitigation");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ElementalMitigationTag, "Combat.Attribute.ElementalMitigation", "Elemental Mitigation");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(MagicalMitigationTag, "Combat.Attribute.MagicalMitigation", "Magical Mitigation");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(PhysicalResistanceTag, "Combat.Attribute.PhysicalResistance", "Physical Resistance");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ElementalResistanceTag, "Combat.Attribute.ElementalResistance", "Elemental Resistance");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(MagicalResistanceTag, "Combat.Attribute.MagicalResistance", "Magical Resistance");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(PhysicalDamageTag, "Combat.Attribute.PhysicalDamage", "Physical Damage");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ElementalDamageTag, "Combat.Attribute.ElementalDamage", "Elemental Damage");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(MagicalDamageTag, "Combat.Attribute.MagicalDamage", "Magical Damage");

UE_DEFINE_GAMEPLAY_TAG_COMMENT(PhysicalTypeTag, "Combat.DamageType.Physical", "Physical Damage Type");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(BlugeonTypeTag, "Combat.DamageType.Physical.Bludgeon", "Bludgeon Damage Type");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(BleedTypeTag, "Combat.DamageType.Physical.Bleed", "Bleed Damage Type");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(PoisonTypeTag, "Combat.DamageType.Physical.Poison", "Poison Damage Type");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ElementalTypeTag, "Combat.DamageType.Elemental", "Elemental Damage Type");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(FireTypeTag, "Combat.DamageType.Elemental.Fire", "Fire Damage Type");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(IceTypeTag, "Combat.DamageType.Elemental.Ice", "Ice Damage Type");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ElectricityTypeTag, "Combat.DamageType.Elemental.Electricity", "Electricity Damage Type");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(MagicalTypeTag, "Combat.DamageType.Magical", "Magical Damage Type");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(LightTypeTag, "Combat.DamageType.Magical.Light", "Light Damage Type");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ShadowTypeTag, "Combat.DamageType.Magical.Shadow", "Shadow Damage Type");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(FearTypeTag, "Combat.DamageType.Magical.Fear", "Fear Damage Type");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(PhysicalBoostTag, "Combat.DamageBoost.Physical", "Physical Damage Boost");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ElementalBoostTag, "Combat.DamageBoost.Elemental", "Elemental Damage Boost");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(MagicalBoostTag, "Combat.DamageBoost.Magical", "Magical Damage Boost");

float UFantasyCombatAttributeSet::GetAttributeValue(FGameplayTag AttributeTag)
{
	GET_IF_TAGMATCHES(PhysicalMitigation, AttributeTag);
	GET_IF_TAGMATCHES(ElementalMitigation, AttributeTag);
	GET_IF_TAGMATCHES(MagicalMitigation, AttributeTag);
	GET_IF_TAGMATCHES(PhysicalResistance, AttributeTag);
	GET_IF_TAGMATCHES(ElementalResistance, AttributeTag);
	GET_IF_TAGMATCHES(MagicalResistance, AttributeTag);
	GET_IF_TAGMATCHES(PhysicalDamage, AttributeTag);
	GET_IF_TAGMATCHES(ElementalDamage, AttributeTag);
	GET_IF_TAGMATCHES(MagicalDamage, AttributeTag);
	return Super::GetAttributeValue(AttributeTag);
}

void UFantasyCombatAttributeSet::SetAttributeValue(FGameplayTag Attribute, float Value)
{
	SET_IF_TAGMATCHES(PhysicalMitigation, Attribute, Value);
	SET_IF_TAGMATCHES(ElementalMitigation, Attribute, Value);
	SET_IF_TAGMATCHES(MagicalMitigation, Attribute, Value);
	SET_IF_TAGMATCHES(PhysicalResistance, Attribute, Value);
	SET_IF_TAGMATCHES(ElementalResistance, Attribute, Value);
	SET_IF_TAGMATCHES(MagicalResistance, Attribute, Value);
	SET_IF_TAGMATCHES(PhysicalDamage, Attribute, Value);
	SET_IF_TAGMATCHES(ElementalDamage, Attribute, Value);
	SET_IF_TAGMATCHES(MagicalDamage, Attribute, Value);
	Super::SetAttributeValue(Attribute, Value);
}

FGameplayTag UFantasyCombatAttributeSet::GetAttributeTag(FGameplayAttribute Attribute)
{
	CHECK_IF_ATTRIBUTE(PhysicalMitigation, Attribute);
	CHECK_IF_ATTRIBUTE(ElementalMitigation, Attribute);
	CHECK_IF_ATTRIBUTE(MagicalMitigation, Attribute);
	CHECK_IF_ATTRIBUTE(PhysicalResistance, Attribute);
	CHECK_IF_ATTRIBUTE(ElementalResistance, Attribute);
	CHECK_IF_ATTRIBUTE(MagicalResistance, Attribute);
	CHECK_IF_ATTRIBUTE(PhysicalDamage, Attribute);
	CHECK_IF_ATTRIBUTE(ElementalDamage, Attribute);
	CHECK_IF_ATTRIBUTE(MagicalDamage, Attribute);
	return Super::GetAttributeTag(Attribute);
}

void UFantasyCombatAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasyCombatAttributeSet, PhysicalDamage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasyCombatAttributeSet, ElementalDamage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasyCombatAttributeSet, MagicalDamage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasyCombatAttributeSet, PhysicalResistance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasyCombatAttributeSet, ElementalResistance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasyCombatAttributeSet, MagicalResistance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasyCombatAttributeSet, PhysicalMitigation, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasyCombatAttributeSet, ElementalMitigation, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFantasyCombatAttributeSet, MagicalMitigation, COND_None, REPNOTIFY_Always);
}

void UFantasyCombatAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}

ATTRIBUTE_IMPLEMENT(UFantasyCombatAttributeSet, PhysicalMitigation);
ATTRIBUTE_IMPLEMENT(UFantasyCombatAttributeSet, ElementalMitigation);
ATTRIBUTE_IMPLEMENT(UFantasyCombatAttributeSet, MagicalMitigation);
ATTRIBUTE_IMPLEMENT(UFantasyCombatAttributeSet, PhysicalResistance);
ATTRIBUTE_IMPLEMENT(UFantasyCombatAttributeSet, ElementalResistance);
ATTRIBUTE_IMPLEMENT(UFantasyCombatAttributeSet, MagicalResistance);
ATTRIBUTE_IMPLEMENT(UFantasyCombatAttributeSet, PhysicalDamage);
ATTRIBUTE_IMPLEMENT(UFantasyCombatAttributeSet, ElementalDamage);
ATTRIBUTE_IMPLEMENT(UFantasyCombatAttributeSet, MagicalDamage);