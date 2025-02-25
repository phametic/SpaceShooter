

#include "SpaceShooter.h"
#include "Ship.h"

AShip::AShip(const class FObjectInitializer& PCIP)
	: Super(PCIP)
{
	ColliderComponent = PCIP.CreateDefaultSubobject<USphereComponent>(this, TEXT("ColliderComponent"));
	ColliderComponent->SetSphereRadius(2.5f);
	
	MeshComponent = PCIP.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Mesh"));
	const ConstructorHelpers::FObjectFinder<UStaticMesh> MeshObj(TEXT("StaticMesh'/Game/ExampleContent/Input_Examples/Meshes/SM_Pixel_Player.SM_Pixel_Player'"));
	MeshComponent->SetStaticMesh(MeshObj.Object);
	RootComponent = MeshComponent;
	
	ColliderComponent->AttachParent = RootComponent;
	ColliderComponent->OnComponentBeginOverlap.AddDynamic(this,&AShip::Hit);

	ExplosionSound = PCIP.CreateDefaultSubobject<UAudioComponent>(this, TEXT("Explosion"));
	const ConstructorHelpers::FObjectFinder<USoundCue> ExplSound(TEXT("SoundCue'/Game/sounds/ExplodeSound.ExplodeSound'"));
	ExplosionSound->Sound = ExplSound.Object;
	ExplosionSound->AttachParent = RootComponent;
	ExplosionSound->bAutoActivate = false;

	LaserSound = PCIP.CreateDefaultSubobject<UAudioComponent>(this, TEXT("Laser1"));
	const ConstructorHelpers::FObjectFinder<USoundCue> LzrSound(TEXT("SoundCue'/Game/sounds/LaserSound.LaserSound'"));
	LaserSound->Sound = LzrSound.Object;
	LaserSound->AttachParent = RootComponent;
	LaserSound->bAutoActivate = false;

	ParticleExhaust = PCIP.CreateDefaultSubobject<UParticleSystemComponent>(this, TEXT("ParticleExhaust"));
	ParticleExhaust->AttachParent = RootComponent;
	static ConstructorHelpers::FObjectFinder<UParticleSystem> pParticleSystem(TEXT("ParticleSystem'/Game/ExampleContent/Input_Examples/Meshes/P_ShipExhaust.P_ShipExhaust'"));
	ParticleExhaust->SetTemplate(pParticleSystem.Object);
	ParticleExhaust->bAutoDestroy = false;

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
	
	//GetWorld()->SpawnActor<AProjectile>(GetActorLocation(), GetActorRotation());
	shootHeld = true;
}

void AShip::OnFireReleased()
{
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
	/*if (!LaserSound->IsPlaying() && shootHeld)
	{
		LaserSound->SetWorldLocation(FVector(position.X + camPos.X, position.Y + camPos.Y, position.Z + camPos.Z));
		LaserSound->Play(0.0f);
		world->SpawnActor<AProjectile>(GetActorLocation(), GetActorRotation());
		shootCounter = 0;
	}*/
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
	if (this->GetActorLocation().X >= 750)
	{
		cam->SetActorLocation(FVector(-3440.0, 260.0, 190.0));
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
	if (!LaserSound->IsPlaying() && shootHeld)
	{
		switch (shotType)
		{
		case NORMAL:
			projectile = world->SpawnActor<AProjectile>(GetActorLocation(), GetActorRotation());
			projectile->SetSpeed(700, 0);
			GEngine->AddOnScreenDebugMessage(10, 5.f, FColor::Black, FString::Printf(TEXT("PROJECTILE 1")));
			break;
		case SPREAD:
			projectile = world->SpawnActor<AProjectile>(GetActorLocation(), GetActorRotation());
			projectile->SetSpeed(700, 0);
			
			projectile = world->SpawnActor<AProjectile>(GetActorLocation(), GetActorRotation());
			projectile->SetSpeed(700, 100);
			
			projectile = world->SpawnActor<AProjectile>(GetActorLocation(), GetActorRotation());
			projectile->SetSpeed(700, -100);
			break;
		}
		LaserSound->SetWorldLocation(FVector(position.X + camPos.X, position.Y + camPos.Y, position.Z + camPos.Z));
		LaserSound->Play(0.0f);
		shootCounter = 0;
	}
}
void AShip::Hit(AActor* TargetActor, UPrimitiveComponent* TargetComp, int32 TargetByIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (TargetActor != nullptr && TargetActor != this && TargetComp != nullptr && (TargetActor->GetName().Contains("Enemy", ESearchCase::IgnoreCase, ESearchDir::FromStart) == true))
	{
		
		ManipulatePlayerLives(-1);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TargetActor->GetName());
		//TargetActor->Destroy();
		ExplosionSound->Play();
		SetActorLocation(FVector(100000,100000,100000));
		position.X = 0;
		position.Y = -400;
		position.Z = 0;
		cam->SetActorLocation(FVector(-3440.0, 260.0, 190.0));
	}
	if (TargetActor != nullptr && TargetActor != this && TargetComp != nullptr && (TargetActor->GetName().Contains("Cube", ESearchCase::IgnoreCase, ESearchDir::FromStart) == true))
	{
		ManipulatePlayerLives(-1);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TargetActor->GetName());
		//TargetActor->Destroy();
		ExplosionSound->Play();
		SetActorLocation(FVector(100000,100000,100000));
		position.X = 0;
		position.Y = -400;
		position.Z = 0;
		cam->SetActorLocation(FVector(-3440.0, 260.0, 190.0));
	}
}