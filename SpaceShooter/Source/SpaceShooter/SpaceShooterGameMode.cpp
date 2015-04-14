

#include "SpaceShooter.h"
#include "SpaceShooterGameMode.h"
#include "BasicEnemy.h"
#include "SpaceHud.h"

ASpaceShooterGameMode::ASpaceShooterGameMode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	DefaultPawnClass = AShip::StaticClass();
	HUDClass = ASpaceHud::StaticClass();
	UWorld* const World = GetWorld();
	if (World)
	{
		World->SpawnActor<AGenTick>(AGenTick::StaticClass());
	}
}

void ASpaceShooterGameMode::StartPlay()
{
	Super::StartPlay();

	StartMatch();

	if (GEngine)
	{
		
	}
}