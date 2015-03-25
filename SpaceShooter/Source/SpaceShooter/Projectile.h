

#pragma once

#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "SpacyCamera.h"
#include "BasicEnemy.h"
#include "Projectile.generated.h"

/**
 * 
 */
UCLASS()
class SPACESHOOTER_API AProjectile : public AActor
{
public:
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;
	void Movement(float DeltaTime);
	ABasicEnemy* basicEnemy;
protected:
	GENERATED_UCLASS_BODY()
	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = Collision)
	TSubobjectPtr<USphereComponent> ColliderComponent;
	
	//UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = Movement)
	//TSubobjectPtr<UProjectileMovementComponent> MovementComponent;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = StaticMesh)
	TSubobjectPtr<UStaticMeshComponent> MeshComponent;
	
private:
	ASpacyCamera* cam;
	
	UFUNCTION()
	void Hit(class AActor* SelfActor, AActor* TargetActor, FVector NormalImpulse, struct FHitResult Hit);
};
