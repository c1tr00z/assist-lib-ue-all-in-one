// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DBCollection.h"
#include "DBFunctions.generated.h"

/**
 * 
 */
UCLASS()
class ASSISTLIBUEALLRUNTIME_API UDBFunctions : public UBlueprintFunctionLibrary {
	GENERATED_BODY()

public:
	static UDBCollection* GetDB(UWorld* World);

	inline static FName KEY_DB = FName(TEXT("AssistLibDBKey"));
	
	UFUNCTION(BlueprintPure)
	UDBCollection* GetDB() const;

	template<typename T>
	static TArray<T> GetAll(UWorld* World);

	UFUNCTION(BlueprintPure)
	TArray<UDBEntry*> GetAllDBEntriesByClass(TSubclassOf<UDBEntry> Class) const;

	UFUNCTION(BlueprintPure)
	UDBEntry* GetDBEntryByClassAndName(TSubclassOf<UDBEntry> Class, FString Name) const;
};

template <typename T>
TArray<T> UDBFunctions::GetAll(UWorld* World) {
	auto DBStatic = GetDB(World);
	auto Entries = DBStatic->Entries;

	TArray<T> Result;
	for (UDBEntry* Entry : Entries)
	{
		T Item = Cast<T>(Entry);
		if (Item != nullptr)
		{
			Result.Add(Item);
		}
	}
	return Result;
}
