// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "Characters/FantasyPlayerCharacter.h"
#include "Characters/FantasyPlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Player/FantasyPlayerState.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Interactable.h"
#include "Components/GameplayAbilitySystemComponent.h"
#include "Components/InputMappingComponent.h"
#include "Components/QuestReceiverComponent.h"
#include "Components/ViewPointComponent.h"
#include "Player/FantasyPlayerController.h"


// Sets default values
AFantasyPlayerCharacter::AFantasyPlayerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
		
	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;
    
	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	ThirdPersonView = CreateDefaultSubobject<UViewPointComponent>(TEXT("Third Person View"));
	ThirdPersonView->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)
}

// Called when the game starts or when spawned
void AFantasyPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFantasyPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AFantasyPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	// Set up action bindings
	if (UInputMappingComponent* EnhancedInputComponent = Cast<UInputMappingComponent>(PlayerInputComponent)) {
		
		EnhancedInputComponent->BindAction(Ability1Action, ETriggerEvent::Triggered, this, &AFantasyPlayerCharacter::AbilityOnePressed);
		EnhancedInputComponent->BindAction(Ability1Action, ETriggerEvent::Completed, this, &AFantasyPlayerCharacter::AbilityOneReleased);
		EnhancedInputComponent->BindAction(Ability2Action, ETriggerEvent::Triggered, this, &AFantasyPlayerCharacter::AbilityTwoPressed);
		EnhancedInputComponent->BindAction(Ability2Action, ETriggerEvent::Completed, this, &AFantasyPlayerCharacter::AbilityTwoReleased);
		EnhancedInputComponent->BindAction(Ability3Action, ETriggerEvent::Triggered, this, &AFantasyPlayerCharacter::AbilityThreePressed);
		EnhancedInputComponent->BindAction(Ability3Action, ETriggerEvent::Completed, this, &AFantasyPlayerCharacter::AbilityThreeReleased);
		EnhancedInputComponent->BindAction(Ability4Action, ETriggerEvent::Triggered, this, &AFantasyPlayerCharacter::AbilityFourPressed);
		EnhancedInputComponent->BindAction(Ability4Action, ETriggerEvent::Completed, this, &AFantasyPlayerCharacter::AbilityFourReleased);
		EnhancedInputComponent->BindAction(Ability5Action, ETriggerEvent::Completed, this, &AFantasyPlayerCharacter::AbilityFiveReleased);
		EnhancedInputComponent->BindAction(Ability6Action, ETriggerEvent::Completed, this, &AFantasyPlayerCharacter::AbilitySixReleased);
		EnhancedInputComponent->BindAction(Ability7Action, ETriggerEvent::Completed, this, &AFantasyPlayerCharacter::AbilitySevenReleased);
		EnhancedInputComponent->BindAction(Ability8Action, ETriggerEvent::Completed, this, &AFantasyPlayerCharacter::AbilityEightReleased);
		EnhancedInputComponent->BindAction(Ability9Action, ETriggerEvent::Completed, this, &AFantasyPlayerCharacter::AbilityNineReleased);
		EnhancedInputComponent->BindAction(Ability0Action, ETriggerEvent::Completed, this, &AFantasyPlayerCharacter::AbilityZeroReleased);

		EnhancedInputComponent->BindAction(MoveForwardTag, ETriggerEvent::Ongoing, this, &AFantasyPlayerCharacter::MoveForward);
		EnhancedInputComponent->BindAction(MoveSlideTag, ETriggerEvent::Ongoing, this, &AFantasyPlayerCharacter::MoveSlide);
		EnhancedInputComponent->BindAction(TurnPitchTag, ETriggerEvent::Ongoing, this, &AFantasyPlayerCharacter::TurnPitch);
		EnhancedInputComponent->BindAction(TurnYawTag, ETriggerEvent::Ongoing, this, &AFantasyPlayerCharacter::TurnYaw);
		EnhancedInputComponent->BindAction(JumpTag, ETriggerEvent::Completed, this, &AFantasyPlayerCharacter::DoJump);
		EnhancedInputComponent->BindAction(InteractTag, ETriggerEvent::Completed, this, &AFantasyPlayerCharacter::Interact);
	}
}

UAbilitySystemComponent* AFantasyPlayerCharacter::GetAbilitySystemComponent() const
{
	AFantasyPlayerState * State = GetPlayerState<AFantasyPlayerState>();
	if(ensure(State))
	{
		return State->GetAbilitySystemComponent();
	}
	return nullptr;
}

UDataAccessComponent* AFantasyPlayerCharacter::GetDataAccessComponent() const
{
	AFantasyPlayerState * FantasyState = Cast<AFantasyPlayerState>(GetPlayerState());
	if(ensure(FantasyState))
	{
		return FantasyState->GetDataAccessComponent();
	}
	return nullptr;
}

