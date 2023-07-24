// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthPowerUp.h"
#include "MazeCharacter.h"

void AHealthPowerUp::Apply(AMazeCharacter* player)
{
	player->Heal(healAmount);
	DestroySelf();
}
