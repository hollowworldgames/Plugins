// Copyright (c) 2024 Hollow World Games llc. All Rights Reserved.


#include "Components/Systems/VehicleTacticalSystemComponent.h"

#include "Targetable.h"
#include "UtilityStatics.h"
#include "Components/WeaponStationComponent.h"
#include "Kismet/GameplayStatics.h"


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

void UVehicleTacticalSystemComponent::OnPressTrigger(int WeaponGroup)
{
	if (WeaponGroups.Contains(WeaponGroup))
	{
		FWeaponGroup Group = WeaponGroups[WeaponGroup];
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
		FWeaponGroup Group = WeaponGroups[WeaponGroup];
		for (TObjectPtr Weapon : Group.Weapons)
		{
			Weapon->SetTriggerReleased();
		}
	}
}

TArray<FTargetTrack> UVehicleTacticalSystemComponent::GetTargetTracks() const
{
	TArray<FTargetTrack> OutputTracks;
	for (auto Track : Tracks)
	{
		OutputTracks.Add(Track.Value);
	}
	return OutputTracks;
}

FTargetTrack UVehicleTacticalSystemComponent::GetCurrentTrack() const
{
	if (Tracks.Contains(CurrentTarget))
	{
		return Tracks[CurrentTarget];
	}
	return FTargetTrack();
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