// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ScoringSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTPERSON_API UScoringSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
protected:
	int Points = 0;
	int Multiplier = 1;

	UFUNCTION(BlueprintCallable)
	void AddPoints(int NumberToAdd);

	UFUNCTION(BlueprintCallable)
	int GetCurrentPoints();

	UFUNCTION(BlueprintCallable)
	void IncreaseMultiplier();

	UFUNCTION(BlueprintCallable)
	int GetCurrentMultiplier();

	UFUNCTION(BlueprintCallable)
	void ResetMultiplier();
};
