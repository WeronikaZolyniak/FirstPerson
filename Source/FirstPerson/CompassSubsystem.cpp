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
		FVector ActorLocation = Actor->GetActorLocation();
		float DotProduct = (ActorLocation.X * ObjectiveLocation.X) + (ActorLocation.Y * ObjectiveLocation.Y);
		float ObjectiveMagnitude = sqrtf((ObjectiveLocation.X * ObjectiveLocation.X) + (ObjectiveLocation.Y * ObjectiveLocation.Y));
		float ActorMagnitude = sqrtf((ActorLocation.X * ActorLocation.X) + (ActorLocation.Y * ActorLocation.Y));
		float Quotient = DotProduct / (ObjectiveMagnitude * ActorMagnitude);
		float Angle = FMath::RadiansToDegrees(acosf(Quotient));
		return Angle;
	}
	return 0.0f;
}
