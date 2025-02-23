using UnrealBuildTool;

public class FantasyCharacter : ModuleRules
{
    public FantasyCharacter(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "Common",
                "Gameplay",
                "DataAccess",
                "Equipment",
                "Inventory",
                "ViewPoints",
                "InputMapping",
                "Quests",
                "FantasyCrafting",
                "AIModule",
                "Interactions"
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
                "GameplayTags",
                "EnhancedInput"
            }
        );
    }
}