UQuestReceiverComponent* AFantasyPlayerCharacter::GetQuestComponent()
{
	AFantasyPlayerState * FantasyState = Cast<AFantasyPlayerState>(GetPlayerState());
	if(ensure(FantasyState))
	{
		return FantasyState->GetQuestComponent();
	}
	return nullptr;
}

void AFantasyPlayerCharacter::OfferQuest(UQuestData* Quest)
{
	AFantasyPlayerController * FantasyPlayerController = Cast<AFantasyPlayerController>(GetController());
	if(ensure(FantasyPlayerController))
	{
		FantasyPlayerController->OfferQuest_Client(Quest);
	}
}

void AFantasyPlayerCharacter::QuestDone(UQuestData* Quest)
{
	AFantasyPlayerController * FantasyPlayerController = Cast<AFantasyPlayerController>(GetController());
	if(ensure(FantasyPlayerController))
	{
		FantasyPlayerController->QuestDone_Client(Quest);
	}
}

void AFantasyPlayerCharacter::QuestInteractionAvailable(TScriptInterface<IQuestGiverInterface> NewGiver)
{
	if(UQuestReceiverComponent * ReceiverComponent = GetQuestComponent())
	{
		ReceiverComponent->OnQuestGiverAvailable(NewGiver);
	}
}

void AFantasyPlayerCharacter::QuestInteractionUnavailable(TScriptInterface<IQuestGiverInterface> RemoveGiver)
{
	if(UQuestReceiverComponent * ReceiverComponent = GetQuestComponent())
	{
		ReceiverComponent->OnQuestGiverUnavailable(RemoveGiver);
	}
}

void AFantasyPlayerCharacter::OnInteractableAvailable(TScriptInterface<IInteractable> Interactable)
{
	AvailableInteraction = Interactable;
}

void AFantasyPlayerCharacter::OnInteractableUnavailable(TScriptInterface<IInteractable> Interactable)
{
	AvailableInteraction = Interactable;
}

void AFantasyPlayerCharacter::OnInteractionBegin(TScriptInterface<IInteractable> Interactable)
{
}

void AFantasyPlayerCharacter::OnInteractionEnd(TScriptInterface<IInteractable> Interactable)
{
}

APawn* AFantasyPlayerCharacter::GetInteractingPawn()
{
	return this;
}

AController* AFantasyPlayerCharacter::GetInteractingController()
{
	return GetController();
}


void AFantasyPlayerCharacter::AbilityOnePressed(FGameplayTag Tag, float Value, bool Axis)
{
	UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(GetAbilitySystemComponent());
	if(AbilitySystemComponent)
	{
		AbilitySystemComponent->OnAbilityInputPressed(Tag);
	}
}

void AFantasyPlayerCharacter::AbilityTwoPressed(FGameplayTag Tag, float Value, bool Axis)
{
	UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(GetAbilitySystemComponent());
	if(AbilitySystemComponent)
	{
		AbilitySystemComponent->OnAbilityInputPressed(Tag);
	}
}

void AFantasyPlayerCharacter::AbilityThreePressed(FGameplayTag Tag, float Value, bool Axis)
{
	UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(GetAbilitySystemComponent());
	if(AbilitySystemComponent)
	{
		AbilitySystemComponent->OnAbilityInputPressed(Tag);
	}
}

void AFantasyPlayerCharacter::AbilityFourPressed(FGameplayTag Tag, float Value, bool Axis)
{
	UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(GetAbilitySystemComponent());
	if(AbilitySystemComponent)
	{
		AbilitySystemComponent->OnAbilityInputPressed(Tag);
	}
}

void AFantasyPlayerCharacter::AbilityFivePressed(FGameplayTag Tag, float Value, bool Axis)
{
	UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(GetAbilitySystemComponent());
	if(AbilitySystemComponent)
	{
		AbilitySystemComponent->OnAbilityInputPressed(Tag);
	}
}

void AFantasyPlayerCharacter::AbilitySixPressed(FGameplayTag Tag, float Value, bool Axis)
{
	UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(GetAbilitySystemComponent());
	if(AbilitySystemComponent)
	{
		AbilitySystemComponent->OnAbilityInputPressed(Tag);
	}
}

void AFantasyPlayerCharacter::AbilitySevenPressed(FGameplayTag Tag, float Value, bool Axis)
{
	UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(GetAbilitySystemComponent());
	if(AbilitySystemComponent)
	{
		AbilitySystemComponent->OnAbilityInputPressed(Tag);
	}
}

void AFantasyPlayerCharacter::AbilityEightPressed(FGameplayTag Tag, float Value, bool Axis)
{
	UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(GetAbilitySystemComponent());
	if(AbilitySystemComponent)
	{
		AbilitySystemComponent->OnAbilityInputPressed(Tag);
	}
}

void AFantasyPlayerCharacter::AbilityNinePressed(FGameplayTag Tag, float Value, bool Axis)
{
	UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(GetAbilitySystemComponent());
	if(AbilitySystemComponent)
	{
		AbilitySystemComponent->OnAbilityInputPressed(Tag);
	}
}

