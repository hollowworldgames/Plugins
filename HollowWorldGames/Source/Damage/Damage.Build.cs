using UnrealBuildTool;

public class Damage : ModuleRules
{
    public Damage(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core", "AIModule","GameplayAbilities", "GameplayTasks", "GameplayTags"
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
                "Gameplay"
                
            }
        );
    }
}