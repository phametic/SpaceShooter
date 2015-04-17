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
	void SetSpeed(float newSpeedX, float newSpeedZ);
protected:
	GENERATED_UCLASS_BODY()
		
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Sounds)
		UAudioComponent* ExplosionSound;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = Collision)
		USphereComponent* ColliderComponent;

	//UPROPERTY(BlueprintAssignable, Category = "Collision")
		//FActorHitSignature OnActorHit;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = StaticMesh)
		UStaticMeshComponent* MeshComponent;

	UFUNCTION()
		void Hit(AActor* TargetActor, UPrimitiveComponent* TargetComp, int32 TargetByIndex, bool bFromSweep, const FHitResult& SweepResult);
	
private:
	ASpacyCamera* cam;
	FScriptDelegate Delegate;
	float speedX, speedZ;
};