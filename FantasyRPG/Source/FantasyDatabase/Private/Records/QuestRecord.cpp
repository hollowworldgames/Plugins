// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "Records/QuestRecord.h"

FQuestStageRecord::FQuestStageRecord(const FSQLitePreparedStatement& Statement)
{
	Statement.GetColumnValueByIndex(1, StageId);
	int Value = 0;
	Statement.GetColumnValueByIndex(2, Value);
	Complete = Value == 1;
	Statement.GetColumnValueByIndex(3, Count);
}

FQuestStageRecord::FQuestStageRecord(int Stage, int Qty, bool bComplete)
{
	StageId = Stage;
	Count = Qty;
	Complete = bComplete;
}

void FQuestStageRecord::WriteToStatement(FSQLitePreparedStatement& Statement) const
{
	Statement.SetBindingValueByIndex(1, StageId);
	Statement.SetBindingValueByIndex(2, Complete);
	Statement.SetBindingValueByIndex(3, Count);
}

void FQuestRecord::WriteToStatement(FSQLitePreparedStatement& UpdateQuestStatement)
{
	for(FQuestStageRecord& Record : Stages)
	{
		UpdateQuestStatement.SetBindingValueByIndex(0, 0);
		if(!UpdateQuestStatement.Execute())
		{
			Record.WriteToStatement(UpdateQuestStatement);
		}
		UpdateQuestStatement.Reset();
	}
}
