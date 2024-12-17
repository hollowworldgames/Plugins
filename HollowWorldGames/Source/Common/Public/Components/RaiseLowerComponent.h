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
	UFUNCTION(BlueprintCallable, CallInEditor, Category = "RaiseLower")
	void Raise();
	UFUNCTION(BlueprintCallable, CallInEditor, Category = "RaiseLower")
	void Lower();
	UFUNCTION(BlueprintCallable, CallInEditor, Category = "RaiseLower")
	void SetRaised();
	UFUNCTION(BlueprintCallable, CallInEditor, Category = "RaiseLower")
	void SetLowered();
	UFUNCTION(BlueprintPure, Category = "RaiseLower")
	ERaiseLowerState GetState() const { return State; }
protected:
	// Called when the game starts
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category = "Events")
	FRaiseLowerDelegate OnRaise;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category = "Events")
	FRaiseLowerDelegate OnLower;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category = "Events")
	FRaiseLowerDelegate OnRaised;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category = "Events")
	FRaiseLowerDelegate OnLowered;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category = "Events")
	FRaiseLowerDelegate StartSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Positions")
	FVector RaisePosition;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Positions")
	FRotator RaiseRotation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Positions")
	FVector LowerPosition;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Positions")
	FRotator LowerRotation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	float ChangeTime = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="Settings")
	float ChangeDelayLower = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="Settings")
	float ChangeDelayRaise = 1;
	float ChangeDelta = 0;
	float DelayDelta = -1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category = "Status")
	ERaiseLowerState State = ERaiseLowerState::ERaiseLowerState_Lowered;
};
