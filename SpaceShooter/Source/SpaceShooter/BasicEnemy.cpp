// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceShooter.h"
#include "BasicEnemy.h"
#include "Ship.h"

// Sets default values
ABasicEnemy::ABasicEnemy(const class FObjectInitializer& PCIP) : Super(PCIP)
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = PCIP.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Mesh"));
	const ConstructorHelpers::FObjectFinder<UStaticMesh> MeshObj(TEXT("StaticMesh'/Game/ExampleContent/Input_Examples/Meshes/SM_Pixel_Enemy_1.SM_Pixel_Enemy_1'"));
	MeshComponent->SetStaticMesh(MeshObj.Object);
	RootComponent = MeshComponent;

}

// Called when the game starts or when spawned
void ABasicEnemy::BeginPlay()
{
	Super::BeginPlay();
	for (TActorIterator<ASpacyCamera> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		cam = ActorItr->returnSelf();
	}

	position.X = cam->GetActorLocation().X + 500;
	position.Y = cam->GetActorLocation().Y -400;
	position.Z = cam->GetActorLocation().Z + FMath::RandRange(-60,300);
	speed = -20.0f;	
	
	world = GetWorld();
	shootCounter = 0;
}

// Called every frame
void ABasicEnemy::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	
	checkOff();
	ShotCheck(DeltaTime);
	move(DeltaTime);
}

// Called to bind functionality to input
void ABasicEnemy::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void ABasicEnemy::checkOff()
{
	if (GetActorLocation().X < cam->GetActorLocation().X - 500)
		Destroy();
}
void ABasicEnemy::move(float DeltaTime)
{
	position.X += speed*DeltaTime;

	SetActorLocation(FVector(position.X, position.Y, position.Z));
}

void ABasicEnemy::Destroyed()
{
	for (TActorIterator<AShip> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		world->SpawnActor<ASpreadShotPowerup>(GetActorLocation(), GetActorRotation());
		ActorItr->ManipulatePlayerScore(10);
	}
}
void ABasicEnemy::ShotCheck(float DeltaTime)
{
	//shootCounter += DeltaTime*0.5;
	//if (shootCounter >= 1)
	//{
		//projectile = world->SpawnActor<AProjectile>(GetActorLocation(), GetActorRotation());
		//projectile->SetOwner(projectile->ENEMY);
		//shootCounter = 0;
	//}
}