// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "SpacyCamera.h"
#include "Projectile.h"

#include "WaveyEnemy.generated.h"


UCLASS()
class SPACESHOOTER_API AWaveyEnemy : public APawn
{
	
private:
	enum DIRECTION{UP,DOWN};
	DIRECTION direction;
	ASpacyCamera* cam;
	FVector position;
	float speedX,speedZ;
	float shootCounter;
	UWorld* world;
	AProjectile* projectile;

	void checkOff();
	void move(float DeltaTime);
	void getCam(ASpacyCamera* );
	void ShotCheck(float DeltaTime);
public:
	GENERATED_UCLASS_BODY()
	// Sets default values for this pawn's properties
	

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input

	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = StaticMesh)
		UStaticMeshComponent* MeshComponent;

	
	
};
