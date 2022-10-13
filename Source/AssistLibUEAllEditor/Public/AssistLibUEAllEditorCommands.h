// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "AssistLibUEAllEditorStyle.h"

class FAssistLibUEAllEditorCommands : public TCommands<FAssistLibUEAllEditorCommands>
{
public:

	FAssistLibUEAllEditorCommands()
		: TCommands<FAssistLibUEAllEditorCommands>(TEXT("AssistLibUEAll"), NSLOCTEXT("Contexts", "AssistLibUEAll", "AssistLibUEAll Plugin"), NAME_None, FAssistLibUEAllEditorStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > PluginAction;
};
