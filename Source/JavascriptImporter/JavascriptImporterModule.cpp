#include "JavascriptImporterModule.h"
#include "AssetToolsModule.h"

void FJavascriptImporterModule::StartupModule()
{
    JavascriptTypeActions_ = MakeShareable(new FAssetTypeActions_JavascriptDataAsset);

    IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
    AssetTools.RegisterAssetTypeActions(JavascriptTypeActions_.ToSharedRef());
}

void FJavascriptImporterModule::ShutdownModule()
{
    IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
    AssetTools.UnregisterAssetTypeActions(JavascriptTypeActions_.ToSharedRef());
}

IMPLEMENT_MODULE(FJavascriptImporterModule, JavascriptImporter);
