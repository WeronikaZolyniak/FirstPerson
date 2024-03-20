// Fill out your copyright notice in the Description page of Project Settings.


#include "CompassSubsystem.h"
#include "Kismet/KismetMathLibrary.h"

void UCompassSubsystem::SetObjectiveLocation(FVector Location)
{
	ObjectiveLocation = Location;
}

float UCompassSubsystem::CalculateTheAngle(AActor* Actor)
{
	if (Actor != nullptr)
	{
		FVector ActorForwardVector = Actor->GetActorForwardVector();
		FVector ActorRightVector = Actor->GetActorRightVector();
		FVector ObjectiveVector = ObjectiveLocation - Actor->GetActorLocation();
		ObjectiveVector.Normalize();
		float ForwardDotProduct = (ActorForwardVector.X * ObjectiveVector.X) + (ActorForwardVector.Y * ObjectiveVector.Y);
		float RightDotProduct = (ActorRightVector.X * ObjectiveVector.X) + (ActorRightVector.Y * ObjectiveVector.Y);
		float Angle = FMath::RadiansToDegrees(acosf(ForwardDotProduct));
		if (RightDotProduct > 0)
		{
			return Angle;
		}
		else
		{
			return -Angle;
		}
		
	}
	return 0.0f;
}
