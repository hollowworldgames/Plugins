// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/TacticalSystemComponent.h"

#include "Targetable.h"
#include "Kismet/GameplayStatics.h"
#include "Weapons/WeaponActorComponent.h"


void FTargetTrack::UpdateTrackInfo(AActor* Track, AActor* Tracker)
{
	Target = Track;
	Location = Track->GetActorLocation();
	Rotation = Track->GetActorRotation();
	if (const IGenericTeamAgentInterface * GenericTeamAgent = Cast<IGenericTeamAgentInterface>(Track))
	{
		Attitude = GenericTeamAgent->GetTeamAttitudeTowards(*Tracker);
	}
}

// Sets default values for this component's properties
UTacticalSystemComponent::UTacticalSystemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTacticalSystemComponent::UpdateTrack(const TScriptInterface<class ITargetable>& Targetable)
{
	if (Tracks.Contains(Targetable->GetId()))
	{
		Tracks[Targetable->GetId()].UpdateTrackInfo(Targetable->GetActor(), GetOwner());
	}
	else
	{
		Tracks.Add(Targetable->GetId()).UpdateTrackInfo(Targetable->GetActor(), GetOwner());
	}
}


// Called when the game starts
void UTacticalSystemComponent::BeginPlay()
{
	Super::BeginPlay();

	GetOwner()->GetComponents(Weapons);
	
}


// Called every frame
void UTacticalSystemComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                             FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	TArray<AActor*> Actors;
	UGameplayStatics::GetAllActorsWithInterface(this, UTargetable::StaticClass(), Actors);
	for (AActor* Actor : Actors)
	{
		if (TScriptInterface<ITargetable> Targetable = TObjectPtr<AActor>(Actor))
		{
			if (IsDetectable(Targetable))
			{
				UpdateTrack(Targetable);
				Targetable->NotifyTracking(TObjectPtr<AActor>(GetOwner()));
			}
		}
	}

	TArray<int> ToRemove;

	for (auto Track : Tracks)
	{
		Track.Value.TickTrack(DeltaTime);
		if (Track.Value.IsExpired())
		{
			ToRemove.Add(Track.Key);
		}
	}

	for (const auto Remove : ToRemove)
	{
		Tracks.Remove(Remove);
	}
}

void UTacticalSystemComponent::OnPressTrigger(int WeaponGroup)
{
	if (WeaponGroups.Contains(WeaponGroup))
	{
		FWeaponGroup Group = WeaponGroups[WeaponGroup];
		for (TObjectPtr<UWeaponActorComponent> Weapon : Group.Weapons)
		{
			Weapon->SetTriggerPressed();
		}
	}
}

void UTacticalSystemComponent::OnReleaseTrigger(int WeaponGroup)
{
	if (WeaponGroups.Contains(WeaponGroup))
	{
		FWeaponGroup Group = WeaponGroups[WeaponGroup];
		for (TObjectPtr<UWeaponActorComponent> Weapon : Group.Weapons)
		{
			Weapon->SetTriggerReleased();
		}
	}
}


TArray<FTargetTrack> UTacticalSystemComponent::GetTargetTracks() const
{
	TArray<FTargetTrack> OutputTracks;
	for (auto Track : Tracks)
	{
		OutputTracks.Add(Track.Value);
	}
	return OutputTracks;
}

FTargetTrack UTacticalSystemComponent::GetCurrentTrack() const
{
	if (Tracks.Contains(CurrentTarget))
	{
		return Tracks[CurrentTarget];
	}
	return FTargetTrack();
}

bool UTacticalSystemComponent::IsDetectable(const TScriptInterface<class ITargetable>& Targetable) const
{
	double Visible = Targetable->GetSignature() * SignalStrength / FVector::Distance(GetOwner()->GetActorLocation(),Targetable->GetLocation());
	return Visible > 1.0f;
}
