// Copyright Epic Games, Inc. All Rights Reserved.

#include "AssistLibUEAllEditor.h"
#include "AssistLibUEAllEditorStyle.h"
#include "AssistLibUEAllEditorCommands.h"
#include "Misc/MessageDialog.h"
#include "ToolMenus.h"
#include "DB/DBLoader.h"
#include "UObject/SavePackage.h"

static const FName AssistLibUEAllTabName("AssistLibUEAll");

#define LOCTEXT_NAMESPACE "FAssistLibUEAllModule"

void FAssistLibUEAllEditorModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FAssistLibUEAllEditorStyle::Initialize();
	FAssistLibUEAllEditorStyle::ReloadTextures();

	FAssistLibUEAllEditorCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FAssistLibUEAllEditorCommands::Get().PluginAction,
		FExecuteAction::CreateRaw(this, &FAssistLibUEAllEditorModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FAssistLibUEAllEditorModule::RegisterMenus));
}

void FAssistLibUEAllEditorModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FAssistLibUEAllEditorStyle::Shutdown();

	FAssistLibUEAllEditorCommands::Unregister();
}

void FAssistLibUEAllEditorModule::PluginButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("[Assist Lib DB] Start collection DB Entries"));
	
	auto DB = DBLoader::LoadDB();

	if (!IsValid(DB))
	{
		UE_LOG(LogTemp, Error, TEXT("[Assist Lib DB] NO DB COLLECTION FOUND"));
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("[Assist Lib DB] DB found: %s"), *DB->GetName());

	if (ObjectLibrary == NULL)
	{
		ObjectLibrary = UObjectLibrary::CreateLibrary(UDBEntry::StaticClass(), false, GIsEditor);
		ObjectLibrary->AddToRoot();
	}
	ObjectLibrary->LoadAssetDataFromPath(TEXT("/Game/DB"));
	ObjectLibrary->LoadAssetsFromAssetData();
	TArray<FAssetData> AssetDatas;
	ObjectLibrary->GetAssetDataList(AssetDatas);

	TArray<UDBEntry*> Entries;
	for (FAssetData AssetData : AssetDatas)
	{
		auto Entry = Cast<UDBEntry>(AssetData.GetAsset());

		if (!IsValid(Entry))
		{
			continue;
		}

		UE_LOG(LogTemp, Warning, TEXT("[Assist Lib DB] Collecting %s"), *Entry->GetName());
		Entries.Add(Entry);
	}

	UPackage* Package = CreatePackage(TEXT("/Game/DB/DB"));
	Package->FullyLoad();
	
	DB->Entries = Entries;
	DB->SaveConfig();
	Package->MarkPackageDirty();

	FString PackageFileName = FPackageName::LongPackageNameToFilename(TEXT("/Game/DB/DB"), FPackageName::GetAssetPackageExtension());
	FSavePackageArgs SaveArgs = { };
	auto IsSaved = UPackage::SavePackage(Package, DB, *PackageFileName, SaveArgs);
	// bool bSaved = UPackage::SavePackage(Package, DB, EObjectFlags::RF_Public | EObjectFlags::RF_Standalone, *PackageFileName, GError, nullptr, true, true, SAVE_NoError);

	UE_LOG(LogTemp, Warning, TEXT("[Assist Lib DB] DB Data Asset saved %b"), IsSaved)
	
	// // Put your "OnButtonClicked" stuff here
	// FText DialogText = FText::Format(
	// 						LOCTEXT("PluginButtonDialogText", "Add code to {0} in {1} to override this button's actions"),
	// 						FText::FromString(TEXT("FAssistLibUEAllModule::PluginButtonClicked()")),
	// 						FText::FromString(TEXT("AssistLibUEAll.cpp"))
	// 				   );
	// FMessageDialog::Open(EAppMsgType::Ok, DialogText);
}

void FAssistLibUEAllEditorModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FAssistLibUEAllEditorCommands::Get().PluginAction, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.PlayToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("PluginTools");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FAssistLibUEAllEditorCommands::Get().PluginAction));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FAssistLibUEAllEditorModule, AssistLibUEAllEditor)