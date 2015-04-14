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
		float EnemyChooser = FMath::RandRange(0.0, 1.0);
		if (EnemyChooser < 0.5)
		{
			world->SpawnActor<ABasicEnemy>(ABasicEnemy::StaticClass());
		}
		else
		{
			world->SpawnActor<AWaveyEnemy>(AWaveyEnemy::StaticClass());
		}
		RandomTime();
	}
}
void EnemySpawner::RandomTime()
{
	CountDownTimer = FMath::RandRange(0, MAX_TIMER);
}