// Copyright (c) 2023 Hollow World Games llc. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "OpenCloseComponent.generated.h"


class USoundCue;

UENUM(BlueprintType)
enum class EOpenCloseState : uint8
{
	EOpenCloseState_Opened UMETA(DisplayName = "Opened"),
	EOpenCloseState_Opening UMETA(DisplayName = "Opening"),
	EOpenCloseState_Closed UMETA(DisplayName = "Closed"),
	EOpenCloseState_Closing UMETA(DisplayName = "Closing"),
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOpenCloseDelegate);	

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COMMON_API UOpenCloseComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenCloseComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintCallable, CallInEditor, Category = "Open Close")
	void Open();
	UFUNCTION(BlueprintCallable, CallInEditor, Category = "Open Close")
	void Close();
	UFUNCTION(BlueprintCallable, CallInEditor, Category = "Open Close")
	void SetOpened();
	UFUNCTION(BlueprintCallable, CallInEditor, Category = "Open Close")
	void SetClosed();
	EOpenCloseState GetState() const { return State; }
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	float ChangeTime = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	float DelayTime = 1;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FOpenCloseDelegate OnOpen;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FOpenCloseDelegate OnClose;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FOpenCloseDelegate OnOpened;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category=Events)
	FOpenCloseDelegate OnClosed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Positions")
	FVector OpenPosition;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Positions")
	FRotator OpenRotation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Positions")
	FVector ClosePosition;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Positions")
	FRotator CloseRotation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Audio)
	USoundCue * Sound;
	float ChangeDelta = 0;
	float DelayDelta = -1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category = "Status")
	EOpenCloseState State = EOpenCloseState::EOpenCloseState_Closed;
};
