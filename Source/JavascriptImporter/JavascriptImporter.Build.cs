using UnrealBuildTool;

public class JavascriptImporter : ModuleRules
{
    public JavascriptImporter(TargetInfo Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "UnrealEd",
            "AssetTools",
            "ScriptPlugin",
            "ClassViewer",
            "KismetCompiler",
            "Kismet",
            "BlueprintGraph"
        });

        Definitions.Add(string.Format("WITH_JSIMPORTER=1"));
    }
}