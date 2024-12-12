// Copyright (c) 2024 Hollow World Games llc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "Interfaces/gravityReceiverInterface.h"
#include "GravityReceiverComponent.generated.h"

class IGravitySourceInterface;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SPACECRAFT_API UGravityReceiverComponent : public UBoxComponent, public IGravityReceiverInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UGravityReceiverComponent();
	virtual void ApplyGravityForce(FVector GravityForce) override;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, Transient, BlueprintReadOnly, Category = "Settings")
	bool EnableGravity = true;
};
