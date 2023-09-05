// Fill out your copyright notice in the Description page of Project Settings.


#include "FlightGameMode.h"

AFlightGameMode::AFlightGameMode() :
	DefaultPawnClassProperty(ACharacterPawn::StaticClass())
{
}

void AFlightGameMode::InitGameState()
{
	Super::InitGameState();
	this->DefaultPawnClass = this->DefaultPawnClassProperty;
}
