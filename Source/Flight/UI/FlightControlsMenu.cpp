// Fill out your copyright notice in the Description page of Project Settings.


#include "FlightControlsMenu.h"

#include "Components/ListView.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Flight/PlayerManagers/FlightMenuComp.h"

UFlightControlsMenuListObject::UFlightControlsMenuListObject() :
	InputCombination({})	
{
}

void UFlightControlsMenuListEntry::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);
	this->InputCombination = Cast<UFlightControlsMenuListObject>(ListItemObject)->InputCombination;
	this->Init();
}

UFlightControlsMenuListEntry::UFlightControlsMenuListEntry(const FObjectInitializer& Initializer) :
	UUserWidget(Initializer),
	InputCombination({})	
{
}

void UFlightControlsMenuListEntry::Init()
{
	this->ActionText->SetText(FText::FromString(this->InputCombination.ActionName));
	this->InputText->SetText(FText::FromString
	(
		this->InputCombination.Modifiers[0].ToString() +
		TEXT(" + ") +	
		this->InputCombination.Modifiers[1].ToString() +
		TEXT(" + ") +	
		this->InputCombination.Modifiers[2].ToString() +
		TEXT(" + ") +	
		this->InputCombination.Key.ToString()
	));

	this->RemapButton->OnClicked.AddDynamic(this, &UFlightControlsMenuListEntry::RemapButtonClicked);
}

void UFlightControlsMenuListEntry::RemapButtonClicked()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Handle Remapping"));
}

UFlightControlsMenu::UFlightControlsMenu(const FObjectInitializer& Initializer) :
	UUserWidget(Initializer),
	CharacterBindingsList(CreateDefaultSubobject<UListView>(TEXT("DefaultList")))
{
}


void UFlightControlsMenu::Init(TWeakObjectPtr<UFlightMenuRoot> rootWidget, TWeakObjectPtr<UFlightMenuComp> parentComponent)
{
	this->RootWidget = rootWidget;
	this->ParentComponent = parentComponent;
	
	if(this->CharacterBindingsList->GetDefaultEntryClass() != UFlightControlsMenuListEntry::StaticClass()) 
	{
		this->CharacterBindingsList->GetDefaultEntryClass() = UFlightControlsMenuListEntry::StaticClass();
	}
	//Do for each Input Scheme
	for(const FInputCombination entry : *this->ParentComponent->GetInputScheme(EInputScheme::Character))
	{
		UFlightControlsMenuListObject* ListItem = NewObject<UFlightControlsMenuListObject>();
		ListItem->InputCombination = entry;
		this->CharacterBindingsList->AddItem(ListItem);
	}
}
