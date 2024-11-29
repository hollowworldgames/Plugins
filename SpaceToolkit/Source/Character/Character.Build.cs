using UnrealBuildTool;

public class Character : ModuleRules
{
    public Character(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "Common",
                "Gameplay",
                "Interactions",
                "DataAccess",
                "ViewPoints",
                "XRCommon", 
                "AIModule",
                "SpaceGameplay"
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
                "GameplayAbilities",
                "GameplayTasks",
                "GameplayTags",
                "AIModule", 
                "EnhancedInput",
                "HeadMountedDisplay"
            }
        );
    }
}