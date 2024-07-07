using UnrealBuildTool;

public class Spacecraft : ModuleRules
{
    public Spacecraft(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core", "GameplayAbilities","GameplayTasks",
                "GameplayTags"
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
                "Common",
                "Gameplay",
                "GameplayTasks",
                "GameplayTags", "EnhancedInput"
            }
        );
    }
}