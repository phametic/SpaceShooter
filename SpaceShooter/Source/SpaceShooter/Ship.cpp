

#include "SpaceShooter.h"
#include "Ship.h"


AShip::AShip(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	MeshComponent = PCIP.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Mesh"));
	//const ConstructorHelpers::FObjectFinder<UStaticMesh> MeshObj(TEXT("StaticMesh'/Game/UFO.UFO'"));
	//const ConstructorHelpers::FObjectFinder<UStaticMesh> MeshObj(TEXT("StaticMesh'/Game/UFO.UFO'"));
	const ConstructorHelpers::FObjectFinder<UStaticMesh> MeshObj(TEXT("StaticMesh'/Game/ExampleContent/Input_Examples/Meshes/SM_Pixel_Player.SM_Pixel_Player'"));
	MeshComponent->SetStaticMesh(MeshObj.Object);
	RootComponent = MeshComponent;
	
}

void AShip::SetupPlayerInputComponent(UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	
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
	UpMovement = value;
	//if ((Controller != NULL) && (value != 0.0f))
	//{
		//AddMovementInput(FVector(0.0f, 0.0f, 1.0f), value);
	//}
}

void AShip::MoveLeftRight(float value)
{
	RightMovement = value;
	//if ((Controller != NULL) && (value != 0.0f))
	//{
		//AddMovementInput(FVector(1.0f, 0.0f, 0.0f), value);
	//}
}
void AShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (RightMovement != 0.f)
	{
		//AddMovementInput(GetActorRightVector() * RightMovement);
		SetActorLocation(FVector(GetActorLocation().X+250.0*RightMovement*DeltaTime,GetActorLocation().Y,GetActorLocation().Z));
		GEngine->AddOnScreenDebugMessage(10, 5.f, FColor::Black, FString::Printf(TEXT("MOVEMENT")));
	}
	else
	{
		SetActorLocation(FVector(GetActorLocation().X+50.0*DeltaTime,GetActorLocation().Y,GetActorLocation().Z));
	}
	if (UpMovement != 0.f)
	{
		SetActorLocation(FVector(GetActorLocation().X,GetActorLocation().Y,GetActorLocation().Z+250.0*UpMovement*DeltaTime));
	}
}