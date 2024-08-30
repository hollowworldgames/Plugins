// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "FantasyCharacterBase.h"
#include "FantasyCharacterTags.h"
#include "GameplayTagContainer.h"
#include "Interactor.h"
#include "Quests/Public/Interfaces/QuestReceiverInterface.h"
#include "FantasyPlayerCharacter.generated.h"

struct FGameplayTag;
class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

UCLASS()
class FANTASYCHARACTER_API AFantasyPlayerCharacter : public AFantasyCharacterBase, public IQuestReceiverInterface, public IInteractor
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFantasyPlayerCharacter();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual UAbilitySystemComponent * GetAbilitySystemComponent() const override;
	virtual UDataAccessComponent * GetDataAccessComponent() const override;
	virtual UQuestReceiverComponent * GetQuestComponent() override;
	virtual void OfferQuest(UQuestData * Quest) override;
	virtual void QuestDone(UQuestData * Quest) override;
	virtual void QuestInteractionAvailable(TScriptInterface<IQuestGiverInterface> NewGiver) override;
	virtual void QuestInteractionUnavailable(TScriptInterface<IQuestGiverInterface> RemoveGiver) override;
	virtual void OnInteractableAvailable(TScriptInterface<IInteractable> Interactable) override;
	virtual void OnInteractableUnavailable(TScriptInterface<IInteractable> Interactable) override;
	virtual void OnInteractionBegin(TScriptInterface<IInteractable> Interactable) override;
	virtual void OnInteractionEnd(TScriptInterface<IInteractable> Interactable) override;
	virtual APawn * GetInteractingPawn() override;
	virtual AController * GetInteractingController() override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
		
	void AbilityOnePressed(FGameplayTag Tag, float Value, bool Axis);
	void AbilityTwoPressed(FGameplayTag Tag, float Value, bool Axis);
	void AbilityThreePressed(FGameplayTag Tag, float Value, bool Axis);
	void AbilityFourPressed(FGameplayTag Tag, float Value, bool Axis);
	void AbilityFivePressed(FGameplayTag Tag, float Value, bool Axis);
	void AbilitySixPressed(FGameplayTag Tag, float Value, bool Axis);
	void AbilitySevenPressed(FGameplayTag Tag, float Value, bool Axis);
	void AbilityEightPressed(FGameplayTag Tag, float Value, bool Axis);
	void AbilityNinePressed(FGameplayTag Tag, float Value, bool Axis);
	void AbilityZeroPressed(FGameplayTag Tag, float Value, bool Axis);
	void AbilityOneReleased(FGameplayTag Tag, float Value, bool Axis);
	void AbilityTwoReleased(FGameplayTag Tag, float Value, bool Axis);
	void AbilityThreeReleased(FGameplayTag Tag, float Value, bool Axis);
	void AbilityFourReleased(FGameplayTag Tag, float Value, bool Axis);
	void AbilityFiveReleased(FGameplayTag Tag, float Value, bool Axis);
	void AbilitySixReleased(FGameplayTag Tag, float Value, bool Axis);
	void AbilitySevenReleased(FGameplayTag Tag, float Value, bool Axis);
	void AbilityEightReleased(FGameplayTag Tag, float Value, bool Axis);
	void AbilityNineReleased(FGameplayTag Tag, float Value, bool Axis);
	void AbilityZeroReleased(FGameplayTag Tag, float Value, bool Axis);

	void MoveForward(FGameplayTag Tag, float Value, bool Axis);
	void MoveSlide(FGameplayTag Tag, float Value, bool Axis);
	void TurnPitch(FGameplayTag Tag, float Value, bool Axis);
	void TurnYaw(FGameplayTag Tag, float Value, bool Axis);
	void DoJump(FGameplayTag Tag, float Value, bool Axis);
	void Interact(FGameplayTag Tag, float Value, bool Axis);
	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	TObjectPtr<UViewPointComponent> ThirdPersonView;

	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	FGameplayTag MoveForwardTag = OutputForwardTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	FGameplayTag MoveSlideTag = OutputSlideTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	FGameplayTag TurnYawTag = OutputYawTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	FGameplayTag TurnPitchTag = OutputPitchTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	FGameplayTag JumpTag = OutputJumpTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	FGameplayTag InteractTag = OutputInteractTag;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	FGameplayTag Ability1Action = OutputAbility1Tag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	FGameplayTag Ability2Action = OutputAbility2Tag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	FGameplayTag Ability3Action = OutputAbility3Tag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	FGameplayTag Ability4Action = OutputAbility4Tag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	FGameplayTag Ability5Action = OutputAbility5Tag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	FGameplayTag Ability6Action = OutputAbility6Tag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	FGameplayTag Ability7Action = OutputAbility7Tag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	FGameplayTag Ability8Action = OutputAbility8Tag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	FGameplayTag Ability9Action = OutputAbility9Tag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	FGameplayTag Ability0Action = OutputAbility0Tag;

	TScriptInterface<IInteractable> AvailableInteraction;
};



