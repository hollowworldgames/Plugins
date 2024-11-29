// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SpaceCharacterPlayer.h"
#include "SpaceCharacterXRPlayer.generated.h"

class UMotionControllerComponent;
class UXRViewPointComponent;

UCLASS(BlueprintType, Blueprintable)
class CHARACTER_API ASpaceCharacterXRPlayer : public ASpaceCharacterPlayer
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASpaceCharacterXRPlayer();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** ViewPoint behind the character */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Camera)
	TObjectPtr<UXRViewPointComponent> HeadViewPoint;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Camera)
	TObjectPtr<UCameraComponent> Camera;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Camera)
	TObjectPtr<UMotionControllerComponent> LeftHand;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Camera)
	TObjectPtr<UMotionControllerComponent> RightHand;
};
