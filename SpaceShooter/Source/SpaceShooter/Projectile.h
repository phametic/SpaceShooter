

#pragma once

#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "SpacyCamera.h"
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
	enum OWNER{ENEMY,PLAYER};
	OWNER owner;
	void SetOwner(OWNER owner);
	//ABasicEnemy* basicEnemy;
protected:
	GENERATED_UCLASS_BODY()
	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = Collision)
		TSubobjectPtr<USphereComponent> ColliderComponent;

	//UPROPERTY(BlueprintAssignable, Category = "Collision")
		//FActorHitSignature OnActorHit;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = StaticMesh)
		TSubobjectPtr<UStaticMeshComponent> MeshComponent;

	UFUNCTION()
		void Hit(AActor* TargetActor, UPrimitiveComponent* TargetComp, int32 TargetByIndex, bool bFromSweep, const FHitResult& SweepResult);
	
private:
	ASpacyCamera* cam;
	FScriptDelegate Delegate;
	float speed;
};
