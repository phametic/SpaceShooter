

#include "SpaceShooter.h"
#include "Projectile.h"
#include "BasicEnemy.h"

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

	//ColliderComponent->OnComponentBeginOverlap.AddDynamic(this,&AProjectile::OnOverlap);
}
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Movement(DeltaTime);
	FHitResult hit;
	//Hit(this, basicEnemy, basicEnemy->GetActorLocation(), hit);
}
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	for (TActorIterator<ASpacyCamera> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		cam = ActorItr->returnSelf();
	}
}
void AProjectile::Movement(float DeltaTime)
{
	SetActorLocation(FVector(GetActorLocation().X+400*DeltaTime,GetActorLocation().Y,GetActorLocation().Z));
	if (GetActorLocation().X > (cam->GetActorLocation().X + 550))
	{
		Destroy();
	}
}
void AProjectile::Hit(class AActor* SelfActor, AActor* TargetActor, FVector NormalImpulse, struct FHitResult Hit)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("PROJECTILE HIT ENEMY!"));
}

