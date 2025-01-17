// Copyright (c) 2024 Hollow World Games llc All Rights Reserved.


#include "CommonGameInstance.h"
#include "XmlFile.h"
#include "Kismet/BlueprintPathsLibrary.h"
#include "Settings/SettingAsset.h"

void UCommonGameInstance::Init()
{
	Super::Init();
	SettingsPath = UBlueprintPathsLibrary::ProjectSavedDir() + FGenericPlatformMisc::GetDefaultPathSeparator() +  TEXT("Settings.xml");
	LoadSettings();
}

void UCommonGameInstance::Shutdown()
{
	Super::Shutdown();
	
}

void UCommonGameInstance::LoadSettings()
{
	FXmlFile SettingsFile(SettingsPath);
	if (SettingsFile.IsValid())
	{
		for(TObjectPtr<USettingAsset> setting : Settings)
		{
			setting->Write(SettingsFile);
		}
	}
	else
	{
		for (TObjectPtr<USettingAsset> setting : Settings)
		{
			setting->Reset();
		}
		SaveSettings();
	}
}

void UCommonGameInstance::SaveSettings()
{
	const FString FileTemplate = "<?xml version=\"1.0\" encoding=\"UTF - 8\"?>\n<root>\n</root>";
	FXmlFile SettingsFile(FileTemplate, EConstructMethod::ConstructFromBuffer);
	for(TObjectPtr<USettingAsset> setting : Settings)
	{
		setting->Write(SettingsFile);
	}
	SettingsFile.Save(SettingsPath);
}


void UCommonGameInstance::ResetSettings()
{
	for(TObjectPtr<USettingAsset> setting : Settings)
	{
		setting->Reset();
	}
	SaveSettings();
}