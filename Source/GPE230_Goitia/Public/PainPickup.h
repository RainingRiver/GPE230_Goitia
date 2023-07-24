// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pickup.h"
#include "PainPickup.generated.h"

/**
 * 
 */
UCLASS()
class GPE230_GOITIA_API APainPickup : public APickup
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		float hurtAmount;


protected:
	virtual void Apply(class AMazeCharacter* player)override;
};
