// Fill out your copyright notice in the Description page of Project Settings.


#include "FlightMenuRoot.h"

#include "FlightControlsMenu.h"
#include "FlightMainMenu.h"
#include "Flight/PlayerManagers/FlightMenuComp.h"

UFlightMenuRoot::UFlightMenuRoot(const FObjectInitializer& Initializer) :
	UUserWidget(Initializer),
	PageSwitcher(CreateDefaultSubobject<UWidgetSwitcher>(TEXT("MainMenuPageSwitcher"))),
	MainMenu(CreateDefaultSubobject<UFlightMainMenu>(TEXT("MainMenu"))),
	ControlsMenu(CreateDefaultSubobject<UFlightControlsMenu>(TEXT("ControlsMenu")))
{
}



void UFlightMenuRoot::Init(TWeakObjectPtr<UFlightMenuComp> MenuComponent)
{
	this->MainMenu->Init(this, MenuComponent);
	this->ControlsMenu->Init(this, MenuComponent);
}
