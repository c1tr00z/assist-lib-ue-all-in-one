// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssistLibModule.h"
#include "GameModeModules.h"
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
	static AGameModeModules* GetModulesGameMode(UWorld* World);
	
	UFUNCTION(BlueprintCallable)
	AAssistLibModule* GetModuleByUClass(UClass* Class);

	UFUNCTION(BlueprintCallable)
	static AAssistLibModule* GetModuleByWorldAndUClass(UWorld* World, UClass* Class);

	template <typename T>
	static T* GetModule(UWorld* World);
};

template <typename T>
T* UModulesFunctions::GetModule(UWorld* World) {
	const auto GameMode = GetModulesGameMode(World);
	if (GameMode == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("No Game Mode of type MGGameModeBase. Impossible to get module"));
		return nullptr;
	}

	if (GameMode->Modules == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("No Modules object in Game Mode. Impossible to get module"));
		return nullptr;
	}

	return GameMode->Modules->GetModule<T>();
}
