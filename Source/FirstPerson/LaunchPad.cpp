// Fill out your copyright notice in the Description page of Project Settings.


#include "LaunchPad.h"
#include "GameFramework/Character.h"
#include "Components/PrimitiveComponent.h"


// Sets default values
ALaunchPad::ALaunchPad()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Collision = CreateDefaultSubobject<UBoxComponent>(FName("Collision"));
	Collision->SetBoxExtent(FVector(46.f,46.f,5.f));
	Collision->SetupAttachment(RootComponent);
	Collision->OnComponentBeginOverlap.AddDynamic(this, &ALaunchPad::OnOverlapBegin);






}

// Called when the game starts or when spawned
void ALaunchPad::BeginPlay()
{
	Super::BeginPlay();

	//UE_LOG(LogTemp, Warning, TEXT("log works"));
	
}

void ALaunchPad::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlapping Collision"));

	if (OtherActor->IsA(ACharacter::StaticClass()))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Overlapping Object is a player"));
		Cast<ACharacter>(OtherActor)->LaunchCharacter(Direction * Strength, true, true);

	}
	else if(OtherComp && OtherComp->IsSimulatingPhysics())
	{
		UE_LOG(LogTemp, Warning, TEXT("Overlapping Object is not a player"));
		OtherComp->AddImpulse(Direction * Strength, NAME_None , true);
	}
}



// Called every frame
void ALaunchPad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

