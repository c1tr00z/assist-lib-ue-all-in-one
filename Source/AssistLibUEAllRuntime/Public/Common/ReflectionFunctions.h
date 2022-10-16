// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ReflectionFunctions.generated.h"

/**
 * 
 */
UCLASS()
class ASSISTLIBUEALLRUNTIME_API UReflectionFunctions : public UBlueprintFunctionLibrary {
	GENERATED_BODY()

public:
	
	UFUNCTION()
	static UStruct* GetUStructByName(FString StructName);

	template <typename T>
	static T InstantiateStructByUStruct(UStruct* UStruct);

	static TArray<UClass*> GetSubclassesOf(const UClass* ParentClass, bool IncludeAbstract = true);
};

template <typename T>
T UReflectionFunctions::InstantiateStructByUStruct(UStruct* UStruct) {
	auto OnScope = FStructOnScope(UStruct);
	auto TOnScope = TStructOnScope<T>();
	TOnScope.InitializeFrom(OnScope);
	return *TOnScope.Get();
}
