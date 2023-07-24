// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickup.h"
#include "MazeCharacter.h"


APickup::APickup()
{
	OnActorBeginOverlap.AddDynamic(this, &APickup::CheckActorType);
}

/// <summary>
/// Check if the other actor in this trigger is a MazeCharacter. If it is, open the door.
/// </summary>
/// <param name="OverlappedActor"></param>
/// <param name="OtherActor"></param>
void APickup::CheckActorType(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor->IsA(AMazeCharacter::StaticClass()))
		Apply(Cast<AMazeCharacter>(OtherActor));
}

void APickup::Apply(AMazeCharacter* player)
{

}

void APickup::DestroySelf()
{
	this->Destroy();
}
