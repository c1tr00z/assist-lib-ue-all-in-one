// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/AssistLibGameInstance.h"

UObject* UAssistLibGameInstance::GetDataItem(FName Key)
{
	if (Data.Contains(Key))
	{
		return Data[Key];
	}

	UE_LOG(LogTemp, Error, TEXT("[Assist Lib Core] No data by key %s"), *Key.ToString());
	return nullptr;
}

void UAssistLibGameInstance::SetDataItem(FName Key, UObject* DataItem)
{
	if (Data.Contains(Key))
	{
		UE_LOG(LogTemp, Warning, TEXT("[Assist Lib Core] Somwthing already in data by key %s"), *Key.ToString());
		Data[Key] = DataItem;
		return;
	}

	Data.Add(Key, DataItem);
}