// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "SpaceHud.generated.h"

/**
 * 
 */
UCLASS()
class SPACESHOOTER_API ASpaceHud : public AHUD
{
	GENERATED_BODY()
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/////Reference to an SCompoundWidget, TSharedPtr adds to the refcount of MyUIWidget
        /////MyUIWidget will not self-destruct as long as refcount > 0
        /////MyUIWidget refcount will be (refcout-1) if HUD is destroyed.
        TSharedPtr<class SSpaceUIWidget> SpaceUIWidget;
 
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/////Called as soon as game starts, create SCompoundWidget and give Viewport access
	void BeginPlay();
	
	
	
};
