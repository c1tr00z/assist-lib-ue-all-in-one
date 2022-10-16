// Fill out your copyright notice in the Description page of Project Settings.


#include "Modules/AssistLibModules.h"


// Sets default values
AAssistLibModules::AAssistLibModules() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAssistLibModules::BeginPlay() {
	Super::BeginPlay();
	
}

void AAssistLibModules::InitModules(UAssistLibModulesCollection* ModulesCollection) {
	for (UClass* ModuleClass : ModulesCollection->ModulesClasses) {
        UE_LOG(LogTemp, Warning, TEXT("Instantiate %s..."), *ModuleClass->GetName())
		auto Module = Cast<AAssistLibModule>(GetWorld()->SpawnActor(ModuleClass));
		Modules.Add(Module);
		UE_LOG(LogTemp, Warning, TEXT("Instantiate of %s finished. Result: %s"), *ModuleClass->GetName(), *Module->GetName());
	}
}

AAssistLibModule* AAssistLibModules::GetModuleByUClass(UClass* Class) {
	for (auto Module : Modules)
	{
		if (Module->GetClass() == Class)
		{
			return Module;
		}
	}

	return nullptr;
}
