// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Actors/XRHandActor.h"
#include "ViewPoints/Public/Components/ViewPointComponent.h"
#include "XRViewPointComponent.generated.h"

class AXRHandActor;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class XRCOMMON_API UXRViewPointComponent : public UViewPointComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UXRViewPointComponent();
	// Called every frame
	virtual void MakeActive() override;
	virtual void MakeInactive() override;
	UMotionControllerComponent* GetMotionController(EHand Hand) const;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	bool Avatar = false;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category=Components)
	TObjectPtr<UMotionControllerComponent> RightHand;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category=Components)
	TObjectPtr<UMotionControllerComponent> LeftHand;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category=Components)
    TObjectPtr<AXRHandActor> RightHandActor;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category=Components)
	TObjectPtr<AXRHandActor> LeftHandActor;
};
