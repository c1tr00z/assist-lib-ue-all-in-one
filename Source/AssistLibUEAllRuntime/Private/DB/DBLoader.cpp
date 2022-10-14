#include "DB/DBLoader.h"

#include "Engine/StreamableManager.h"

UDBCollection* DBLoader::LoadDB() {
	FStreamableManager AssetLoader;
	FSoftObjectPath AssetRef("/Game/DB/DB");
	auto Asset = AssetRef.TryLoad();

	if (Asset == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("[Assist Lib DB] DB Asset not found"));
		return nullptr;
	}

	auto DBCandidate = Cast<UDBCollection>(Asset);

	if (DBCandidate == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("[Assist Lib DB] Asset on path /Game/DB/DB is not DBCollection"));
		return nullptr;
	}

	return DBCandidate;
}
