using UnrealBuildTool;

public class FantasyDatabase : ModuleRules
{
    public FantasyDatabase(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core", "DataAccess","Quests","GameplayTags",
                "GameplayAbilities", "Gameplay","Common","SQLiteCore","SQLiteSupport"
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore"
            }
        );
    }
}