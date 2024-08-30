// (c) Copyright 2024 Hollow World Games llc All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interfaces/QuestGiverInterface.h"
#include "QuestReceiverInterface.generated.h"

class UQuestData;
class UQuestReceiverComponent;
// This class does not need to be modified.
UINTERFACE(BlueprintType)
class UQuestReceiverInterface : public UInterface
{
	GENERATED_BODY()
};


class QUESTS_API IQuestReceiverInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual UQuestReceiverComponent * GetQuestComponent() = 0;
	virtual void OfferQuest(UQuestData * Quest) = 0;
	virtual void QuestDone(UQuestData * Quest) = 0;
	virtual void QuestInteractionAvailable(TScriptInterface<IQuestGiverInterface> NewGiver) = 0;
	virtual void QuestInteractionUnavailable(TScriptInterface<IQuestGiverInterface> RemoveGiver) = 0;
};
