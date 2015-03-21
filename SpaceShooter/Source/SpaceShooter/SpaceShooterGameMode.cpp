

#include "SpaceShooter.h"
#include "SpaceShooterGameMode.h"
#include "BasicEnemy.h"

ASpaceShooterGameMode::ASpaceShooterGameMode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	DefaultPawnClass = AShip::StaticClass();
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
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("HELLO WORLD"));
	}
}