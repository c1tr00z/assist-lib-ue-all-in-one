// Fill out your copyright notice in the Description page of Project Settings.


#include "Modules/ModulesFunctions.h"
#include "Modules/GameModeModules.h"

AGameModeModules* UModulesFunctions::GetModulesGameMode(UWorld* World) {
	if (World == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("No UWorld object was providen. Impossible to get module"));
		return nullptr;
	}
	
	return Cast<AGameModeModules>(World->GetAuthGameMode());
}

AAssistLibModule* UModulesFunctions::GetModuleByUClass(UClass* Class) {
	return GetModuleByWorldAndUClass(GetWorld(), Class);
}

AAssistLibModule* UModulesFunctions::GetModuleByWorldAndUClass(UWorld* World, UClass* Class) {
	
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
	
	return GameMode->Modules->GetModuleByUClass(Class);
}
