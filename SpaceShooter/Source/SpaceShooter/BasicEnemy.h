// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "SpacyCamera.h"


#include "BasicEnemy.generated.h"


UCLASS()
class SPACESHOOTER_API ABasicEnemy : public APawn
{
	GENERATED_BODY()
private:
	ASpacyCamera* cam;
	FVector position;
	void getCam(ASpacyCamera*);
public:
	// Sets default values for this pawn's properties
	ABasicEnemy();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	
	
};
