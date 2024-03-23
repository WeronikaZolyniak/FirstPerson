// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Components/BoxComponent.h>
#include "Particles/ParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"
#include "LaunchPad.generated.h"


UCLASS()
class FIRSTPERSON_API ALaunchPad : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALaunchPad();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp ,AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
	class UBoxComponent* Collision;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	class UArrowComponent* Arrow;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	class USoundBase* LaunchSound;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	class UParticleSystemComponent* ParticleEmmiter;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Strength;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector Direction;



};
