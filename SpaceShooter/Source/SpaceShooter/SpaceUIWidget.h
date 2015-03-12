//Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
//Author: Ram
//File: SpaceUIWidget.h
 
#pragma once
 
#include "SpaceHud.h"
#include "Slate.h"
 
class SSpaceUIWidget : public SCompoundWidget
{
	SLATE_BEGIN_ARGS(SSpaceUIWidget)
	{}
        /*See private declaration of OwnerHUD below.*/
	SLATE_ARGUMENT(TWeakObjectPtr<class ASpaceHud>, OwnerHUD)
 
	SLATE_END_ARGS()
 
public:
	////////////////////////////////////////////////////////////////////////////////////////////////////
        /////Needed for every widget
	/////Builds this widget and any of it's children
	void Construct(const FArguments& InArgs);
private:
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/////Pointer to our parent HUD
        /////To make sure HUD's lifetime is controlled elsewhere, use "weak" ptr.
        /////HUD has "strong" pointer to Widget,
        /////circular ownership would prevent/break self-destruction of hud/widget (cause memory leak).
	TWeakObjectPtr<class ASpaceHud> OwnerHUD;
};