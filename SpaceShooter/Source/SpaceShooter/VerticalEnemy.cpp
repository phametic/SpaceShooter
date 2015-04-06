// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceShooter.h"
#include "VerticalEnemy.h"


// Sets default values
AVerticalEnemy::AVerticalEnemy(const class FPostConstructInitializeProperties& PCIP) : Super(PCIP)
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = PCIP.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Mesh"));
	const ConstructorHelpers::FObjectFinder<UStaticMesh> MeshObj(TEXT("StaticMesh'/Game/ExampleContent/Input_Examples/Meshes/SM_Pixel_Enemy_1.SM_Pixel_Enemy_1'"));
	MeshComponent->SetStaticMesh(MeshObj.Object);
	RootComponent = MeshComponent;

}

// Called when the game starts or when spawned
void AVerticalEnemy::BeginPlay()
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
	
}

// Called every frame
void AVerticalEnemy::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	
	checkOff();
	move(DeltaTime);
}

// Called to bind functionality to input
void AVerticalEnemy::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void AVerticalEnemy::checkOff()
{
	if (GetActorLocation().X < cam->GetActorLocation().X - 500)
		Destroy();
}
void AVerticalEnemy::move(float DeltaTime)
{
	position.X += speed*DeltaTime;

	SetActorLocation(FVector(position.X, position.Y, position.Z));
}

