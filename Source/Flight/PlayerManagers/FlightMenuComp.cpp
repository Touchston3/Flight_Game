// Fill out your copyright notice in the Description page of Project Settings.


#include "FlightMenuComp.h"
#include "FlightPlayerController.h"


// Sets default values for this component's properties
UFlightMenuComp::UFlightMenuComp() :
	MainMenuRootClass(UFlightMenuRoot::StaticClass()),
	MainMenuRoot(CreateDefaultSubobject<UFlightMenuRoot>(TEXT("Temp Root")))
{
	PrimaryComponentTick.bCanEverTick = false;
}




// Called when the game starts
void UFlightMenuComp::BeginPlay()
{
	UActorComponent::BeginPlay();

	this->MainMenuRoot = TStrongObjectPtr(CreateWidget<UFlightMenuRoot>(this->GetParentController(), MainMenuRootClass));
	this->MainMenuRoot->Init(this);

	this->MainMenuRoot->AddToViewport();
	this->GetParentController()->SetShowMouseCursor(true);
}

