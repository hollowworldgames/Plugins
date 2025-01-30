// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "QuestGiverInterface.generated.h"

class IQuestReceiverInterface;
class UQuestData;
// This class does not need to be modified.
UINTERFACE()
class UQuestGiverInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class QUESTS_API IQuestGiverInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual TArray<UQuestData*> GetAvailableQuests(TScriptInterface<IQuestReceiverInterface> Receiver) = 0;
	virtual void TurnIn(TScriptInterface<IQuestReceiverInterface> Receiver,const UQuestData * Quest) = 0;
	virtual void Accept(TScriptInterface<IQuestReceiverInterface> Receiver,const UQuestData * Quest) = 0;
};
