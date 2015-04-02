// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SMyMenuWidget.h"
#include "GameFramework/PlayerController.h"
#include "MyMenuController.generated.h"


/**
 * 
 */
UCLASS()
class SPACESHOOTER_API AMyMenuController : public APlayerController
{
	GENERATED_BODY()
	
public:
	void PostInitializeComponents() override;
private:
	TSharedPtr<SMyMenuWidget> MyMenuWidget;

	FReply OnPlayClicked();
	FReply OnOptionsClicked();
	FReply OnQuitClicked();
	
};
