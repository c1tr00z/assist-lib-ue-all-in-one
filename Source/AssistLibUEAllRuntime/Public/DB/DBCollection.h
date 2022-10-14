// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DBEntry.h"
#include "UObject/Object.h"
#include "DBCollection.generated.h"

/**
 * 
 */
UCLASS()
class ASSISTLIBUEALLRUNTIME_API UDBCollection : public UDataAsset {
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<UDBEntry*> Entries;

};
