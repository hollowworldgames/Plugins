// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/DataCharacter.h"

#include "Actors/DataPlayerState.h"
#include "Components/DataAccessComponent.h"


// Sets default values
ADataCharacter::ADataCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ADataCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ADataCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	Save();
}

// Called every frame
void ADataCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ADataCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ADataCharacter::Load(int64 NewActorId)
{
	ActorId = NewActorId;
	if(ensure(DataAccessComponent))
	{
		DataAccessComponent->LoadActorState(ActorId);
	}
	
}

void ADataCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	ADataPlayerState * DataPlayerState = Cast<ADataPlayerState>(GetPlayerState());
	if(ensure(DataPlayerState))
	{
		DataPlayerState->InitializeDataComponent();
		DataAccessComponent = DataPlayerState->GetDataAccessComponent();
	}
}

void ADataCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	if(!NewController->IsPlayerController())
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
		if (DataClass)
		{
			DataAccessComponent = Cast<UDataAccessComponent>(AddComponentByClass(DataClass, false, FTransform(), false));
			DataAccessComponent->SetIsReplicated(true);
			DataAccessComponent->GetDataLoaded().AddDynamic(this, &ADataCharacter::Multicast_PostLoad);
		}
	}
}

void ADataCharacter::Save() const
{
	if(ensure(DataAccessComponent))
	{
		OnPrepareSave();
		DataAccessComponent->SaveActorState();
	}
}

void ADataCharacter::OnLoaded()
{

}

void ADataCharacter::OnPrepareSave() const
{
	//Derived Class Will write attributes and such here to update persistence
}

void ADataCharacter::Multicast_PostLoad_Implementation()
{
	
	OnLoaded();
}
