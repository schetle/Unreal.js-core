#include "JavascriptImportFactory.h"
#include "JavascriptDataAsset.h"

UJavascriptImportFactory::UJavascriptImportFactory(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {

    bCreateNew = false;
    bEditAfterNew = true;
    SupportedClass = UJavascriptDataAsset::StaticClass();

    bEditorImport = true;
    bText = true;

    Formats.Add(TEXT("js;Javascript"));
}

FText UJavascriptImportFactory::GetDisplayName() const {
    return FText::FromString(TEXT("Javascript"));
}

bool UJavascriptImportFactory::DoesSupportClass(UClass * Class) {
    return Class == UJavascriptDataAsset::StaticClass();
}

bool UJavascriptImportFactory::FactoryCanImport(const FString& Filename) {
    return true;
}

UObject* UJavascriptImportFactory::FactoryCreateText(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, const TCHAR* Type, const TCHAR*& Buffer, const TCHAR* BufferEnd, FFeedbackContext* Warn) {
    FString name(InName.ToString());

    UJavascriptDataAsset* asset = NewObject<UJavascriptDataAsset>(InParent, InClass, FName(*name), Flags);
    asset->SetJavascriptDataFileName(FName(*GetCurrentFilename()));
    return asset;
}
