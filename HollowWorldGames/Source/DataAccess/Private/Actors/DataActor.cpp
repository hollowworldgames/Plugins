// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/DataActor.h"
#include "Components/DataAccessComponent.h"


// Sets default values
ADataActor::ADataActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ADataActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADataActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	Save();
}

// Called every frame
void ADataActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADataActor::Load(int64 NewActorId)
{
	ActorId = NewActorId;
	TSubclassOf<UDataAccessComponent> DataClass;
	switch(GetNetMode())
	{
	case NM_Client :
		{
			//Server will create this
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
		{
			break;
		}
	}
	DataAccessComponent = Cast<UDataAccessComponent>(AddComponentByClass(DataClass, false, FTransform(), false));
	if(ensure(DataAccessComponent))
	{
		DataAccessComponent->SetIsReplicated(true);
		DataAccessComponent->GetDataLoaded().AddDynamic(this, &ADataActor::Multicast_PostLoad);
		DataAccessComponent->LoadActorState(ActorId);
	}
}

void ADataActor::Save() const
{
	if(ensure(DataAccessComponent))
	{
		OnPrepareSave();
		DataAccessComponent->SaveActorState();
	}
}

void ADataActor::OnLoaded()
{
	//Derived Class Will Setup Attributes and such here
}

void ADataActor::OnPrepareSave() const
{
	//Derived Class Will write attributes and such here to update persistence
}

void ADataActor::Multicast_PostLoad_Implementation()
{
	OnLoaded();
}

