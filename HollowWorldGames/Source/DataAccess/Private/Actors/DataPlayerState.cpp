// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "Actors/DataPlayerState.h"

#include "Components/DataAccessComponent.h"

void ADataPlayerState::Multicast_PostLoad()
{
	
}


void ADataPlayerState::Load(uint64 ActorId)
{
	if(ensure(DataAccessComponent))
	{
		DataAccessComponent->LoadActorState(ActorId);
	}
}

void ADataPlayerState::InitializeDataComponent()
{
	TSubclassOf<UDataAccessComponent> DataClass;
	switch(GetNetMode())
	{
	case NM_Client :
		{
			DataClass = ClientDataClass;
			break;
		}
	case NM_DedicatedServer :
		{
			DataClass = ServerDataClass;
			break;
		}
	case NM_ListenServer :
	case NM_Standalone :
		{
			DataClass = SingleDataClass;
			break;
		}
	default :
		break;
	}
	DataAccessComponent = Cast<UDataAccessComponent>(AddComponentByClass(DataClass, false, FTransform(), false));
	DataAccessComponent->SetIsReplicated(true);
	DataAccessComponent->GetDataLoaded().AddDynamic(this, &ADataPlayerState::Multicast_PostLoad);
}

