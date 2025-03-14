// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "CompassSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTPERSON_API UCompassSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

protected:

	UFUNCTION(BlueprintCallable)
	void SetObjectiveLocation(FVector Location);

	UFUNCTION(BlueprintCallable)
	float CalculateTheAngle(AActor* Actor);

	FVector ObjectiveLocation;
};
