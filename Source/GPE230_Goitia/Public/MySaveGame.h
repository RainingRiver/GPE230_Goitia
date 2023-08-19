// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"

#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "Blueprint/UserWidget.h"

#include "MySaveGame.generated.h"

/**
 * 
 */
UCLASS()
class GPE230_GOITIA_API UMySaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite)
		int furthestCompletedLevel;
	UPROPERTY(BlueprintReadWrite)
		float masterVolumeSetting;
	UPROPERTY(BlueprintReadWrite)
		float musicVolumeSetting;
	UPROPERTY(BlueprintReadWrite)
		float effectVolumeSetting;

};
