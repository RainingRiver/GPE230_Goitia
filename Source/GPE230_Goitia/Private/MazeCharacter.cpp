// Fill out your copyright notice in the Description page of Project Settings.

#include "MazeCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AMazeCharacter::AMazeCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMazeCharacter::BeginPlay()
{
	Super::BeginPlay();
	_currentHealth = maxHealth;
}


/// <summary>
/// Function allows for character to take damage
/// </summary>
/// <param name="DamageAmount"></param>
/// <param name="DamageEvent"></param>
/// <param name="EventInstigator"></param>
/// <param name="DamageCauser"></param>
/// <returns></returns>
float AMazeCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	if (!_isDead)
	{
		// Subtract the incoming damage
		_currentHealth -= DamageAmount;

		UE_LOG(LogTemp, Log, TEXT("Player took %f damage. %f health remaining."), DamageAmount, _currentHealth);

		if (_currentHealth <= 0)
		{
			Die();
		}

		return DamageAmount;
	}
	else
	{
		return 0;
	}
}

void AMazeCharacter::Die()
{
	_isDead = true;
	_currentHealth = 0;
	_moveSpeed = 0;
	_rotationSpeed = 0;


	GetMesh()->PlayAnimation(_deathAnim, false);

	// ToDo: Trigger game over state and prompt the player to restart the level
}

// Called every frame
void AMazeCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMazeCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveFB"), this, &AMazeCharacter::MoveFB);
	PlayerInputComponent->BindAxis(TEXT("MoveLR"), this, &AMazeCharacter::MoveLR);
	PlayerInputComponent->BindAxis(TEXT("Rotate"), this, &AMazeCharacter::Rotate);

}

void AMazeCharacter::Heal(float HealAmount)
{
	_currentHealth = HealAmount + _currentHealth;
	if (_currentHealth >= maxHealth)
	{
		_currentHealth = maxHealth;
	}
}

void AMazeCharacter::Hurt(float HurtAmount)
{
	_currentHealth = _currentHealth - HurtAmount;
	if (_currentHealth <= 0)
	{
		Die();
	}
}


/// <summary>
/// Forward and backwards movement
/// </summary>
/// <param name="value"></param>
void AMazeCharacter::MoveFB(float value)
{
	AddMovementInput(GetActorForwardVector(), value * _moveSpeed);
}

/// <summary>
/// Left and right movement
/// </summary>
/// <param name="value"></param>
void AMazeCharacter::MoveLR(float value)
{
	AddMovementInput(-GetActorRightVector(), value * _moveSpeed);
}

/// <summary>
/// Rotation movement
/// </summary>
/// <param name="value"></param>
void AMazeCharacter::Rotate(float value)
{
	AddControllerYawInput(value * _rotationSpeed);
}

void AMazeCharacter::ActiveateStunParticleSystem()
{
	if (_stunSystem)
	{
		USceneComponent* AttachComp = GetDefaultAttachComponent();

		UNiagaraComponent* NiagaraComp = UNiagaraFunctionLibrary::SpawnSystemAttached(_stunSystem, AttachComp, NAME_None,
			FVector(0), FRotator(0), EAttachLocation::Type::KeepRelativeOffset, true);

		NiagaraComp->Activate();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Player tryed to use stun ability, but no template particles system was sound."));
	}
}
