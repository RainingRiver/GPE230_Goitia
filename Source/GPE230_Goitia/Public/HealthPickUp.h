// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pickup.h"
#include "HealthPickUp.generated.h"

UCLASS()
class GPE230_GOITIA_API AHealthPickUp : public APickup
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHealthPickUp();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Heal(float HealAmount);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
