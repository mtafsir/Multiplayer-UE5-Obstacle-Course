// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatformV2.h"

// Sets default values
AMovingPlatformV2::AMovingPlatformV2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatformV2::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();

	// This is the normal vector for direction for one unit of movement in the designated velocity path
	MoveDirectionNormal = PlatformVelocity.GetSafeNormal();



	
}

// Called every frame
void AMovingPlatformV2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	

	// Get current location
	FVector CurrentLocation = GetActorLocation();
		
	
	if(Direction == AMovingPlatformV2::MovingDirection::Forward)
	{
		CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
		FVector test = (PlatformVelocity * DeltaTime);
	}
	else
	{
		CurrentLocation -= (PlatformVelocity * DeltaTime);
	}



	// Set the location
	SetActorLocation(CurrentLocation);

	// Check how far we have moved
	DistanceFromTheStartCurrent = FVector::Dist(StartLocation, CurrentLocation);

	// Sets direction based on distance from the start
	//FVector::Dist(PlatformVelocity,FVector(0)) -> This will return the distance the platform will move
	if( DistanceFromTheStartCurrent >= Distance)
	{	
		CurrentLocation = StartLocation + MoveDirectionNormal * DistanceFromTheStartCurrent;
		SetActorLocation(CurrentLocation);

		Direction = AMovingPlatformV2::MovingDirection::Backwards;
		
		// A flag that a positive distance in comparison to the previous run should not appear again without the direction being changed
		PositiveCheck = 1;
	}
	else if (DistanceFromTheStartCurrent >= 0 && (0 < DistanceFromTheStartCurrent - DistancePrevious) && PositiveCheck == 1)
	{	
		SetActorLocation(StartLocation);

		Direction = AMovingPlatformV2::MovingDirection::Forward;
		PositiveCheck = 0;
	}

	DistancePrevious = DistanceFromTheStartCurrent;


}

