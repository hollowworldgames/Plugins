// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "Attributes/WeaponAttributeSet.h"
#include "Net/UnrealNetwork.h"

void UWeaponAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UWeaponAttributeSet, WeaponLevel, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UWeaponAttributeSet, WeaponHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UWeaponAttributeSet, MaxWeaponHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UWeaponAttributeSet, WeaponMinDamage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UWeaponAttributeSet, WeaponMaxDamage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UWeaponAttributeSet, WeaponMinRange, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UWeaponAttributeSet, WeaponMaxRange, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UWeaponAttributeSet, WeaponAccuracy, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UWeaponAttributeSet, WeaponCriticalChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UWeaponAttributeSet, WeaponCriticalDamage, COND_None, REPNOTIFY_Always);
}

ATTRIBUTE_IMPLEMENT(UWeaponAttributeSet, WeaponLevel);
ATTRIBUTE_IMPLEMENT(UWeaponAttributeSet, WeaponHealth);
ATTRIBUTE_IMPLEMENT(UWeaponAttributeSet, MaxWeaponHealth);
ATTRIBUTE_IMPLEMENT(UWeaponAttributeSet, WeaponMinDamage);
ATTRIBUTE_IMPLEMENT(UWeaponAttributeSet, WeaponMaxDamage);
ATTRIBUTE_IMPLEMENT(UWeaponAttributeSet, WeaponMinRange);
ATTRIBUTE_IMPLEMENT(UWeaponAttributeSet, WeaponMaxRange);
ATTRIBUTE_IMPLEMENT(UWeaponAttributeSet, WeaponAccuracy);
ATTRIBUTE_IMPLEMENT(UWeaponAttributeSet, WeaponCriticalChance);
ATTRIBUTE_IMPLEMENT(UWeaponAttributeSet, WeaponCriticalDamage);