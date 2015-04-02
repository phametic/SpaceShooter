

#include "SpaceShooter.h"
#include "SpaceShooterGameMode.h"
#include "BasicEnemy.h"
#include "SpaceHud.h"

ASpaceShooterGameMode::ASpaceShooterGameMode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	DefaultPawnClass = AShip::StaticClass();
	HUDClass = ASpaceHud::StaticClass();
}

void ASpaceShooterGameMode::StartPlay()
{
	Super::StartPlay();

	StartMatch();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("HELLO WORLD"));
	}
}