// Copyright Epic Games, Inc. All Rights Reserved.

#include "AssistLibUEAllEditorStyle.h"
#include "Framework/Application/SlateApplication.h"
#include "Styling/SlateStyleRegistry.h"
#include "Slate/SlateGameResources.h"
#include "Interfaces/IPluginManager.h"
#include "Styling/SlateStyleMacros.h"

#define RootToContentDir Style->RootToContentDir

TSharedPtr<FSlateStyleSet> FAssistLibUEAllEditorStyle::StyleInstance = nullptr;

void FAssistLibUEAllEditorStyle::Initialize()
{
	if (!StyleInstance.IsValid())
	{
		StyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FAssistLibUEAllEditorStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

FName FAssistLibUEAllEditorStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("AssistLibUEAllStyle"));
	return StyleSetName;
}


const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon20x20(20.0f, 20.0f);

TSharedRef< FSlateStyleSet > FAssistLibUEAllEditorStyle::Create()
{
	TSharedRef< FSlateStyleSet > Style = MakeShareable(new FSlateStyleSet("AssistLibUEAllStyle"));
	Style->SetContentRoot(IPluginManager::Get().FindPlugin("AssistLibUEAll")->GetBaseDir() / TEXT("Resources"));

	Style->Set("AssistLibUEAll.PluginAction", new IMAGE_BRUSH_SVG(TEXT("CollectDBIcon"), Icon20x20));
	return Style;
}

void FAssistLibUEAllEditorStyle::ReloadTextures()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

const ISlateStyle& FAssistLibUEAllEditorStyle::Get()
{
	return *StyleInstance;
}
