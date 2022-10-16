// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssistLibModules.h"
#include "AssistLibModulesCollection.h"
#include "GameFramework/GameModeBase.h"
#include "GameModeModules.generated.h"

UCLASS()
class ASSISTLIBUEALLRUNTIME_API AGameModeModules : public AGameModeBase {
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UAssistLibModulesCollection* ModulesCollection;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	AAssistLibModules* Modules;
};
