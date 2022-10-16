// Fill out your copyright notice in the Description page of Project Settings.


#include "Common/ReflectionFunctions.h"

UStruct* UReflectionFunctions::GetUStructByName(FString StructName) {
	UObject* ClassPackage = ANY_PACKAGE;
	return FindObject<UStruct>(ClassPackage, *StructName);
}

TArray<UClass*> UReflectionFunctions::GetSubclassesOf(const UClass* ParentClass, bool IncludeAbstract) {
	TArray<UClass*> ResultClasses;
	for(TObjectIterator<UClass> It; It; ++It)
	{
		if(It->IsChildOf(ParentClass) && (IncludeAbstract || !It->HasAnyClassFlags(CLASS_Abstract)))
		{
			ResultClasses.Add(*It);
		}
	}
	return ResultClasses;
}
