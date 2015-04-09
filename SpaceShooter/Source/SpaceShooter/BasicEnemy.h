// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "SpacyCamera.h"


#include "BasicEnemy.generated.h"


UCLASS()
class SPACESHOOTER_API ABasicEnemy : public APawn
{
	
private:
	ASpacyCamera* cam;
	FVector position;
	float speed;
	void checkOff();
	void move(float DeltaTime);
	void getCam(ASpacyCamera*);
public:
	GENERATED_UCLASS_BODY()
	// Sets default values for this pawn's properties
	

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input

	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	//on ship destroyed
	virtual void Destroyed();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = StaticMesh)
		TSubobjectPtr<UStaticMeshComponent> MeshComponent;

	
	
};
