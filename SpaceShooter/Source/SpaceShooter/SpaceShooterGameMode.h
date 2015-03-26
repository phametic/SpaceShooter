

#pragma once

#include "GameFramework/GameMode.h"
#include "Ship.h"
#include "GenTick.h"
#include "SpaceShooterGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SPACESHOOTER_API ASpaceShooterGameMode : public AGameMode
{
	GENERATED_UCLASS_BODY()

		virtual void StartPlay() override;
	
};
