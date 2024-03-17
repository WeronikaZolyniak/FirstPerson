// Fill out your copyright notice in the Description page of Project Settings.


#include "ScoringSubsystem.h"

void UScoringSubsystem::AddPoints(int NumberToAdd)
{
	Points += NumberToAdd * Multiplier;
}

int UScoringSubsystem::GetCurrentPoints()
{
	return Points;
}

void UScoringSubsystem::IncreaseMultiplier()
{
	Multiplier++;
}

int UScoringSubsystem::GetCurrentMultiplier()
{
	return Multiplier;
}

void UScoringSubsystem::ResetMultiplier()
{
	Multiplier = 1;
}
