// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "Player/FantasyPlayerController.h"

void AFantasyPlayerController::OfferQuest_Client_Implementation(UQuestData* Quest)
{
	OnQuestOffered.Broadcast(Quest);
}

void AFantasyPlayerController::QuestDone_Client_Implementation(UQuestData* Quest)
{
	OnQuestDone.Broadcast(Quest);
}
