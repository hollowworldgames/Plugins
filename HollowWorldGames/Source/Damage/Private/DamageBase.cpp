// (c) Copyright 2023 Hollow World Games All Rights Reserved


#include "DamageBase.h"
#include "DamageResistance.h"


UDamageBase::UDamageBase()
{
}

UDamageBase::~UDamageBase()
{
}

float UDamageBase::ApplyDamage(TSubclassOf<UDamageResistance> resistance, float damage) const
{
	float damageOutput = 0;
	if(ensure(resistance.GetDefaultObject()))
	{
		for(int x = 0;x < Damage.Num();x++)
		{
			damageOutput += (1 - resistance.GetDefaultObject()->Resistance[x]) * (Damage[x] * damage);
		}
	}
	return damageOutput;
}

