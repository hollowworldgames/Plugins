// Copyright (c) 2023 Hollow World Games llc. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "RaiseLowerComponent.generated.h"

UENUM(BlueprintType)
enum class ERaiseLowerState : uint8
{
	ERaiseLowerState_Raised UMETA(DisplayName = "Raised"),
	ERaiseLowerState_Rising UMETA(DisplayName = "Rising"),
	ERaiseLowerState_Lowered UMETA(DisplayName = "Lowered"),
	ERaiseLowerState_Lowering UMETA(DisplayName = "Lowering"),
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FRaiseLowerDelegate);	


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COMMON_API URaiseLowerComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URaiseLowerComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintCallable, CallInEditor)
	void Raise();
	UFUNCTION(BlueprintCallable, CallInEditor)
	void Lower();
	UFUNCTION(BlueprintCallable, CallInEditor)
	void SetRaised();
	UFUNCTION(BlueprintCallable, CallInEditor)
	void SetLowered();
	UFUNCTION(BlueprintPure)
	ERaiseLowerState GetState() const { return State; }
protected:
	// Called when the game starts
	UPROPERTY(EditAnywhere, BlueprintAssignable)
	FRaiseLowerDelegate OnRaise;
	UPROPERTY(EditAnywhere, BlueprintAssignable)
	FRaiseLowerDelegate OnLower;
	UPROPERTY(EditAnywhere, BlueprintAssignable)
	FRaiseLowerDelegate OnRaised;
	UPROPERTY(EditAnywhere, BlueprintAssignable)
	FRaiseLowerDelegate OnLowered;
	UPROPERTY(EditAnywhere, BlueprintAssignable)
	FRaiseLowerDelegate StartSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Positions")
	FVector RaisePosition;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Positions")
	FRotator RaiseRotation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Positions")
	FVector LowerPosition;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Positions")
	FRotator LowerRotation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ChangeTime = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ChangeDelayLower = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ChangeDelayRaise = 1;
	float ChangeDelta = 0;
	float DelayDelta = -1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient)
	ERaiseLowerState State = ERaiseLowerState::ERaiseLowerState_Lowered;
};
