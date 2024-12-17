// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "NativeGameplayTags.h"
#include "SystemActor.h"
#include "ShieldActor.generated.h"

SPACECRAFT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ShieldHitPointBonusTag);
SPACECRAFT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ShieldPowerHitPointBonusTag);

class UShieldAttributeSet;

UCLASS(BlueprintType)
class UShieldDefinitionData : public USystemDefinitionData
{
	GENERATED_BODY()
public :
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Shield)
	float HitPoints;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Shield)
	float PowerToHitPoints;
};

UCLASS()
class SPACECRAFT_API AShieldActor : public ASystemActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AShieldActor();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void InitializeAttributes(ASpaceCraftActor* SystemOwner, USystemDefinitionData* SystemData) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Attributes")
	TObjectPtr<UShieldAttributeSet> ShieldAttributes;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Effects")
	TSubclassOf<UGameplayEffect> InitializeEffect;
};
