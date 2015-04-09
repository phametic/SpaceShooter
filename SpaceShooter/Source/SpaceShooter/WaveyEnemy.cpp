// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceShooter.h"
#include "WaveyEnemy.h"


// Sets default values
AWaveyEnemy::AWaveyEnemy(const class FPostConstructInitializeProperties& PCIP) : Super(PCIP)
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = PCIP.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Mesh"));
	const ConstructorHelpers::FObjectFinder<UStaticMesh> MeshObj(TEXT("StaticMesh'/Game/ExampleContent/Input_Examples/Meshes/SM_Pixel_Enemy_1.SM_Pixel_Enemy_1'"));
	MeshComponent->SetStaticMesh(MeshObj.Object);
	RootComponent = MeshComponent;
	direction = UP;
}

// Called when the game starts or when spawned
void AWaveyEnemy::BeginPlay()
{
	Super::BeginPlay();
	for (TActorIterator<ASpacyCamera> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		cam = ActorItr->returnSelf();
	}

	position.X = cam->GetActorLocation().X + 500;
	position.Y = cam->GetActorLocation().Y -400;
	position.Z = cam->GetActorLocation().Z + FMath::RandRange(-60,300);
	speedX = -20.0f;
	speedZ = 1.0f;

	world = GetWorld();
	shootCounter = 0;
}

// Called every frame
void AWaveyEnemy::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	
	checkOff();
	move(DeltaTime);
	ShotCheck(DeltaTime);
}

// Called to bind functionality to input
void AWaveyEnemy::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
}

void AWaveyEnemy::checkOff()
{
	if (GetActorLocation().X < cam->GetActorLocation().X - 500)
		Destroy();
}
void AWaveyEnemy::move(float DeltaTime)
{
	position.X += speedX*DeltaTime;
	position.Z += speedZ*DeltaTime;

	if (direction == UP)
	{
		speedZ += 120.0 * DeltaTime;
	}
	else if (direction == DOWN)
	{
		speedZ -= 120.0 * DeltaTime;
	}

	if (speedZ < -120.0)
	{
		direction = UP;
	}
	else if (speedZ > 120.0)
	{
		direction = DOWN;
	}

	SetActorLocation(FVector(position.X, position.Y, position.Z));
}
void AWaveyEnemy::ShotCheck(float DeltaTime)
{
	shootCounter += DeltaTime*0.5;
	if (shootCounter >= 1)
	{
		FVector ProjectileOffset = GetActorLocation();
		ProjectileOffset.X -= 100;
		projectile = world->SpawnActor<AProjectile>(ProjectileOffset, GetActorRotation());
		projectile->SetSpeed(-400);
		//projectile->SetOwner(projectile->ENEMY);
		shootCounter = 0;
	}
}

