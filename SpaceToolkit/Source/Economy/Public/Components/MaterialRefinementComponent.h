// Copyright(c) 2024 Hollow World Games llc All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "MaterialRefinementComponent.generated.h"


class IMaterialSourceInterface;
class IEconomyCharacterInterface;
class IResourceSourceInterface;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMaterialRefinedDelegate, UMaterialRefinementComponent*, Component);

USTRUCT(BlueprintType)
struct FRefineJob
{
	GENERATED_BODY()
	UPROPERTY()
	FGameplayTag Material;
	UPROPERTY()
	TScriptInterface<IResourceSourceInterface> ResourceSource;
	UPROPERTY()
	TScriptInterface<IMaterialSourceInterface> Destination;
	UPROPERTY()
	TScriptInterface<IEconomyCharacterInterface> Character;
	UPROPERTY()
	float Qty;
};

UCLASS(ClassGroup=(Economy), Abstract)
class ECONOMY_API UMaterialRefinementComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UMaterialRefinementComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	void StartRefinement(FGameplayTag Material, TScriptInterface<IResourceSourceInterface> ResourceSource,
		TScriptInterface<IMaterialSourceInterface> Destination, TScriptInterface<IEconomyCharacterInterface> Character, float Qty);
	virtual bool CanRefine(FGameplayTag Material, TScriptInterface<IResourceSourceInterface> ResourceSource,
		TScriptInterface<IMaterialSourceInterface> Destination, TScriptInterface<IEconomyCharacterInterface> Character, float Qty);
protected:
	virtual void CommitResources(FRefineJob& Job);
	virtual bool DoJob(FRefineJob& Job, float DeltaTime);
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category = "Material")
	FMaterialRefinedDelegate OnMaterialRefined;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category = "Jobs")
	TArray<FRefineJob> Jobs;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Jobs")
	int MaxJobs = 1;
};
