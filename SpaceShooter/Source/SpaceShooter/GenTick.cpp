// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceShooter.h"
#include "GenTick.h"


// Sets default values
AGenTick::AGenTick()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	spawner = new EnemySpawner(GetWorld());

}

// Called when the game starts or when spawned
void AGenTick::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGenTick::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	spawner->Tick(DeltaTime);
}

