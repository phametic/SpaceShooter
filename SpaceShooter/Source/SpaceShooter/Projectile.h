

#pragma once

#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Projectile.generated.h"

/**
 * 
 */
UCLASS()
class SPACESHOOTER_API AProjectile : public AActor
{
public:
	virtual void Tick(float DeltaTime) override;
protected:
	GENERATED_UCLASS_BODY()
	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = Collision)
	TSubobjectPtr<USphereComponent> ColliderComponent;
	
	//UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = Movement)
	//TSubobjectPtr<UProjectileMovementComponent> MovementComponent;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = StaticMesh)
	TSubobjectPtr<UStaticMeshComponent> MeshComponent;
	
};
