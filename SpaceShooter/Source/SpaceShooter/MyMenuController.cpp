// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceShooter.h"
#include "MyMenuController.h"
#include "SpaceShooterGameMode.h"
#include "MyPlayerController.h"


void AMyMenuController::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	if (GEngine && GEngine->GameViewport)
	{
		UGameViewportClient* Viewport = GEngine->GameViewport;

		MyMenuWidget = SNew(SMyMenuWidget);

		Viewport->AddViewportWidgetContent(
			MyMenuWidget.ToSharedRef());

		MyMenuWidget->AddMenuItem(
			NSLOCTEXT("SpaceShooter", "PLAYLABEL", "PLAY"),
			FOnClicked::CreateUObject(
				this,
				&AMyMenuController::OnPlayClicked
			)
		);
		MyMenuWidget->AddMenuItem(
			NSLOCTEXT("SpaceShooter", "OPTIONSLABEL", "OPTIONS"),
			FOnClicked::CreateUObject(
				this,
				&AMyMenuController::OnOptionsClicked
			)
		);
		MyMenuWidget->AddMenuItem(
			NSLOCTEXT("SpaceShooter", "QUITLABEL", "QUIT"),
			FOnClicked::CreateUObject(
				this,
				&AMyMenuController::OnQuitClicked
			)
		);
	}
}

FReply AMyMenuController::OnPlayClicked()
{
	GEngine->AddOnScreenDebugMessage(
		1,
		5.f,
		FColor::Red,
		TEXT("PLAY CLICKED"));

	//GameMode = ASpaceShooterGameMode::StaticClass();

	return FReply::Handled();
}

FReply AMyMenuController::OnOptionsClicked()
{
	GEngine->AddOnScreenDebugMessage(
		1,
		5.f,
		FColor::Red,
		TEXT("OPTIONS CLICKED"));

	return FReply::Handled();
}

FReply AMyMenuController::OnQuitClicked()
{
	GEngine->AddOnScreenDebugMessage(
		1,
		5.f,
		FColor::Red,
		TEXT("QUIT CLICKED"));

	return FReply::Handled();
}

