// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FantasyPlayerController.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FQuestNotify, UQuestData *, Quest);

UCLASS()
class FANTASYCHARACTER_API AFantasyPlayerController : public APlayerController
{
	GENERATED_BODY()
public :
	UFUNCTION(Client, Reliable)
	void OfferQuest_Client(UQuestData * Quest);
	UFUNCTION(Client, Reliable)
    void QuestDone_Client(UQuestData * Quest);
protected :
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Events)
	FQuestNotify OnQuestOffered;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Events)
	FQuestNotify OnQuestDone;
};
