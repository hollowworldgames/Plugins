// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "Data/InputMapDefaultsData.h"
#include "GameplayTagContainer.h"
#include "InputMappingComponent.generated.h"

class UInputMappingContext;
class UOutputsUsedData;

USTRUCT(BlueprintType)
struct FInputAvailable
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input)
	TObjectPtr<UInputAction> Action;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input)
	FGameplayTag InputTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input)
	bool Axis = false;
};

UCLASS(Blueprintable, BlueprintType)
class UInputDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input)
	TArray<FInputAvailable> Inputs;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FInputNotify, FGameplayTag, Input, float, Value, bool, Axis);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Abstract, Blueprintable)
class INPUTMAPPING_API UInputMappingComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UInputMappingComponent();
	void InitializeInputs();
	void LoadDefaultMapping(FString Mapping);
	void SetMapping(TArray<FInputMapping> Mappings);
	void LoadMapping(FString Path);
	void SaveMapping(FString Path);
	template<class UserClass, typename Function> void BindAction(FGameplayTag Output, ETriggerEvent Event, UserClass Class, Function Func);
protected:
	void OnTriggered(const FInputActionValue& Value, bool Axis, FGameplayTag Input);
	void OnReleased(const FInputActionValue& Value, bool Axis, FGameplayTag Input);
	void OnOngoing(const FInputActionValue& Value, bool Axis, FGameplayTag Input);
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Mappings)
	TArray<TObjectPtr<UInputMapDefaultsData>> Defaults;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Output)
	TObjectPtr<UOutputsUsedData> Outputs;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input)
	TObjectPtr<UInputDataAsset> Inputs;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category=Mapping)
	TMap<FGameplayTag, FInputMapping> CurrentMap;
	UPROPERTY(VisibleAnywhere, Transient,  Category=Mapping)
	TMap<FGameplayTag, FInputNotify> TriggerNotifies;
	UPROPERTY(VisibleAnywhere, Transient,  Category=Mapping)
	TMap<FGameplayTag, FInputNotify> OngoingNotifies;
	UPROPERTY(VisibleAnywhere, Transient,  Category=Mapping)
	TMap<FGameplayTag, FInputNotify> CompleteNotifies;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input)
	TArray<TObjectPtr<UInputMappingContext>> Contexts;
};


template <class UserClass, typename Function>
void UInputMappingComponent::BindAction(FGameplayTag Output, ETriggerEvent Event, UserClass Class, Function Func)
{
	switch(Event)
	{
	case ETriggerEvent::Triggered :
		{
			if(TriggerNotifies.Contains(Output))
			{
				TriggerNotifies[Output].AddDynamic(Class, Func);
			}
			break;
		}
	case ETriggerEvent::Ongoing :
		{
			if(OngoingNotifies.Contains(Output))
			{
				OngoingNotifies[Output].AddDynamic(Class, Func);
			}
			break;
		}
	case ETriggerEvent::Completed :
		{
			if(CompleteNotifies.Contains(Output))
			{
				CompleteNotifies[Output].AddDynamic(Class, Func);
			}
			break;
		}
	default :
		{
			ensure(false);
		}
	}
}
