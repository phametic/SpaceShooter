// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/**
 * 
 */
class SPACESHOOTER_API SMyMenuWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMyMenuWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	void AddMenuItem(FText Label, FOnClicked Callback);

private:
	TSharedPtr<SVerticalBox> MenuContainer;
};
