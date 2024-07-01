// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "Settings/IntSettingAsset.h"

#include "XmlFile.h"


void UIntSettingAsset::SetValue(int NewValue)
{
	if(ensure(NewValue >= MinValue && NewValue <= MaxValue))
	{
		Value = NewValue;
	}
}

void UIntSettingAsset::Write(FXmlFile& File)
{
	Super::Write(File);
	File.GetRootNode()->AppendChildNode(FString(SettingName.ToString()), FString::Printf(TEXT("%d"), Value));
}

void UIntSettingAsset::Read(FXmlFile& File)
{
	Super::Read(File);
	FXmlNode* Node = File.GetRootNode()->FindChildNode(SettingName.ToString());
	if(ensure(Node))
	{
		Value = FCString::Atoi(*Node->GetContent());
	}
}