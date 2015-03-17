

#include "SpaceShooter.h"
#include "Ship.h"

AShip::AShip(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	MeshComponent = PCIP.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Mesh"));
	const ConstructorHelpers::FObjectFinder<UStaticMesh> MeshObj(TEXT("StaticMesh'/Game/ExampleContent/Input_Examples/Meshes/SM_Pixel_Player.SM_Pixel_Player'"));
	MeshComponent->SetStaticMesh(MeshObj.Object);
	RootComponent = MeshComponent;
	
	//ProjectileClass = PCIP.CreateDefaultSubobject<AProjectile>(this, TEXT("Projectile Class"));

	position.X = 0;
	position.Y = -400;
	position.Z = 0;
	speed = 300.0;
}

void AShip::SetupPlayerInputComponent(UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	
	// Setup gameplay key bindings
	InputComponent->BindAction("Fire", IE_Pressed, this, &AShip::OnFirePressed);
	InputComponent->BindAction("Fire", IE_Released, this, &AShip::OnFireReleased);
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
	SetActorRotation(FRotator(-90.0,0.0,0.0));
	for (TActorIterator<ASpacyCamera> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		cam = ActorItr->returnSelf();
	}
	world = GetWorld();
	shootCounter = 0;
}

void AShip::MoveUpDown(float value)
{
	velocity.Z = value;
}

void AShip::MoveLeftRight(float value)
{
	velocity.X = value;
}

void AShip::OnFirePressed()
{
	GEngine->AddOnScreenDebugMessage(10, 5.f, FColor::Black, FString::Printf(TEXT("SHOOT PRESSED")));
	//GetWorld()->SpawnActor<AProjectile>(GetActorLocation(), GetActorRotation());
	shootHeld = true;
}

void AShip::OnFireReleased()
{
	GEngine->AddOnScreenDebugMessage(10, 5.f, FColor::Black, FString::Printf(TEXT("SHOOT RELEASED")));
	shootHeld = false;
}

void AShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Movement(DeltaTime);
	ShotCheck(DeltaTime);
}

void AShip::Movement(float DeltaTime)
{
	position.X += (speed * velocity.X)*DeltaTime;
	if (position.X >= 320)
	{
		position.X = 320;
	}
	else if (position.X <= -320)
	{
		position.X = -320;
	}
	position.Z += (speed * velocity.Z)*DeltaTime;
	if (position.Z >= 300)
	{
		position.Z = 300;
	}
	else if (position.Z <= -60)
	{
		position.Z = -60;
	}
	camPos = cam->GetActorLocation();
	SetActorLocation(FVector(position.X+camPos.X,position.Y+camPos.Y,position.Z+camPos.Z));
}

void AShip::ShotCheck(float DeltaTime)
{
	shootCounter += DeltaTime*4;
	if (shootHeld && shootCounter >= 1)
	{
		world->SpawnActor<AProjectile>(GetActorLocation(), GetActorRotation());
		shootCounter = 0;
	}
}