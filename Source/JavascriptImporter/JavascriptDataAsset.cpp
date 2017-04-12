#include "JavascriptDataAsset.h"

FName UJavascriptDataAsset::GetJavascriptDataFileName() const {
#if WITH_EDITORONLY_DATA
    TArray<FString> files;
    if (importData) importData->ExtractFilenames(files);
    if (files.Num() > 0) return FName(*files[0]);
    else return javascriptDataFileName;
#else
    return javascriptDataFileName;
#endif
}

#if WITH_EDITORONLY_DATA

void UJavascriptDataAsset::SetJavascriptDataFileName(const FName &JavascriptDataFileName) {
    importData->UpdateFilenameOnly(JavascriptDataFileName.ToString());
    TArray<FString> files;
    importData->ExtractFilenames(files);
    if (files.Num() > 0) this->javascriptDataFileName = FName(*files[0]);
}

void UJavascriptDataAsset::PostInitProperties() {
    if (!HasAnyFlags(RF_ClassDefaultObject)) importData = NewObject<UAssetImportData>(this, TEXT("AssetImportData"));
    Super::PostInitProperties();
}

void UJavascriptDataAsset::GetAssetRegistryTags(TArray<FAssetRegistryTag>& OutTags) const {
    if (importData) {
        OutTags.Add(FAssetRegistryTag(SourceFileTagName(), "", FAssetRegistryTag::TT_Hidden));
    }

    Super::GetAssetRegistryTags(OutTags);
}

void UJavascriptDataAsset::BeginDestroy() {
    Super::BeginDestroy();
}
#endif
