// Copyright Epic Games, Inc. All Rights Reserved.

#include "AssistLibUEAllEditor.h"
#include "AssistLibUEAllEditorStyle.h"
#include "AssistLibUEAllEditorCommands.h"
#include "Misc/MessageDialog.h"
#include "ToolMenus.h"

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
	// Put your "OnButtonClicked" stuff here
	FText DialogText = FText::Format(
							LOCTEXT("PluginButtonDialogText", "Add code to {0} in {1} to override this button's actions"),
							FText::FromString(TEXT("FAssistLibUEAllModule::PluginButtonClicked()")),
							FText::FromString(TEXT("AssistLibUEAll.cpp"))
					   );
	FMessageDialog::Open(EAppMsgType::Ok, DialogText);
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