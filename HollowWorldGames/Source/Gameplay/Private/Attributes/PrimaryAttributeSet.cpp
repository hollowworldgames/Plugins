// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.


#include "Attributes/PrimaryAttributeSet.h"

#include "Net/UnrealNetwork.h"

UE_DEFINE_GAMEPLAY_TAG_COMMENT(StrengthTag, "Primary.Attributes.Strength", "Strength");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(AgilityTag,"Primary.Attributes.Agility","Agility");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(PrecisionTag,"Primary.Attributes.Precision","Precision");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(IntelligenceTag,"Primary.Attributes.Intelligence","Intelligence");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(WisdomTag,"Primary.Attributes.Wisdom","Wisdom");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(LuckTag,"Primary.Attributes.Luck","Luck");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(ConstitutionTag,"Primary.Attributes.Constitution","Constitution");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(EnduranceTag,"Primary.Attributes.Endurance","Endurance");
UE_DEFINE_GAMEPLAY_TAG_COMMENT(CharismaTag,"Primary.Attributes.Charisma","Charisma");

float UPrimaryAttributeSet::GetAttributeValue(FGameplayTag AttributeTag)
{
	return Super::GetAttributeValue(AttributeTag);
}

void UPrimaryAttributeSet::SetAttributeValue(FGameplayTag Attribute, float Value)
{
	Super::SetAttributeValue(Attribute, Value);
}

FGameplayTag UPrimaryAttributeSet::GetAttributeTag(FGameplayAttribute Attribute)
{
	return Super::GetAttributeTag(Attribute);
}

void UPrimaryAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UPrimaryAttributeSet, Strength, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPrimaryAttributeSet, Agility, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPrimaryAttributeSet, Precision, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPrimaryAttributeSet, Intelligence, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPrimaryAttributeSet, Wisdom, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPrimaryAttributeSet, Luck, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPrimaryAttributeSet, Constitution, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPrimaryAttributeSet, Endurance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPrimaryAttributeSet, Charisma, COND_None, REPNOTIFY_Always);
}

void UPrimaryAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}

ATTRIBUTE_IMPLEMENT(UPrimaryAttributeSet, Strength);
ATTRIBUTE_IMPLEMENT(UPrimaryAttributeSet, Agility);
ATTRIBUTE_IMPLEMENT(UPrimaryAttributeSet, Precision);
ATTRIBUTE_IMPLEMENT(UPrimaryAttributeSet, Intelligence);
ATTRIBUTE_IMPLEMENT(UPrimaryAttributeSet, Wisdom);
ATTRIBUTE_IMPLEMENT(UPrimaryAttributeSet, Luck);
ATTRIBUTE_IMPLEMENT(UPrimaryAttributeSet, Constitution);
ATTRIBUTE_IMPLEMENT(UPrimaryAttributeSet, Endurance);
ATTRIBUTE_IMPLEMENT(UPrimaryAttributeSet, Charisma);
