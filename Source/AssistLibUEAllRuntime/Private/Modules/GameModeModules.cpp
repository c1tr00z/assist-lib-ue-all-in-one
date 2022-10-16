// Fill out your copyright notice in the Description page of Project Settings.


#include "Modules/GameModeModules.h"

#include "Modules/AssistLibModules.h"


// Called when the game starts or when spawned
void AGameModeModules::BeginPlay() {
	Super::BeginPlay();

	Modules = Cast<AAssistLibModules>(GetWorld()->SpawnActor(AAssistLibModules::StaticClass()));

	Modules->Rename(TEXT("Modules"));

	Modules->InitModules(ModulesCollection);
}


