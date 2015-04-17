// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "BasicEnemy.h"
#include "WaveyEnemy.h"
#define MAX_TIMER 2
/**
 * 
 */
class SPACESHOOTER_API EnemySpawner
{
public:
	EnemySpawner(UWorld* world);
	~EnemySpawner();
	void Tick(float DeltaTime);

private:
	void RandomTime();
	UWorld* world;
	float CountDownTimer;
};
