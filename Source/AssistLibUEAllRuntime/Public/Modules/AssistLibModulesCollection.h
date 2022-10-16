// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssistLibModule.h"
#include "UObject/Object.h"
#include "AssistLibModulesCollection.generated.h"

/**
 * 
 */
UCLASS()
class ASSISTLIBUEALLRUNTIME_API UAssistLibModulesCollection : public UDataAsset {
	GENERATED_BODY()

public:
	TArray<TSubclassOf<AAssistLibModule>> ModulesClasses;
};