void AFantasyPlayerCharacter::AbilityZeroPressed(FGameplayTag Tag, float Value, bool Axis)
{
	UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(GetAbilitySystemComponent());
	if(AbilitySystemComponent)
	{
		AbilitySystemComponent->OnAbilityInputPressed(Tag);
	}
}

void AFantasyPlayerCharacter::AbilityOneReleased(FGameplayTag Tag, float Value, bool Axis)
{
	UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(GetAbilitySystemComponent());
	if(AbilitySystemComponent)
	{
		AbilitySystemComponent->OnAbilityInputReleased(Tag);
	}
}

void AFantasyPlayerCharacter::AbilityTwoReleased(FGameplayTag Tag, float Value, bool Axis)
{
	UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(GetAbilitySystemComponent());
	if(AbilitySystemComponent)
	{
		AbilitySystemComponent->OnAbilityInputReleased(Tag);
	}
}

void AFantasyPlayerCharacter::AbilityThreeReleased(FGameplayTag Tag, float Value, bool Axis)
{
	UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(GetAbilitySystemComponent());
	if(AbilitySystemComponent)
	{
		AbilitySystemComponent->OnAbilityInputReleased(Tag);
	}
}

void AFantasyPlayerCharacter::AbilityFourReleased(FGameplayTag Tag, float Value, bool Axis)
{
	UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(GetAbilitySystemComponent());
	if(AbilitySystemComponent)
	{
		AbilitySystemComponent->OnAbilityInputReleased(Tag);
	}
}

void AFantasyPlayerCharacter::AbilityFiveReleased(FGameplayTag Tag, float Value, bool Axis)
{
	UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(GetAbilitySystemComponent());
	if(AbilitySystemComponent)
	{
		AbilitySystemComponent->OnAbilityInputReleased(Tag);
	}
}

void AFantasyPlayerCharacter::AbilitySixReleased(FGameplayTag Tag, float Value, bool Axis)
{
	UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(GetAbilitySystemComponent());
	if(AbilitySystemComponent)
	{
		AbilitySystemComponent->OnAbilityInputReleased(Tag);
	}
}

void AFantasyPlayerCharacter::AbilitySevenReleased(FGameplayTag Tag, float Value, bool Axis)
{
	UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(GetAbilitySystemComponent());
	if(AbilitySystemComponent)
	{
		AbilitySystemComponent->OnAbilityInputReleased(Tag);
	}
}

void AFantasyPlayerCharacter::AbilityEightReleased(FGameplayTag Tag, float Value, bool Axis)
{
	UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(GetAbilitySystemComponent());
	if(AbilitySystemComponent)
	{
		AbilitySystemComponent->OnAbilityInputReleased(Tag);
	}
}

void AFantasyPlayerCharacter::AbilityNineReleased(FGameplayTag Tag, float Value, bool Axis)
{
	UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(GetAbilitySystemComponent());
	if(AbilitySystemComponent)
	{
		AbilitySystemComponent->OnAbilityInputReleased(Tag);
	}
}

void AFantasyPlayerCharacter::AbilityZeroReleased(FGameplayTag Tag, float Value, bool Axis)
{
	UGameplayAbilitySystemComponent * AbilitySystemComponent = Cast<UGameplayAbilitySystemComponent>(GetAbilitySystemComponent());
	if(AbilitySystemComponent)
	{
		AbilitySystemComponent->OnAbilityInputReleased(Tag);
	}
}

void AFantasyPlayerCharacter::MoveForward(FGameplayTag Tag, float Value, bool Axis)
{
	// input is a Vector2D
	if (Controller != nullptr && ensure(Axis))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		// add movement 
		AddMovementInput(ForwardDirection, Value);
	}
}

void AFantasyPlayerCharacter::MoveSlide(FGameplayTag Tag, float Value, bool Axis)
{
	// input is a Vector2D
	if (Controller != nullptr && ensure(Axis))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(RightDirection, Value);
	}
}

void AFantasyPlayerCharacter::TurnPitch(FGameplayTag Tag, float Value, bool Axis)
{
	if (Controller != nullptr && ensure(Axis))
	{
		// add pitch input to controller
		AddControllerPitchInput(Value);
	}
}

void AFantasyPlayerCharacter::TurnYaw(FGameplayTag Tag, float Value, bool Axis)
{
	if (Controller != nullptr && ensure(Axis))
	{
		// add yaw input to controller
		AddControllerYawInput(Value);
	}
}

void AFantasyPlayerCharacter::DoJump(FGameplayTag Tag, float Value, bool Axis)
{
	Jump();
}

void AFantasyPlayerCharacter::Interact(FGameplayTag Tag, float Value, bool Axis)
{
	if(AvailableInteraction)
	{
		AvailableInteraction->OnInteraction(TObjectPtr<AFantasyPlayerCharacter>(this));
	}
}