

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

	position.X = 0;
	position.Y = -400;
	position.Z = 0;

	SetPlayerLives(3);
	SetPlayerScore(0);

	if (GEngine)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("We are using Ship!"));
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
	
	/*
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
	*/
	shootCounter += DeltaTime*4;
	if (shootHeld && shootCounter >= 1)
	{
		world->SpawnActor<AProjectile>(GetActorLocation(), GetActorRotation());
		shootCounter = 0;
	}
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

int32 AShip::GetPlayerScore()
{
	return PlayerScore;
}
void AShip::SetPlayerScore(int32 score)
{
	PlayerScore = score;
}
void AShip::ManipulatePlayerScore(int32 score)
{
	PlayerScore += score;
}

int32 AShip::GetPlayerLives()
{
	return PlayerLives;
}
void AShip::SetPlayerLives(int32 lives)
{
	PlayerLives = lives;
}
void AShip::ManipulatePlayerLives(int32 lives)
{
	PlayerLives += lives;
}
void AShip::ShotCheck(float DeltaTime)
{
	shootCounter += DeltaTime*4;
	if (shootHeld && shootCounter >= 1)
	{
		switch (shotType)
		{
		case NORMAL:
			projectile = world->SpawnActor<AProjectile>(GetActorLocation(), GetActorRotation());
			projectile->SetSpeed(400, 0);
			GEngine->AddOnScreenDebugMessage(10, 5.f, FColor::Black, FString::Printf(TEXT("PROJECTILE 1")));
			break;
		case SPREAD:
			projectile = world->SpawnActor<AProjectile>(GetActorLocation(), GetActorRotation());
			projectile->SetSpeed(400, 0);
			
			projectile = world->SpawnActor<AProjectile>(GetActorLocation(), GetActorRotation());
			projectile->SetSpeed(400, 100);
			
			projectile = world->SpawnActor<AProjectile>(GetActorLocation(), GetActorRotation());
			projectile->SetSpeed(400, -100);
			break;
		}
		shootCounter = 0;
	}
}