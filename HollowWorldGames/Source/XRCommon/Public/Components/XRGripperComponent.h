// Copyright (c) 2024 Hollow World Games llc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "XRGripSystemComponent.h"
#include "Components/BoxComponent.h"
#include "Interfaces/GrippableInterface.h"
#include "XRGripperComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class XRCOMMON_API UXRGripperComponent : public UBoxComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UXRGripperComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	EControllerHand GetControllerHand() const { return Hand; }
	void Grip(const TScriptInterface<IGrippableInterface>& Grippable);
	void Release();
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hand")
	EControllerHand Hand = EControllerHand::Left;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Gripped")
	TScriptInterface<IGrippableInterface> Gripped;
};
