// Copyright (c) 2024 Hollow World Games llc. All Rights Reserved.


#include "Components/Systems/VehicleTacticalSystemComponent.h"

#include "Targetable.h"
#include "UtilityStatics.h"
#include "Components/WeaponStationComponent.h"
#include "Kismet/GameplayStatics.h"


void FSensorPing::UpdateTrackInfo(const AActor* Track, const AActor* Tracker, const int Class)
{
	Direction = UUtilityStatics::GetDirectionTo(Track->GetActorLocation(), Tracker->GetActorLocation());
	Expiration = 1.0f;
	PingClass = Class;
}

void FSensorTargetTrack::UpdateTrackInfo(AActor* Track, AActor* Tracker)
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
UVehicleTacticalSystemComponent::UVehicleTacticalSystemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UVehicleTacticalSystemComponent::BeginPlay()
{
	Super::BeginPlay();

	GetOwner()->GetComponents(Weapons);
}

void UVehicleTacticalSystemComponent::UpdateTrack(const TScriptInterface<class ITargetable>& Targetable)
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

void UVehicleTacticalSystemComponent::UpdatePing(const TScriptInterface<class ITargetable>& Targetable)
{
	if (Pings.Contains(Targetable->GetId()))
	{
		Pings[Targetable->GetId()].UpdateTrackInfo(Targetable->GetActor(), GetOwner(), 0);
	}
	else
	{
		Pings.Add(Targetable->GetId()).UpdateTrackInfo(Targetable->GetActor(), GetOwner(), 0);
	}
}

// Called every frame
void UVehicleTacticalSystemComponent::TickComponent(float DeltaTime, ELevelTick TickType,
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
	CheckForExpiredTracks(DeltaTime);
	CheckForExpiredPings(DeltaTime);
}

void UVehicleTacticalSystemComponent::CheckForExpiredTracks(float DeltaTime)
{
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

void UVehicleTacticalSystemComponent::CheckForExpiredPings(float DeltaTime)
{
	TArray<int> ToRemove;

	for (auto Track : Pings)
	{
		Track.Value.TickTrack(DeltaTime);
		if (Track.Value.IsExpired())
		{
			ToRemove.Add(Track.Key);
		}
	}

	for (const auto Remove : ToRemove)
	{
		Pings.Remove(Remove);
	}
}

void UVehicleTacticalSystemComponent::OnPressTrigger(int WeaponGroup)
{
	if (WeaponGroups.Contains(WeaponGroup))
	{
		FWeaponGrouping Group = WeaponGroups[WeaponGroup];
		for (TObjectPtr Weapon : Group.Weapons)
		{
			Weapon->SetTriggerPressed();
		}
	}
}

void UVehicleTacticalSystemComponent::OnReleaseTrigger(int WeaponGroup)
{
	if (WeaponGroups.Contains(WeaponGroup))
	{
		FWeaponGrouping Group = WeaponGroups[WeaponGroup];
		for (TObjectPtr Weapon : Group.Weapons)
		{
			Weapon->SetTriggerReleased();
		}
	}
}

TArray<FSensorTargetTrack> UVehicleTacticalSystemComponent::GetTargetTracks() const
{
	TArray<FSensorTargetTrack> OutputTracks;
	for (auto Track : Tracks)
	{
		OutputTracks.Add(Track.Value);
	}
	return OutputTracks;
}

FSensorTargetTrack UVehicleTacticalSystemComponent::GetCurrentTrack() const
{
	if (Tracks.Contains(CurrentTarget))
	{
		return Tracks[CurrentTarget];
	}
	return FSensorTargetTrack();
}

void UVehicleTacticalSystemComponent::OnTrackedBy(TScriptInterface<ITargetable> Tracker)
{
	
}

bool UVehicleTacticalSystemComponent::IsDetectable(const TScriptInterface<class ITargetable>& Targetable) const
{
	double Distance = FVector::Distance(GetOwner()->GetActorLocation(),Targetable->GetLocation());
	double Visible = Targetable->GetSignature() * SignalStrength / Distance;
 	if (Visible > 1.0)
 	{
 		FHitResult Hit;
 		FVector Location = GetOwner()->GetActorLocation();
 		FCollisionQueryParams Params;
 		Params.AddIgnoredActor(GetOwner());
 		if (GetWorld()->LineTraceSingleByChannel(Hit,Location, Targetable->GetLocation(), ECC_WorldDynamic, Params) && Hit.GetActor() == Targetable->GetActor())
 		{
			return true;	
 		}
 	}
	return false;
}
