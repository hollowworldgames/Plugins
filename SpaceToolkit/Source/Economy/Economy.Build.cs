using UnrealBuildTool;

public class Economy : ModuleRules
{
    public Economy(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core", "GameplayTags", "Gameplay",
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
                "Galaxy",
                "GameplayAbilities",
                "GameplayTags",
                "Gameplay"
            }
        );
    }
}