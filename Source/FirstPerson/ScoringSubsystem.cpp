// Fill out your copyright notice in the Description page of Project Settings.


#include "ScoringSubsystem.h"

void UScoringSubsystem::AddPoints(int NumberToAdd)
{
	Points += NumberToAdd;
}

int UScoringSubsystem::GetCurrentPoints()
{
	return Points;
}
