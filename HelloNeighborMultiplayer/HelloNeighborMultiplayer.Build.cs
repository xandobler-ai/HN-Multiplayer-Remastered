using UnrealBuildTool;

public class HelloNeighborMultiplayer : ModuleRules
{
    public HelloNeighborMultiplayer(
        ReadOnlyTargetRules Target
    ) : base(Target)
    {
        PCHUsage =
            PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core"
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine"
            }
        );
    }
}
