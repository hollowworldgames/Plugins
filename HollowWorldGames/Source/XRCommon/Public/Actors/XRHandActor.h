// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "XRHandActor.generated.h"

UENUM(BlueprintType)
enum class EHand : uint8
{
	Left UMETA(DisplayName = "Left"),
	Right UMETA(DisplayName = "Right"),
};

UCLASS()
class XRCOMMON_API AXRHandActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AXRHandActor();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	EHand GetHand() const { return Hand; }
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hand")
	EHand Hand = EHand::Left;
};
