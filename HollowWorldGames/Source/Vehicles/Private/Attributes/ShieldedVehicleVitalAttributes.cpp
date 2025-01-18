// Copyright (c) 2024 Hollow World Games llc All Rights Reserved


#include "Attributes/ShieldedVehicleVitalAttributes.h"

#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

UE_DEFINE_GAMEPLAY_TAG_COMMENT(FuselageHealthTag, "Vehicle.Attribute.Fuselage.Health", "Fuselage Health")
UE_DEFINE_GAMEPLAY_TAG_COMMENT(FuselageMaxHealthTag, "Vehicle.Attribute.Fuselage.MaxHealth", "Fuselage Max Health")
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ForwardShieldHealthTag, "Vehicle.Attribute.Shield.Forward.Health", "Forward Shield Health")
UE_DEFINE_GAMEPLAY_TAG_COMMENT(RearShieldHealthTag, "Vehicle.Attribute.Shield.Rear.Health", "Rear Shield Health")


float UShieldedVehicleVitalAttributes::GetAttributeValue(FGameplayTag AttributeTag)
{
	GET_IF_TAGMATCHES(FuselageHealth, AttributeTag);
	GET_IF_TAGMATCHES(FuselageMaxHealth, AttributeTag);
	GET_IF_TAGMATCHES(ForwardShieldHealth, AttributeTag);
	GET_IF_TAGMATCHES(ForwardShieldMaxHealth, AttributeTag);
	GET_IF_TAGMATCHES(RearShieldHealth, AttributeTag);
	GET_IF_TAGMATCHES(RearShieldMaxHealth, AttributeTag);
	return Super::GetAttributeValue(AttributeTag);
}

void UShieldedVehicleVitalAttributes::SetAttributeValue(FGameplayTag Attribute, float Value)
{
	SET_IF_TAGMATCHES(FuselageHealth, Attribute, Value);
	SET_IF_TAGMATCHES(FuselageMaxHealth, Attribute, Value);
	SET_IF_TAGMATCHES(ForwardShieldHealth, Attribute, Value);
	SET_IF_TAGMATCHES(RearShieldHealth, Attribute, Value);
	SET_IF_TAGMATCHES(RearShieldMaxHealth, Attribute, Value);
	SET_IF_TAGMATCHES(ForwardShieldMaxHealth, Attribute, Value);
	Super::SetAttributeValue(Attribute, Value);
}

FGameplayTag UShieldedVehicleVitalAttributes::GetAttributeTag(FGameplayAttribute Attribute)
{
	CHECK_IF_ATTRIBUTE(FuselageHealth, Attribute);
	CHECK_IF_ATTRIBUTE(FuselageMaxHealth, Attribute);
	CHECK_IF_ATTRIBUTE(ForwardShieldHealth, Attribute);
	CHECK_IF_ATTRIBUTE(RearShieldHealth, Attribute);
	CHECK_IF_ATTRIBUTE(RearShieldMaxHealth, Attribute);
	CHECK_IF_ATTRIBUTE(ForwardShieldMaxHealth, Attribute);
	return Super::GetAttributeTag(Attribute);
}

void UShieldedVehicleVitalAttributes::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UShieldedVehicleVitalAttributes, FuselageHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UShieldedVehicleVitalAttributes, FuselageMaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UShieldedVehicleVitalAttributes, ForwardShieldHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UShieldedVehicleVitalAttributes, RearShieldHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UShieldedVehicleVitalAttributes, ForwardShieldMaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UShieldedVehicleVitalAttributes, RearShieldMaxHealth, COND_None, REPNOTIFY_Always);
}

void UShieldedVehicleVitalAttributes::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	PROCESS_INCOMING_DAMAGE_NO_NOTIFY(IncomingFuselageDamage, FuselageHealth, Data);
	PROCESS_INCOMING_DAMAGE_NO_NOTIFY(IncomingForwardShieldDamage, ForwardShieldHealth, Data);
	PROCESS_INCOMING_DAMAGE_NO_NOTIFY(IncomingRearShieldDamage, RearShieldHealth, Data);

	CAP_ATTRIBUTE(FuselageHealth, FuselageMaxHealth, Data);
	CAP_ATTRIBUTE(ForwardShieldHealth, ForwardShieldMaxHealth, Data);
	CAP_ATTRIBUTE(RearShieldHealth, RearShieldMaxHealth, Data);
}

ATTRIBUTE_IMPLEMENT(UShieldedVehicleVitalAttributes, FuselageHealth);
ATTRIBUTE_IMPLEMENT(UShieldedVehicleVitalAttributes, FuselageMaxHealth);
ATTRIBUTE_IMPLEMENT(UShieldedVehicleVitalAttributes, ForwardShieldHealth);
ATTRIBUTE_IMPLEMENT(UShieldedVehicleVitalAttributes, ForwardShieldMaxHealth);
ATTRIBUTE_IMPLEMENT(UShieldedVehicleVitalAttributes, RearShieldHealth);
ATTRIBUTE_IMPLEMENT(UShieldedVehicleVitalAttributes, RearShieldMaxHealth);
