// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "Data/QuestListData.h"

#include "Data/QuestData.h"

TObjectPtr<UQuestData> UQuestListData::GetQuest(int QuestId)
{
	for(TObjectPtr<UQuestData> Quest : Quests)
	{
		if(Quest->QuestId == QuestId)
		{
			return Quest;
		}
	}
	return nullptr;
}
