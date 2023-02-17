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



	
}

// Called every frame
void AMovingPlatformV2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	// Get current location
	FVector CurrentLocation = GetActorLocation();


	// Check ho far we have moved
	DistanceFromTheStart = FVector::Dist(StartLocation, CurrentLocation);	
	
	if(Direction == AMovingPlatformV2::MovingDirection::Forward)
	{
		CurrentLocation += (PlatformVelocity * DeltaTime);
	}
	else
	{
		CurrentLocation -= (PlatformVelocity * DeltaTime);
	}

	// Set the location
	SetActorLocation(CurrentLocation);

	// Sets direction based on distance from the start
	//FVector::Dist(PlatformVelocity,FVector(0)) -> This will return the distance the platform will move
	if( DistanceFromTheStart >= (FVector::Dist(PlatformVelocity,FVector(0)) * 10) )
	{	
		Direction = AMovingPlatformV2::MovingDirection::Backwards;
	}
	else if (DistanceFromTheStart <= (FVector::Dist(PlatformVelocity, FVector(0)) + 10) )
	{	
		Direction = AMovingPlatformV2::MovingDirection::Forward;
	}




}

