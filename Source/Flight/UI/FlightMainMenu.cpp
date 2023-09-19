// Fill out your copyright notice in the Description page of Project Settings.


#include "FlightMainMenu.h"

#include "FlightMenuRoot.h"
#include "Flight/PlayerManagers/FlightPlayerController.h"

UFlightMainMenu::UFlightMainMenu(const FObjectInitializer& Initializer) :
	UUserWidget(Initializer)
{
	
}

void UFlightMainMenu::Init(TWeakObjectPtr<UFlightMenuRoot> rootWidget, TWeakObjectPtr<UFlightMenuComp> parentComponent)
{
	this->RootWidget = rootWidget;
	this->ParentComponent = parentComponent;

	this->ReturnButton->OnClicked.AddDynamic(this, &UFlightMainMenu::ReturnButtonClicked);
	this->ControlsSettingsButton->OnClicked.AddDynamic(this, &UFlightMainMenu::ControlsSettingsButtonClicked);
	this->GraphicsSettingsButton->OnClicked.AddDynamic(this, &UFlightMainMenu::GraphicsSettingsButtonClicked);
}

void UFlightMainMenu::ReturnButtonClicked()
{
	this->ParentComponent->GetParentController()->SetShowMouseCursor(false);
	this->RootWidget->RemoveFromParent();
}

void UFlightMainMenu::ControlsSettingsButtonClicked()
{
	this->RootWidget->GetPageSwitcher()->SetActiveWidgetIndex((uint8)EMenuIndex::ControlsMenu);
}

void UFlightMainMenu::GraphicsSettingsButtonClicked()
{
	if(GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Graphics Settings"));
}
