// Fill out your copyright notice in the Description page of Project Settings.


#include "MazeGameMode.h"

void AMazeGameMode::InitGameState()
{
	Super::InitGameState();

	//if their is no override for the default pawn class
	if (DefaultPawnClass == ADefaultPawn::StaticClass())
	{
		//Set the pawn to MY pawn
		DefaultPawnClass = DefaultPlayerCharacter;
	}
}