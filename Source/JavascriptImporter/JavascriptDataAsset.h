#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EditorFramework/AssetImportData.h"
#include "JavascriptDataAsset.generated.h"

UCLASS(MinimalAPI)
class UJavascriptDataAsset : public UObject {
    GENERATED_BODY()

public:
    FName GetJavascriptDataFileName() const;

    virtual void BeginDestroy() override;

protected:
    UPROPERTY()
    FName javascriptDataFileName;

#if WITH_EDITORONLY_DATA
public:
    void SetJavascriptDataFileName(const FName &javascriptDataFileName);

protected:
    UPROPERTY(VisibleAnywhere, Instanced, Category = ImportSettings)
    class UAssetImportData* importData;

    virtual void PostInitProperties() override;
    virtual void GetAssetRegistryTags(TArray<FAssetRegistryTag>& OutTags) const override;
#endif
};
