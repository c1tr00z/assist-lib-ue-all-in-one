// Copyright Epic Games, Inc. All Rights Reserved.

#include "AssistLibUEAllEditorCommands.h"

#define LOCTEXT_NAMESPACE "FAssistLibUEAllModule"

void FAssistLibUEAllEditorCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "AssistLibUEAll", "Execute AssistLibUEAll action", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
