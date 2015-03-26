// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceShooter.h"
#include "EnemySpawner.h"

EnemySpawner::EnemySpawner(UWorld* world)
{
	this->world = world;
	CountDownTimer = 0;
	RandomTime();
}

EnemySpawner::~EnemySpawner()
{
}

void EnemySpawner::Tick(float DeltaTime)
{
	CountDownTimer -= DeltaTime;
	if (CountDownTimer <= 0)
	{
		world->SpawnActor<ABasicEnemy>(ABasicEnemy::StaticClass());
		RandomTime();
	}
}
void EnemySpawner::RandomTime()
{
	CountDownTimer = FMath::RandRange(0, MAX_TIMER);
}