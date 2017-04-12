#include "AssetTypeActions_JavascriptDataAsset.h"

void FAssetTypeActions_JavascriptDataAsset::OpenAssetEditor( const TArray<UObject*>& InObjects, TSharedPtr<IToolkitHost> EditWithinLevelEditor ) {
    UJavascriptDataAsset* jsAsset = Cast<UJavascriptDataAsset>(InObjects[0]);
    FPlatformProcess::LaunchFileInDefaultExternalApplication(*jsAsset->GetJavascriptDataFileName().ToString(), NULL, ELaunchVerb::Edit);
}
