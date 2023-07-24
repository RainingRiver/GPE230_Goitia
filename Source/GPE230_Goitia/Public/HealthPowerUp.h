// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pickup.h"
#include "HealthPowerUp.generated.h"

/**
 * 
 */
UCLASS()
class GPE230_GOITIA_API AHealthPowerUp : public APickup
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		float healAmount;
	

protected:
		virtual void Apply(class AMazeCharacter* player)override;
};
