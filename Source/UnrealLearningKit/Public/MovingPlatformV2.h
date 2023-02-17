// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatformV2.generated.h"

UCLASS()
class UNREALLEARNINGKIT_API AMovingPlatformV2 : public AActor
{
	GENERATED_BODY()

private:
	enum MovingDirection {Forward, Backwards};

public:	
	// Sets default values for this actor's properties
	AMovingPlatformV2();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

/// For UPROPERTY parameters 
public:

	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	FVector PlatformVelocity = FVector(100, 0, 0);

	UPROPERTY(VisibleAnywhere, Category = "Moving Platform")
	double DistanceFromTheStartCurrent = 0;

	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	double Distance = 10;

// For standard variables
public:
	FVector StartLocation;
	FVector MoveDirectionNormal;
	MovingDirection Direction = Forward;

	int PositiveCheck = 0;
	double DistancePrevious = 0;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;




};
