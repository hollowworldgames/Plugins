// (c) Copyright 2023 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DoorMovementComponent.generated.h"


UENUM(BlueprintType)
enum class EDoorState : uint8
{
	EDoorState_Opened UMETA(DisplayName = "Opened"),
	EDoorState_Opening UMETA(DisplayName = "Opening"),
	EDoorState_Closed UMETA(DisplayName = "Closed"),
	EDoorState_Closing UMETA(DisplayName = "Closing"),
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorDelegate);	


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COMMON_API UDoorMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDoorMovementComponent();
	UFUNCTION(BlueprintCallable, CallInEditor)
	void Open();
	UFUNCTION(BlueprintCallable, CallInEditor)
	void Close();
	UFUNCTION(BlueprintCallable, CallInEditor)
	void SetOpened();
	UFUNCTION(BlueprintCallable, CallInEditor)
	void SetClosed();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ChangeTime = 1;
	UPROPERTY(EditAnywhere, BlueprintAssignable)
	FDoorDelegate OnOpen;
	UPROPERTY(EditAnywhere, BlueprintAssignable)
	FDoorDelegate OnClose;
	UPROPERTY(EditAnywhere, BlueprintAssignable)
	FDoorDelegate OnOpened;
	UPROPERTY(EditAnywhere, BlueprintAssignable)
	FDoorDelegate OnClosed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Positions")
	FVector OpenPosition;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Positions")
	FRotator OpenRotation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Positions")
	FVector ClosePosition;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Positions")
	FRotator CloseRotation;
	float ChangeDelta = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient)
	EDoorState State = EDoorState::EDoorState_Closed;
};