// Fill out your copyright notice in the Description page of Project Settings.


#include "DB/DBFunctions.h"

#include "Core/AssistLibGameInstance.h"
#include "DB/DBLoader.h"

UDBCollection* UDBFunctions::GetDB(UWorld* World)
{
	auto GameInstance = Cast<UAssistLibGameInstance>(World->GetGameInstance());

	if (!IsValid(GameInstance))
	{
		UE_LOG(LogTemp, Error, TEXT("[Assist Lib DB] No Assist Lib Game Instance set up in project"));
		return nullptr;
	}

	auto DBCandidate = GameInstance->GetDataItem(KEY_DB);

	if (!IsValid(DBCandidate))
	{
		DBCandidate = DBLoader::LoadDB();
		GameInstance->SetDataItem(KEY_DB, DBCandidate);
	}

	auto DB = Cast<UDBCollection>(DBCandidate);
	return DB;
}

UDBCollection* UDBFunctions::GetDB() const
{
	return GetDB(GetWorld());
}

TArray<UDBEntry*> UDBFunctions::GetAllDBEntriesByClass(TSubclassOf<UDBEntry> Class) const
{
	TArray<UDBEntry*> Result;

	auto DB = GetDB();
	auto Entries = DB->Entries;

	for (UDBEntry* Entry : Entries)
	{
		if (Entry->GetClass() == Class)
		{
			Result.Add(Entry);
		}
	}

	return Result;
}

UDBEntry* UDBFunctions::GetDBEntryByClassAndName(TSubclassOf<UDBEntry> Class, FString Name) const
{
	auto DB = GetDB();
	auto Entries = DB->Entries;

	for (UDBEntry* Entry : Entries)
	{
		if (Entry->GetClass() == Class && Entry->GetName() == Name)
		{
			return Entry;
		}
	}

	return nullptr;
}