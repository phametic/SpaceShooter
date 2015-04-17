// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SpreadShotPowerup.generated.h"

class AShip;

UCLASS()
class SPACESHOOTER_API ASpreadShotPowerup : public AActor
{
	
private:
	AShip* ship;
	UWorld* world;
public:	
	// Sets default values for this actor's properties
	GENERATED_UCLASS_BODY()
	//ASpreadShotPowerup();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = Collision)
		USphereComponent* ColliderComponent;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = StaticMesh)
		UStaticMeshComponent* MeshComponent;
	
	UFUNCTION()
		void Hit(AActor* TargetActor, UPrimitiveComponent* TargetComp, int32 TargetByIndex, bool bFromSweep, const FHitResult& SweepResult);
};
