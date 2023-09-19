// Fill out your copyright notice in the Description page of Project Settings.


#include "FlightCharacterPawn.h"
#include "FlightCharacterPawnMovement.h"


// Sets default values
AFlightCharacterPawn::AFlightCharacterPawn() :
	InputScheme(EInputScheme::Character),
	MovementComp(CreateDefaultSubobject<UFlightCharacterPawnMovement>(TEXT("Movement_Component")))

{
	PrimaryActorTick.bCanEverTick = true;


}

// Called when the game starts or when spawned
void AFlightCharacterPawn::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void AFlightCharacterPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


