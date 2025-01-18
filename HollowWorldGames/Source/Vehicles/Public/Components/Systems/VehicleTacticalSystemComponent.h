// Copyright (c) 2024 Hollow World Games llc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GenericTeamAgentInterface.h"
#include "SystemComponent.h"
#include "VehicleTacticalSystemComponent.generated.h"

class UWeaponStationComponent;

USTRUCT(BlueprintType)
struct FWeaponGroup
{
	GENERATED_BODY()
	public :
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Weapons)
	TArray<TObjectPtr<UWeaponStationComponent>> Weapons;
};

USTRUCT(BlueprintType)
struct FTargetTrack
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tracks")
	TWeakObjectPtr<AActor> Target;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tracks")
	FVector Location;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tracks")
	FRotator Rotation;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tracks")
	TEnumAsByte<ETeamAttitude::Type> Attitude;
	void UpdateTrackInfo(AActor* Track, AActor * Tracker);
	void TickTrack(float DeltaTime) { Expiration -= DeltaTime; }
	bool IsExpired() const { return Expiration < 0.0f; }
	float Expiration = 1.0f;
};


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class VEHICLES_API UVehicleTacticalSystemComponent : public USystemComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UVehicleTacticalSystemComponent();
	void UpdateTrack(const TScriptInterface<class ITargetable>& Targetable);
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
							   FActorComponentTickFunction* ThisTickFunction) override;
	void OnPressTrigger(int WeaponGroup);
	void OnReleaseTrigger(int WeaponGroup);
	TArray<FTargetTrack> GetTargetTracks() const;
	FTargetTrack GetCurrentTrack() const;
protected:
	bool IsDetectable(const TScriptInterface<class ITargetable>& Targetable) const;
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category = "Weapons")
	TArray<TObjectPtr<UWeaponStationComponent>> Weapons;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category = "Weapons")
	TMap<int, FWeaponGroup> WeaponGroups;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category = "Target")
	TMap<int, FTargetTrack> Tracks;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category = "Transient")
	int CurrentTarget = 0;
	float SignalStrength = 0;
};
