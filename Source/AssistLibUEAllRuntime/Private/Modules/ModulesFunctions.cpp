// Fill out your copyright notice in the Description page of Project Settings.


#include "Modules/ModulesFunctions.h"
#include "Modules/GameModeModules.h"

AAssistLibModule* UModulesFunctions::GetModuleByUClass(UClass* Class) {
	return GetModuleByWorldAndUClass(GetWorld(), Class);
}

AAssistLibModule* UModulesFunctions::GetModuleByWorldAndUClass(UWorld* World, UClass* Class) {
	if (World == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("No UWorld object was providen. Impossible to get module"));
		return nullptr;
	}
	
	auto GameMode = Cast<AGameModeModules>(World->GetAuthGameMode());
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
