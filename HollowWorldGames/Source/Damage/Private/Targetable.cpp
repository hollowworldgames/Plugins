// (c) Copyright 2023 Hollow World Games All Rights Reserved


#include "Targetable.h"

// Add default functionality here for any ITargetable functions that are not pure virtual.
ETeamAttitude::Type ITargetable::GetTeamAttitude(AActor* Actor)
{
	IGenericTeamAgentInterface * TeamAgentInterface = Cast<IGenericTeamAgentInterface>(Actor);
	if(TeamAgentInterface)
	{
		return TeamAgentInterface->GetTeamAttitudeTowards(*Actor);
	}
	return ETeamAttitude::Neutral;
}
