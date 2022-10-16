// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssistLibModule.h"
#include "UObject/Object.h"
#include "ModulesFunctions.generated.h"

/**
 * 
 */
UCLASS()
class ASSISTLIBUEALLRUNTIME_API UModulesFunctions : public UBlueprintFunctionLibrary {
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	AAssistLibModule* GetModuleByUClass(UClass* Class);

	UFUNCTION(BlueprintCallable)
	static AAssistLibModule* GetModuleByWorldAndUClass(UWorld* World, UClass* Class);
};
