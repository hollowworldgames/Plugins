// Copyright (c) 2024 Hollow World Games llc All Rights Reserved


#include "Attributes/ShieldedVehicleVitalAttributes.h"

#include "GameplayEffectExtension.h"

UE_DEFINE_GAMEPLAY_TAG_COMMENT(FuselageHealthTag, "Vehicle.Attribute.Fuselage.Health", "Fuselage Health")
UE_DEFINE_GAMEPLAY_TAG_COMMENT(FuselageMaxHealthTag, "Vehicle.Attribute.Fuselage.MaxHealth", "Fuselage Max Health")

float UShieldedVehicleVitalAttributes::GetAttributeValue(FGameplayTag AttributeTag)
{
	return Super::GetAttributeValue(AttributeTag);
}

void UShieldedVehicleVitalAttributes::SetAttributeValue(FGameplayTag Attribute, float Value)
{
	Super::SetAttributeValue(Attribute, Value);
}

FGameplayTag UShieldedVehicleVitalAttributes::GetAttributeTag(FGameplayAttribute Attribute)
{
	return Super::GetAttributeTag(Attribute);
}

void UShieldedVehicleVitalAttributes::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}

void UShieldedVehicleVitalAttributes::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	PROCESS_INCOMING_DAMAGE_NO_NOTIFY(IncomingFuselageDamage, FuselageHealth, Data);
}

ATTRIBUTE_IMPLEMENT(UShieldedVehicleVitalAttributes, FuselageHealth);
ATTRIBUTE_IMPLEMENT(UShieldedVehicleVitalAttributes, FuselageMaxHealth);
