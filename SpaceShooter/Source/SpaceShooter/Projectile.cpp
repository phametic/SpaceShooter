

#include "SpaceShooter.h"
#include "Projectile.h"

AProjectile::AProjectile(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{	
	ColliderComponent = ObjectInitializer.CreateDefaultSubobject<USphereComponent>(this, TEXT("ColliderComponent"));
	ColliderComponent->SetSphereRadius(2.5f);
	
	ExplosionSound = ObjectInitializer.CreateDefaultSubobject<UAudioComponent>(this, TEXT("Explosion"));
	const ConstructorHelpers::FObjectFinder<USoundCue> ExplSound(TEXT("SoundCue'/Game/sounds/ExplodeSound.ExplodeSound'"));
	ExplosionSound->Sound = ExplSound.Object;
	ExplosionSound->AttachParent = RootComponent;
	ExplosionSound->bAutoActivate = false;

	MeshComponent = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Mesh"));
	const ConstructorHelpers::FObjectFinder<UStaticMesh> MeshObj(TEXT("StaticMesh'/Game/ExampleContent/Input_Examples/Meshes/SM_Pixel_Cube.SM_Pixel_Cube'"));
	MeshComponent->SetStaticMesh(MeshObj.Object);
	//MeshComponent->AttachTo(RootComponent);
	RootComponent = MeshComponent;

	PrimaryActorTick.bCanEverTick = true;
	ColliderComponent->AttachParent = RootComponent;
	ColliderComponent->OnComponentBeginOverlap.AddDynamic(this,&AProjectile::Hit);

	speedX = 400;
	speedZ = 0;
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
	SetActorLocation(FVector(GetActorLocation().X+speedX*DeltaTime,GetActorLocation().Y,GetActorLocation().Z+speedZ*DeltaTime));
	if (GetActorLocation().X > (cam->GetActorLocation().X + 550))
	{
		Destroy();
	}
}
void AProjectile::Hit(AActor* TargetActor, UPrimitiveComponent* TargetComp, int32 TargetByIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (TargetActor != nullptr && TargetActor != this && TargetComp != nullptr && (TargetActor->GetName().Contains("Enemy", ESearchCase::IgnoreCase, ESearchDir::FromStart) == true))
	{
		ExplosionSound->bStopWhenOwnerDestroyed = false;
		ExplosionSound->Activate();
		ExplosionSound->Play();
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TargetActor->GetName());
		TargetActor->Destroy();
		this->Destroy();
	}
}
void AProjectile::SetSpeed(float newSpeedX, float newSpeedZ)
{
	speedX = newSpeedX;
	speedZ = newSpeedZ;
}

