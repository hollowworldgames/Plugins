﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DataCharacter.generated.h"

class UDataAccessComponent;

UCLASS()
class DATAACCESS_API ADataCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADataCharacter();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void Load(uint64 ActorId);
	void Save() const;
	UFUNCTION()
	virtual void OnLoaded();
	virtual void OnPrepareSave() const;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Data)
	TSubclassOf<UDataAccessComponent> SingleDataClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Data)
	TSubclassOf<UDataAccessComponent> ServerDataClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Data)
	TSubclassOf<UDataAccessComponent> ClientDataClass;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category=Data)
	TObjectPtr<UDataAccessComponent> DataAccessComponent;
private:
	UFUNCTION(NetMulticast, Reliable)
    virtual void Multicast_PostLoad();
};


