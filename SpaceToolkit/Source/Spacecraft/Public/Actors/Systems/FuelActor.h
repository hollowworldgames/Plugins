// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "NativeGameplayTags.h"
#include "SystemActor.h"
#include "FuelActor.generated.h"

class UFuelAttributeSet;

SPACECRAFT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(FuelMaxFuelBonusTag);

UCLASS(BlueprintType)
class UFuelDefinitionData : public USystemDefinitionData
{
	GENERATED_BODY()
public :
	UPROPERTY()
	float MaxFuelBonus;
};

UCLASS(Blueprintable, BlueprintType)
class SPACECRAFT_API AFuelActor : public ASystemActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFuelActor();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void InitializeAttributes(ASpaceCraftActor* SystemOwner, USystemDefinitionData* SystemData) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Attributes")
	TObjectPtr<UFuelAttributeSet> FuelAttributes;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Effects")
	TSubclassOf<UGameplayEffect> InitializeEffect;
};
