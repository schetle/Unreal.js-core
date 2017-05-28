#pragma once

#include "IJavascriptImporterModule.h"
#include "AssetTypeActions_JavascriptDataAsset.h"

class FJavascriptImporterModule : public IJavascriptImporterModule
{
    // Begin IModuleInterface
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
    // End IModuleInterface

private:
    TSharedPtr<FAssetTypeActions_JavascriptDataAsset> JavascriptTypeActions_;
};
