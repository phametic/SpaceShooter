#pragma once

#include "GameFramework/Character.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Projectile.h"
#include "SpacyCamera.h"
#include "BasicEnemy.h"
#include "Ship.generated.h"

/**
 * 
 */
UCLASS()
class SPACESHOOTER_API AShip : public APawn
{
	GENERATED_UCLASS_BODY()

		virtual void BeginPlay() override;

private:
	FVector position;
	FVector camPos;
	FVector velocity;
	float speed;
	ASpacyCamera* cam;
	AProjectile* projectile;
	AProjectile* projectile2;
	AProjectile* projectile3;
	bool shootHeld;
	UWorld* world;
	float shootCounter;

	int32 PlayerScore;
	int32 PlayerLives;
	void Movement(float DeltaTime);
	void ShotCheck(float DeltaTime);
public:
	enum SHOTTYPE{NORMAL,SPREAD};
	SHOTTYPE shotType;
	void Tick(float DeltaTime);

	int32 GetPlayerScore();
	void SetPlayerScore(int32 score);
	void ManipulatePlayerScore(int32 score);

	int32 GetPlayerLives();
	void SetPlayerLives(int32 lives);
	void ManipulatePlayerLives(int32 lives);
	
	UFUNCTION()
	void Hit(AActor* TargetActor, UPrimitiveComponent* TargetComp, int32 TargetByIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = Collision)
		TSubobjectPtr<USphereComponent> ColliderComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = StaticMesh)
	TSubobjectPtr<UStaticMeshComponent> MeshComponent;
	
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Projectiles)
	//TSubobjectPtr<AProjectile> ProjectileClass;
	
	//Up & Down movement
	UFUNCTION()
		void MoveUpDown(float value);

	//Left & Right movement
	UFUNCTION()
		void MoveLeftRight(float value);

	UFUNCTION()
		void OnFirePressed();
	UFUNCTION()
		void OnFireReleased();
};
