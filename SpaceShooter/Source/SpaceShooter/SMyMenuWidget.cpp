// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceShooter.h"
#include "SMyMenuWidget.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMyMenuWidget::Construct(const FArguments& InArgs)
{
	ChildSlot
	.HAlign(HAlign_Center)
	.VAlign(VAlign_Center)
	[
		// Populate the widget
		SAssignNew(MenuContainer, SVerticalBox)
	];
}

void SMyMenuWidget::AddMenuItem(FText Label, FOnClicked Callback)
{
	MenuContainer->AddSlot()
		.AutoHeight()
		.Padding(FMargin(0, 5))
		[
			SNew(SBox)
			.WidthOverride(250)
			.HeightOverride(45)
			[
				SNew(SButton)
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Center)
				.OnClicked(Callback)
				[
					SNew(STextBlock)
					.Text(Label)
				]
			]
		];
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
