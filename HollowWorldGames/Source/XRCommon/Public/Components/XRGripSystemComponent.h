// Copyright (c) 2024 Hollow World Games llc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "XRGripSystemComponent.generated.h"


class IGrippableInterface;
class UXRHandProxyComponent;
class UXRGripperComponent;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class XRCOMMON_API UXRGripSystemComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UXRGripSystemComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	void Grip();
	bool HasGrippable();
protected:
	// Called when the game starts
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hands")
	TObjectPtr<UXRGripperComponent> LeftGripper;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hands")
	TObjectPtr<UXRHandProxyComponent> LeftHand;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hands")
	TObjectPtr<UXRGripperComponent> RightGripper;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hands")
	TObjectPtr<UXRHandProxyComponent> RightHand;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Hands")
	TScriptInterface<IGrippableInterface> Grippable;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Hands")
	TObjectPtr<UXRGripperComponent> Gripper;
};
