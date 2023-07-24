// Fill out your copyright notice in the Description page of Project Settings.


#include "PainPickup.h"
#include "MazeCharacter.h"

void APainPickup::Apply(AMazeCharacter* player)
{
	player->Hurt(hurtAmount);
	DestroySelf();
}
