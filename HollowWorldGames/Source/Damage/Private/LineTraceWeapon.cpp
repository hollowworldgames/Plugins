// (c) Copyright 2023 Hollow World Games All Rights Reserved


#include "LineTraceWeapon.h"

#include "ConverterStatics.h"
#include "UtilityStatics.h"
#include "Kismet/GameplayStatics.h"
#include "Targetable.h"


// Sets default values for this component's properties
ULineTraceWeapon::ULineTraceWeapon()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void ULineTraceWeapon::DoDamage(AActor* Actor, const FHitResult& HitResult)
{
	if(Actor->Implements<UTargetable>())
	{
		APawn * Pawn = GetOwner<APawn>();
		if(ensure(Pawn))
		{
			UGameplayStatics::ApplyPointDamage(Actor, MaxDamage,UUtilityStatics::GetVectorTo(GetComponentLocation(), HitResult.ImpactPoint), HitResult, Pawn->GetController() , Pawn, DamageClass);
			
		}
	}
	else
	{
		OnImpact.Broadcast(Actor, HitResult.ImpactPoint, HitResult.ImpactNormal);
	}
}

// Called when the game starts
void ULineTraceWeapon::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void ULineTraceWeapon::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	Cooldown = FMath::Clamp(Cooldown - DeltaTime, 0.0, FireRate);
	if(CanFire())
	{
		Fire();
	}
}

void ULineTraceWeapon::Fire()
{
	if(GetWorld())
	{
		FHitResult HitResult;
		if(GetWorld()->LineTraceSingleByChannel(HitResult, GetComponentLocation(), GetComponentLocation() , ECC_Pawn))
		{
			if(AActor * Actor = HitResult.GetActor())
			{
				OnFireAt(GetComponentLocation(), HitResult.ImpactPoint);
				DoDamage(Actor, HitResult);
			}
		}
		else
		{
			OnFireAt(GetComponentLocation(), GetComponentLocation() + GetForwardVector() * UConverterStatics::KmToUUnits(MaxRangeKM));
		}
	}
}

bool ULineTraceWeapon::CanFire()
{
	return Trigger && Cooldown == 0;
}

