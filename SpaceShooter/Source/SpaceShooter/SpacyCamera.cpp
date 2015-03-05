

#include "SpaceShooter.h"
#include "SpacyCamera.h"


ASpacyCamera::ASpacyCamera(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	PrimaryActorTick.bCanEverTick = true;
	CameraComponent = PCIP.CreateDefaultSubobject<UCameraComponent>(this, TEXT("Shmup Camera"));
	RootComponent = CameraComponent;

}
void ASpacyCamera::Tick(float DeltaTime)
{
	//SetActorLocation(FVector(GetActorLocation().X+1,GetActorLocation().Y,GetActorLocation().Z));
	Super::Tick(DeltaTime);
	SetActorLocation(FVector(GetActorLocation().X+50.0*DeltaTime,GetActorLocation().Y,GetActorLocation().Z));
}

