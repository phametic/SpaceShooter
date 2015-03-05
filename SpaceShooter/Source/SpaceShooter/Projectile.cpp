

#include "SpaceShooter.h"
#include "Projectile.h"


AProjectile::AProjectile(const FPostConstructInitializeProperties& ObjectInitializer)
	: Super(ObjectInitializer)
{
	//ColliderComponent = ObjectInitializer.CreateDefaultSubobject<USphereComponent>(this, TEXT("ColliderComponent"));
	//ColliderComponent->SetSphereRadius(2.5f);
	//RootComponent = ColliderComponent;
	
	//MovementComponent = ObjectInitializer.CreateDefaultSubobject<UProjectileMovementComponent>(this, TEXT("MovementComponent"));
	//const ConstructorHelpers::FObjectFinder<UStaticMesh> MeshObj(TEXT("StaticMesh'/Game/ExampleContent/Input_Examples/Meshes/SM_Pixel_Cube.SM_Pixel_Cube'"));
	//MeshComponent->SetStaticMesh(MeshObj.Object);
	
	//MeshComponent->AttachTo(RootComponent);

	//bReplicates = true;
	//bReplicateMovement = true;
}


