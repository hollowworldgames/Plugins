// (c) Copyright 2024 Hollow World Games llc All Rights Reserved


#include "Settings/SettingsGameInstance.h"

#include "XmlFile.h"
#include "Kismet/BlueprintPathsLibrary.h"
#include "Settings/SettingAsset.h"

void USettingsGameInstance::Init()
{
	Super::Init();
	SettingsPath = UBlueprintPathsLibrary::ProjectSavedDir() + FGenericPlatformMisc::GetDefaultPathSeparator() +  TEXT("Settings.xml");
	LoadSettings();
}

void USettingsGameInstance::Shutdown()
{
	Super::Shutdown();
	
}

void USettingsGameInstance::LoadSettings()
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

void USettingsGameInstance::SaveSettings()
{
	const FString FileTemplate = "<?xml version=\"1.0\" encoding=\"UTF - 8\"?>\n<root>\n</root>";
	FXmlFile SettingsFile(FileTemplate, EConstructMethod::ConstructFromBuffer);
	for(TObjectPtr<USettingAsset> setting : Settings)
	{
		setting->Write(SettingsFile);
	}
	SettingsFile.Save(SettingsPath);
}


void USettingsGameInstance::ResetSettings()
{
	for(TObjectPtr<USettingAsset> setting : Settings)
	{
		setting->Reset();
	}
	SaveSettings();
}