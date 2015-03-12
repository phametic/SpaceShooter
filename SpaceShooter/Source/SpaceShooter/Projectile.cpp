

#include "SpaceShooter.h"
#include "Projectile.h"


AProjectile::AProjectile(const FPostConstructInitializeProperties& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ColliderComponent = ObjectInitializer.CreateDefaultSubobject<USphereComponent>(this, TEXT("ColliderComponent"));
	ColliderComponent->SetSphereRadius(2.5f);
	
	//MovementComponent = ObjectInitializer.CreateDefaultSubobject<UProjectileMovementComponent>(this, TEXT("MovementComponent"));
	
	MeshComponent = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Mesh"));
	const ConstructorHelpers::FObjectFinder<UStaticMesh> MeshObj(TEXT("StaticMesh'/Game/ExampleContent/Input_Examples/Meshes/SM_Pixel_Cube.SM_Pixel_Cube'"));
	MeshComponent->SetStaticMesh(MeshObj.Object);
	//MeshComponent->AttachTo(RootComponent);
	RootComponent = MeshComponent;

	PrimaryActorTick.bCanEverTick = true;

	//bReplicates = true;
	//bReplicateMovement = true;

	//MovementComponent->ProjectileGravityScale = 0.0;
}
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetActorLocation(FVector(GetActorLocation().X+400*DeltaTime,GetActorLocation().Y,GetActorLocation().Z));
}

