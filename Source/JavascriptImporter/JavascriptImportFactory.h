#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "Factories/Factory.h"
#include "JavascriptImportFactory.generated.h"

/**
 * Factory for importing javascript files
 */

UCLASS(hidecategories = Object)
class UJavascriptImportFactory : public UFactory
{
    GENERATED_UCLASS_BODY()

    virtual FText GetDisplayName() const override;
    virtual UObject* FactoryCreateText(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, const TCHAR* Type, const TCHAR*& Buffer, const TCHAR* BufferEnd, FFeedbackContext* Warn) override;
    virtual bool DoesSupportClass(UClass * Class) override;
    virtual bool FactoryCanImport(const FString& Filename) override;
};
