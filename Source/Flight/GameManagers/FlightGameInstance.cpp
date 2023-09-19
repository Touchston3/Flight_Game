// Fill out your copyright notice in the Description page of Project Settings.


#include "FlightGameInstance.h"
#include "Engine/World.h"
#include "GeneralEngineSettings.h"
#include "..\FlightWorldSettings.h"

UFlightGameInstance::UFlightGameInstance() :
	WorldSettings(CreateDefaultSubobject<AFlightWorldSettings>(TEXT("DefaultWorldSettings")))
{
	
}

void UFlightGameInstance::Init()
{
	this->DefaultWorld = UWorld::CreateWorld(EWorldType::Game, true, TEXT("UserGeneratedWorld")); //I have a lot of work to do with understanding the UWorld class. 
	UGameInstance::GetWorldContext()->SetCurrentWorld(this->DefaultWorld);
	UGameInstance::Init();
	
}

void UFlightGameInstance::Shutdown()
{
	UGameInstance::Shutdown();
}



void UFlightGameInstance::StartGameInstance()
{
	UGameInstance::StartGameInstance();
}

void UFlightGameInstance::ReturnToMainMenu()
{
	UGameInstance::ReturnToMainMenu();
}

void UFlightGameInstance::OnStart()
{
	UGameInstance::OnStart();
}
