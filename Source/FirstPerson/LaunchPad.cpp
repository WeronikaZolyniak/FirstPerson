// Fill out your copyright notice in the Description page of Project Settings.


#include "LaunchPad.h"
#include "GameFramework/Character.h"
#include "Components/PrimitiveComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/ArrowComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ALaunchPad::ALaunchPad()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Collision = CreateDefaultSubobject<UBoxComponent>(FName("Collision"));
	Collision->SetBoxExtent(FVector(46.f, 46.f, 45.f));
	RootComponent = Collision;
	Collision->OnComponentBeginOverlap.AddDynamic(this, &ALaunchPad::OnOverlapBegin);

	Arrow = CreateDefaultSubobject<UArrowComponent>(FName("Arrow"));
	Arrow->SetupAttachment(RootComponent);
	Arrow->SetRelativeLocation(FVector(0, 0, -20));
	Arrow->SetRelativeRotation(Direction.Rotation());
}

// Called when the game starts or when spawned
void ALaunchPad::BeginPlay()
{
	Super::BeginPlay();

	FRotator LaunchPadRotation = GetActorRotation();
	Direction = LaunchPadRotation.RotateVector(Direction);	
}

void ALaunchPad::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), LaunchSound, GetActorLocation());

	if (OtherActor->IsA(ACharacter::StaticClass()))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Overlapping Object is a player"));
		Cast<ACharacter>(OtherActor)->LaunchCharacter(Direction * Strength, true, true);

		UCharacterMovementComponent* MovComp = OtherActor->FindComponentByClass<UCharacterMovementComponent>();
		//UE_LOG(LogTemp, Warning, TEXT("Movement Component: %s"), *MovComp->GetName());

		if(MovComp != nullptr) MovComp->AirControl = 0;
	}
	else if(OtherComp && OtherComp->IsSimulatingPhysics())
	{
		//UE_LOG(LogTemp, Warning, TEXT("Overlapping Object is not a player"));
		OtherComp->AddImpulse(Direction * Strength, NAME_None , true);
	}
}

#if WITH_EDITOR
void ALaunchPad::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	Arrow->SetRelativeRotation(Direction.Rotation());
}
#endif


// Called every frame
void ALaunchPad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

