// Copyright (c) 2024 Hollow World Games llc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "XRReplicationComponent.generated.h"


class UXRHandProxyComponent;
class UXRHeadProxyComponent;
class UMotionControllerComponent;
class UCameraComponent;
class UFloatVariableAsset;

USTRUCT(BlueprintType)
struct FXRReplicatedPosition
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector HeadPosition;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator HeadRotation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector LeftPosition;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator LeftRotation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector RightPosition;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator RightRotation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Sequence = 0;
	FXRReplicatedPosition() = default;
	FXRReplicatedPosition(const FVector& NewHeadPosition, const FRotator& NewHeadRotation,
		const FVector& NewLeftHandPosition, const FRotator& NewLeftHandRotation,
		const FVector& NewRightHandPosition, const FRotator& NewRightHandRotation, int Sequence);
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class XRCOMMON_API UXRReplicationComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UXRReplicationComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
							   FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintPure, Category="XR Transforms")
	FTransform GetHeadTransform() const;
	UFUNCTION(BlueprintPure, Category="XR Transforms")
	FTransform GetLeftTransform() const;
	UFUNCTION(BlueprintPure, Category="XR Transforms")
	FTransform GetRightTransform() const;
protected:
	UFUNCTION(Server, Unreliable)
	void ReplicateXRPositionRotation_Server(FVector HeadPosition, FRotator HeadRotation,
		FVector LeftHandPosition, FRotator LeftHandRotation, FVector RightHandPosition, FRotator RightHandRotation, int Sequence);
	UFUNCTION(NetMulticast, Unreliable)
	void ReplicateXRPositionRotation_Multicast(FVector HeadPosition, FRotator HeadRotation,
		FVector LeftHandPosition, FRotator LeftHandRotation, FVector RightHandPosition, FRotator RightHandRotation, int Sequence);
	void AddReplicatedPosition(const FVector& HeadPosition, const FRotator& HeadRotation,
		const FVector& LeftHandPosition, const FRotator& LeftHandRotation, const FVector& RightHandPosition, const FRotator& RightHandRotation, const int& Sequence);
	// Called when the game starts
	virtual void BeginPlay() override;
	bool IsLocallySimulated() const;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Status")
	float ReplicateTime = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Replication")
	TObjectPtr<UFloatVariableAsset> ReplicationFrequency;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	TObjectPtr<UCameraComponent> HeadComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	TObjectPtr<UMotionControllerComponent> LeftComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	TObjectPtr<UMotionControllerComponent> RightComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	TObjectPtr<UXRHeadProxyComponent> HeadProxyComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	TObjectPtr<UXRHandProxyComponent> LeftProxyComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	TObjectPtr<UXRHandProxyComponent> RightProxyComponent;
	int NextSequence = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Replication")
	TArray<FXRReplicatedPosition> ReplicatedPositions;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Replication")
	FXRReplicatedPosition PreviousReplicatedPosition;
};
