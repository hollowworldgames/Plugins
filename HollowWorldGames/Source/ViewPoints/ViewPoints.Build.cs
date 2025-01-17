using UnrealBuildTool;

public class ViewPoints : ModuleRules
{
    public ViewPoints(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore", "Common", "EnhancedInput", "XRBase","GameplayTags"
            }
        );
    }
}