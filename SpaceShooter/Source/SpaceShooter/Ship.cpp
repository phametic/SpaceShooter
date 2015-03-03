

#include "SpaceShooter.h"
#include "Ship.h"


AShip::AShip(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	

}

void AShip::SetupPlayerInputComponent(UInputComponent* InputComponent)
{
	// Setup gameplay key bindings
	InputComponent->BindAxis("MoveUpDown", this, &AShip::MoveUpDown);
	InputComponent->BindAxis("MoveLeftRight", this, &AShip::MoveLeftRight);
}

void AShip::BeginPlay()
{
	Super::BeginPlay();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("We are using Ship!"));
	}
}

void AShip::MoveUpDown(float value)
{
	if ((Controller != NULL) && (value != 0.0f))
	{
		AddMovementInput(FVector(0.0f, 0.0f, 1.0f), value);
	}
}

void AShip::MoveLeftRight(float value)
{
	if ((Controller != NULL) && (value != 0.0f))
	{
		AddMovementInput(FVector(1.0f, 0.0f, 0.0f), value);
	}
}
