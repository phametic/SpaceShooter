//Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
//Author: Ram
//File: SpaceUIWidget.cpp
 
#include "SpaceShooter.h"
#include "SpaceUIWidget.h"
 
void SSpaceUIWidget::Construct(const FArguments& InArgs)
{
	OwnerHUD = InArgs._OwnerHUD;
 
	////////////////////////////////////////////////////////////////////////////////////////////////////
        /////If the code below doesn't look like C++ to you it's because it (sort-of) isn't,
        /////Slate makes extensive use of the C++ Prerocessor(macros) and operator overloading,
        /////Epic is trying to make our lives easier, look-up the macro/operator definitions to see why.
	ChildSlot
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Top)
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
			.VAlign(VAlign_Top)
			.HAlign(HAlign_Center)
			[
				SNew(STextBlock)
				.ShadowColorAndOpacity(FLinearColor::Black)
				.ColorAndOpacity(FLinearColor::White)
				.ShadowOffset(FIntPoint(-1, 1))
				.Font(FSlateFontInfo("Veranda", 30))
				.Text(this,&SSpaceUIWidget::GetScore)
			]
			+ SOverlay::Slot()
			.VAlign(VAlign_Top)
			.HAlign(HAlign_Left)
			.Padding(FMargin(-5.5,50))
			[
				SNew(STextBlock)
				.ShadowColorAndOpacity(FLinearColor::Black)
				.ColorAndOpacity(FLinearColor::White)
				.ShadowOffset(FIntPoint(-1, 1))
				.Font(FSlateFontInfo("Veranda", 30))
				.Text(this,&SSpaceUIWidget::GetLives)
			]
		];

	
}

FText SSpaceUIWidget::GetScore() const
{
	FString tempString;

	for(TObjectIterator<AShip> Itr; Itr; ++Itr)
	{
		 tempString = "Highscore: " + FString::FromInt(Itr->GetPlayerScore());
	}

	return FText::FromString(tempString);
}

FText SSpaceUIWidget::GetLives() const
{
	FString tempString;

	for(TObjectIterator<AShip> Itr; Itr; ++Itr)
	{
		 tempString = "Lives: " + FString::FromInt(Itr->GetPlayerLives());
	}

	return FText::FromString(tempString);
}