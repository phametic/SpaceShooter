

#include "SpaceShooter.h"
#include "SpaceShooterGameMode.h"
#include "Ship.h"


ASpaceShooterGameMode::ASpaceShooterGameMode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	 // set default pawn class to our Blueprinted character
   static ConstructorHelpers::FClassFinder<APawn> PlayerPawnObject(TEXT("Blueprint'/Game/ExampleContent/Input_Examples/Blueprints/BP_Pixel_Ship_Player.BP_Pixel_Ship_Player_C'"));
   if (PlayerPawnObject.Class != NULL)
   {
       DefaultPawnClass = PlayerPawnObject.Class;
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

