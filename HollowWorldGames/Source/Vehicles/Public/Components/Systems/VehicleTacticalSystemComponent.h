// Copyright (c) 2024 Hollow World Games llc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GenericTeamAgentInterface.h"
#include "SystemComponent.h"
#include "VehicleTacticalSystemComponent.generated.h"

class UWeaponStationComponent;

USTRUCT(BlueprintType)
struct FWeaponGrouping
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Weapons)
	TArray<TObjectPtr<UWeaponStationComponent>> Weapons;
};

USTRUCT(BlueprintType)
struct FSensorTargetTrack
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

USTRUCT(BlueprintType)
struct FSensorPing
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ping")
	TWeakObjectPtr<AActor> Source;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ping")
	FVector Direction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ping")
	int PingClass = 0;
	void UpdateTrackInfo(const AActor* Track, const AActor * Tracker, int Class);
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
	void UpdatePing(const TScriptInterface<class ITargetable>& Targetable);
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
							   FActorComponentTickFunction* ThisTickFunction) override;
	void OnPressTrigger(int WeaponGroup);
	void OnReleaseTrigger(int WeaponGroup);
	TArray<FSensorTargetTrack> GetTargetTracks() const;
	FSensorTargetTrack GetCurrentTrack() const;
	void OnTrackedBy(TScriptInterface<ITargetable> Tracker);
protected:
	void CheckForExpiredTracks(float DeltaTime);
	void CheckForExpiredPings(float DeltaTime);
	bool IsDetectable(const TScriptInterface<class ITargetable>& Targetable) const;
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category = "Weapons")
	TArray<TObjectPtr<UWeaponStationComponent>> Weapons;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category = "Weapons")
	TMap<int, FWeaponGrouping> WeaponGroups;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category = "Target")
	TMap<int, FSensorTargetTrack> Tracks;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category = "Target")
	TMap<int, FSensorPing> Pings;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category = "Transient")
	int CurrentTarget = 0;
	float SignalStrength = 0;
};


