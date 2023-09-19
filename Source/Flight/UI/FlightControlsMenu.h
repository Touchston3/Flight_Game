// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Flight/PlayerManagers/FlightInputComp.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "FlightControlsMenu.generated.h"

class UFlightMenuRoot;
class UListView;
class UFlightMenuComp;
class UTextBlock;
class UButton;
UCLASS(NotBlueprintable)
class FLIGHT_API UFlightControlsMenuListObject : public UObject
{
	GENERATED_BODY()

public:
	UFlightControlsMenuListObject();
	FInputCombination InputCombination;
};

UCLASS(Blueprintable)
class FLIGHT_API UFlightControlsMenuListEntry : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

public:
	UFlightControlsMenuListEntry(const FObjectInitializer& Initializer);
	void Init();
protected:
	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;
private:
	
	FInputCombination InputCombination;
	
	UPROPERTY(EditDefaultsOnly, meta=(BindWidget))
	UTextBlock* ActionText;
	UPROPERTY(EditDefaultsOnly, meta=(BindWidget))
	UTextBlock* InputText;
	UPROPERTY(EditDefaultsOnly, meta=(BindWidget))
	UButton* RemapButton;


	UFUNCTION()
	void RemapButtonClicked();
};

UCLASS(Blueprintable)
class FLIGHT_API UFlightControlsMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	UFlightControlsMenu(const FObjectInitializer& Initializer);
	void Init(TWeakObjectPtr<UFlightMenuRoot> rootWidget, TWeakObjectPtr<UFlightMenuComp> parentComponent);
private:
	TWeakObjectPtr<UFlightMenuRoot> RootWidget;
	TWeakObjectPtr<UFlightMenuComp> ParentComponent;
	
	UPROPERTY(EditDefaultsOnly, meta=(BindWidget))
	UListView* CharacterBindingsList;
};
