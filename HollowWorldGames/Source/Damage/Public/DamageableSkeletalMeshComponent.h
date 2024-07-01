// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/SceneComponent.h"
#include "DamageableSkeletalMeshComponent.generated.h"


struct FGameplayTag;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DAMAGE_API UDamageableSkeletalMeshComponent : public USkeletalMeshComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDamageableSkeletalMeshComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	FGameplayTag GetTagFromBone(FName Bone) const;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Bones)
	TMap<FName, FGameplayTag> BoneTags;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	FGameplayTag DefaultComponent;
};
