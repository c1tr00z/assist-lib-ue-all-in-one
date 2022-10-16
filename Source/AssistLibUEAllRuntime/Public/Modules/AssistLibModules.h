// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssistLibModulesCollection.h"
#include "GameFramework/Actor.h"
#include "AssistLibModules.generated.h"

UCLASS()
class ASSISTLIBUEALLRUNTIME_API AAssistLibModules : public AActor {
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAssistLibModules();

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	TArray<AAssistLibModule*> Modules;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	void InitModules(UAssistLibModulesCollection* ModulesCollection);

	UFUNCTION(BlueprintCallable)
	AAssistLibModule* GetModuleByUClass(UClass* Class);

};
