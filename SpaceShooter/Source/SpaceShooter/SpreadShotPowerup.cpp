// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceShooter.h"
#include "SpreadShotPowerup.h"
#include "Ship.h"
// Sets default values
ASpreadShotPowerup::ASpreadShotPowerup(const FPostConstructInitializeProperties& ObjectInitializer)
	: Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	ColliderComponent = ObjectInitializer.CreateDefaultSubobject<USphereComponent>(this, TEXT("ColliderComponent"));
	ColliderComponent->SetSphereRadius(2.5f);
	
	MeshComponent = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Mesh"));
	const ConstructorHelpers::FObjectFinder<UStaticMesh> MeshObj(TEXT("StaticMesh'/Game/ExampleContent/Input_Examples/Meshes/SM_Pixel_SpreadShotPowerup.SM_Pixel_SpreadShotPowerup'"));
	MeshComponent->SetStaticMesh(MeshObj.Object);
	//MeshComponent->AttachTo(RootComponent);
	RootComponent = MeshComponent;

	PrimaryActorTick.bCanEverTick = true;
	ColliderComponent->AttachParent = RootComponent;
	
	ColliderComponent->OnComponentBeginOverlap.AddDynamic(this,&ASpreadShotPowerup::Hit);
}

// Called when the game starts or when spawned
void ASpreadShotPowerup::BeginPlay()
{
	Super::BeginPlay();
	MeshComponent->SetWorldScale3D(FVector(2.0,2.0,2.0));
}

// Called every frame
void ASpreadShotPowerup::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}
void ASpreadShotPowerup::Hit(AActor* TargetActor, UPrimitiveComponent* TargetComp, int32 TargetByIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (TargetActor != nullptr && TargetActor != this && TargetComp != nullptr && (TargetActor->GetName().Contains("Ship", ESearchCase::IgnoreCase, ESearchDir::FromStart) == true))
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TargetActor->GetName());
		for (TActorIterator<AShip> ActorItr(GetWorld()); ActorItr; ++ActorItr)
		{
			ship = *ActorItr;
			ship->shotType = ship->SPREAD;
		}
		this->Destroy();
	}
}

