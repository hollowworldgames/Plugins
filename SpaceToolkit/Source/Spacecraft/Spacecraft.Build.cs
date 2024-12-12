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
                "GameplayTags", "ViewPoints", "Gameplay","SpaceGameplay"
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
                "Gameplay","Character",
                "GameplayTasks",
                "GameplayTags", 
                "EnhancedInput",
                "Interactions",
                "HeadMountedDisplay", 
                "Damage",
                "AIModule",
                "Galaxy"
            }
        );
    }
}