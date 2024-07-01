// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "Settings/BoolSettingAsset.h"

#include "XmlFile.h"
#include "XmlNode.h"


void UBoolSettingAsset::SetValue(bool NewValue)
{
	Value = NewValue;
}

void UBoolSettingAsset::Write(FXmlFile& File)
{
	Super::Write(File);
	File.GetRootNode()->AppendChildNode(FString(SettingName.ToString()), (Value) ? TEXT("true") : TEXT("false"));
}

void UBoolSettingAsset::Read(FXmlFile& File)
{
	Super::Read(File);
	FXmlNode* Node = File.GetRootNode()->FindChildNode(SettingName.ToString());
	if(ensure(Node))
	{
		Value = Node->GetContent() == TEXT("true");
	}
}