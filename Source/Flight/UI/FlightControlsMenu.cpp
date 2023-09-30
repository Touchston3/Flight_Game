// Fill out your copyright notice in the Description page of Project Settings.


#include "FlightControlsMenu.h"

#include "EnhancedInputSubsystems.h"
#include "Components/ListView.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "PlayerMappableInputConfig.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "Flight/PlayerManagers/FlightPlayerController.h"
#include "Flight/PlayerManagers/FlightMenuComp.h"



void UFlightControlsMenuListEntry::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);
	this->KeyMapping = Cast<UFlightControlsMenuListObject>(ListItemObject)->InputCombination;
	this->Init();
}

TWeakObjectPtr<AFlightPlayerController> UFlightControlsMenuListEntry::GetPlayerController() const
{
	return Cast<AFlightPlayerController>(UUserWidget::GetOwningPlayer());
}

UFlightControlsMenuListObject::UFlightControlsMenuListObject()
{
}

UFlightControlsMenuListEntry::UFlightControlsMenuListEntry(const FObjectInitializer& Initializer) :
	UUserWidget(Initializer)
{
}

void UFlightControlsMenuListEntry::Init()
{
	this->ActionText->SetText(FText::FromString(KeyMapping.Action.GetName()));
	this->InputKeySelector->SetSelectedKey(this->KeyMapping.Key);
	this->ResetButton->OnClicked.AddDynamic(this, &UFlightControlsMenuListEntry::HandleResetButtonClicked);
	this->InputKeySelector->OnKeySelected.AddDynamic(this, &UFlightControlsMenuListEntry::HandleKeySelected);
}

void UFlightControlsMenuListEntry::HandleResetButtonClicked()
{
	if(UEnhancedInputLocalPlayerSubsystem* EnhancedInputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(this->GetPlayerController()->GetLocalPlayer())) //These variable name lengths are getting outta hand
	{
		for(auto DefaultKeyMapping : this->GetPlayerController()->PlayerInputComponent->DefaultInputConfig->GetPlayerMappableKeys())
		{
			if(DefaultKeyMapping.Action == this->KeyMapping.Action)
			{
				this->KeyMapping = DefaultKeyMapping;			
			}
		}
		EnhancedInputSubsystem->AddPlayerMappedKeyInSlot(this->KeyMapping.GetMappingName(), this->KeyMapping.Key);
		this->InputKeySelector->SetSelectedKey(this->KeyMapping.Key);
		this->GetPlayerController()->PlayerInputComponent->ActiveInputConfig->ReloadConfig();
	}
}

void UFlightControlsMenuListEntry::HandleKeySelected(FInputChord InputChord)
{
	if(UEnhancedInputLocalPlayerSubsystem* EnhancedInputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(this->GetPlayerController()->GetLocalPlayer())) //These variable name lengths are getting outta hand
	{
		EnhancedInputSubsystem->AddPlayerMappedKeyInSlot(this->KeyMapping.GetMappingName(), InputChord.Key);
		this->KeyMapping.Key = InputChord.Key;
		this->GetPlayerController()->PlayerInputComponent->ActiveInputConfig->ReloadConfig();
	}
	
}


UFlightControlsMenu::UFlightControlsMenu(const FObjectInitializer& Initializer) :
	UUserWidget(Initializer),
	CharacterBindingsList(CreateDefaultSubobject<UListView>(TEXT("DefaultList")))
{
}


void UFlightControlsMenu::Init(TWeakObjectPtr<UFlightMenuRoot> rootWidget)
{
	this->RootWidget = rootWidget;
	if(this->CharacterBindingsList->GetDefaultEntryClass() != UFlightControlsMenuListEntry::StaticClass()) 
	{
		this->CharacterBindingsList->GetDefaultEntryClass() = UFlightControlsMenuListEntry::StaticClass();
	}
	//Do for each Input Scheme
	for(const FEnhancedActionKeyMapping entry : this->GetPlayerController()->PlayerInputComponent->ActiveInputConfig->GetPlayerMappableKeys())
	{
		UFlightControlsMenuListObject* ListItem = NewObject<UFlightControlsMenuListObject>();
		ListItem->InputCombination = entry;
		this->CharacterBindingsList->AddItem(ListItem);
	}
}

TWeakObjectPtr<AFlightPlayerController> UFlightControlsMenu::GetPlayerController() const
{
	return Cast<AFlightPlayerController>(UUserWidget::GetOwningPlayer());
}
