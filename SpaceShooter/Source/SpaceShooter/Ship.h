#pragma once

#include "GameFramework/Character.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Projectile.h"
#include "SpacyCamera.h"
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
	bool shootHeld;
	UWorld* world;
	float shootCounter;
	void Movement(float DeltaTime);
	void ShotCheck(float DeltaTime);
public:
	void Tick(float DeltaTime);

protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
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
