// (c) Copyright 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerInputComponent.generated.h"

class UPlayerInputConfig;
class UMappedInputComponent;
class UInputMappingContext;

USTRUCT(BlueprintType)
struct FInputMappingContextAndPriority
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category="Input", meta=(AssetBundles="Client,Server"))
	TObjectPtr<UInputMappingContext> InputMapping;

	// Higher priority input mappings will be prioritized over mappings with a lower priority.
	UPROPERTY(EditAnywhere, Category="Input")
	int32 Priority = 0;
	
	/** If true, then this mapping context will be registered with the settings when this game feature action is registered. */
	UPROPERTY(EditAnywhere, Category="Input")
	bool bRegisterWithSettings = true;

	UPROPERTY(EditAnywhere, Category="Input")
	FName Name;
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class INPUTMAPPING_API UPlayerInputComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UPlayerInputComponent();
	virtual void InitializePlayerInput(UMappedInputComponent* InputComponent);
	// Called every frame
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void ClearMappings();
	virtual void SwitchToAlternate(int Alternate);
	virtual void SwitchToDefaults();
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void MapInputs(UMappedInputComponent* InputComponent);
	UFUNCTION()
	void Input_AbilityInputTagPressed(FGameplayTag InputTag);
	UFUNCTION()
	void Input_AbilityInputTagReleased(FGameplayTag InputTag);
	UPROPERTY(EditAnywhere, Category=Config)
	TObjectPtr<UPlayerInputConfig> InputConfig;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input)
	TArray<FInputMappingContextAndPriority> DefaultInputMappings;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input)
	TArray<FInputMappingContextAndPriority> AlternateInputMappings;
};
