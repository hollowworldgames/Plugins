// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "ViewPoints/Public/Components/ViewPointComponent.h"
#include "XRViewPointComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class XRCOMMON_API UXRViewPointComponent : public UViewPointComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UXRViewPointComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category=Components)
	TObjectPtr<UMotionControllerComponent> RightHand;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category=Components)
	TObjectPtr<UMotionControllerComponent> LeftHand;
};
