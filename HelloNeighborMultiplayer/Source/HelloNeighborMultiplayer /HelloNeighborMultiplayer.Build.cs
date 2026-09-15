using UnrealBuildTool;

public class HelloNeighborMultiplayer : ModuleRules
{
    public HelloNeighborMultiplayer(ReadOnlyTargetRules Target)
        : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

       PublicDependencyModuleNames.AddRange(
    new string[]
    {
        "Core",
        "CoreUObject",
        "Engine",
        "NetCore"
    }
