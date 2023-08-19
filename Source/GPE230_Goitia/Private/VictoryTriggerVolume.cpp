// Fill out your copyright notice in the Description page of Project Settings.


#include "VictoryTriggerVolume.h"
#include "MazeCharacter.h"

void AVictoryTriggerVolume::Apply(AMazeCharacter* player)
{
	player->OpenVictoryScreen();

}
