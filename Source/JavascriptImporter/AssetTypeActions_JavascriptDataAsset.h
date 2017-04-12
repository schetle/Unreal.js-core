#pragma once

#include "CoreMinimal.h"
#include "AssetTypeActions_Base.h"
#include "JavascriptDataAsset.h"

class FAssetData;

class FAssetTypeActions_JavascriptDataAsset : public FAssetTypeActions_Base
{
public:
    virtual FText GetName() const override { return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_JavascriptDataAsset", "Javascript"); }
    virtual FColor GetTypeColor() const override { return FColor(125, 157, 186); }
    virtual UClass* GetSupportedClass() const override { return UJavascriptDataAsset::StaticClass(); }
    virtual uint32 GetCategories() override { return EAssetTypeCategories::Misc; }
    virtual bool CanLocalize() const override { return false; }

    virtual void OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor = TSharedPtr<IToolkitHost>()) override;
};
