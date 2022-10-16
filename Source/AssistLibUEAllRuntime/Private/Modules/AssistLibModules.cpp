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
	for (UClass* ModulesClass : ModulesCollection->ModulesClasses) {
		auto ModuleActor = GetWorld()->SpawnActor(ModulesClass);
		auto Module = Cast<AAssistLibModule>(ModuleActor);
		Modules.Add(Module);
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
