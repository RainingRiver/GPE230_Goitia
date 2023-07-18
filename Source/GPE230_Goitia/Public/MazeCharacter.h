// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"

#include "MazeCharacter.generated.h"// This is always last

UCLASS()
class GPE230_GOITIA_API AMazeCharacter : public ACharacter
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
		float _moveSpeed;
	UPROPERTY(EditAnywhere)
		float _rotationSpeed;
	/// <summary>
	/// The animation to play when the player dies
	/// </summary>
	UPROPERTY(EditAnywhere)
		UAnimSequence* _deathAnim;
	/// <summary>
	/// Is this player dead and ready to restart the level?
	/// </summary>
	UPROPERTY(EditAnywhere)
		bool _isDead = false;
	UPROPERTY(EditAnywhere)
		UNiagaraSystem* _stunSystem;



protected:
	/// <summary>
	/// The current health of this character
	/// </summary>
	float _currentHealth;

public:
	/// <summary>
	///	The max health and the starting health of this character
	/// </summary>
	UPROPERTY(EditAnywhere)
	float maxHealth;

public:
	// Sets default values for this character's properties
	AMazeCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
	virtual void Die();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void MoveFB(float value);
	void MoveLR(float value);
	void Rotate(float value);
	UFUNCTION(BlueprintCallable)
	void ActiveateStunParticleSystem();
};
