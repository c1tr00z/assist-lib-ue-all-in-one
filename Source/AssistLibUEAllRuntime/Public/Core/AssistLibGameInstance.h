// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AssistLibGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class ASSISTLIBUEALLRUNTIME_API UAssistLibGameInstance : public UObject {
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Assist Lib Core")
	TMap<FName, UObject*> Data;

public:
	UFUNCTION(BlueprintPure, Category="Assist Lib Core")
	UObject* GetDataItem(FName Key);

	UFUNCTION(BlueprintCallable, Category="Assist Lib Core")
	void SetDataItem(FName Key, UObject* DataItem);

};
