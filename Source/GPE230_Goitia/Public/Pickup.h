// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "Pickup.generated.h"

/**
 * 
 */
UCLASS()
class GPE230_GOITIA_API APickup : public ATriggerBox
{
	GENERATED_BODY()
	

protected:
	UFUNCTION()
		virtual void Apply(class AMazeCharacter* player);
	UFUNCTION()
		virtual void DestroySelf();

public:
	APickup();

	UFUNCTION()
		void CheckActorType(class AActor* OverlappedActor, class AActor* OtherActor);
};
