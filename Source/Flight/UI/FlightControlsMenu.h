// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedActionKeyMapping.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Components/InputKeySelector.h"
#include "FlightControlsMenu.generated.h"

class UFlightMenuRoot;
class UListView;
class UFlightMenuComp;
class UTextBlock;
class UButton;
class AFlightPlayerController;
class UInputMappingContext;
class UInputAction;

UCLASS(NotBlueprintable)
class FLIGHT_API UFlightControlsMenuListObject : public UObject
{
	GENERATED_BODY()

public:
	UFlightControlsMenuListObject();
	FEnhancedActionKeyMapping InputCombination;
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
	
	TWeakObjectPtr<AFlightPlayerController> GetPlayerController() const;
	FEnhancedActionKeyMapping KeyMapping;
	
	UPROPERTY(EditDefaultsOnly, meta=(BindWidget))
	UTextBlock* ActionText;
	UPROPERTY(EditDefaultsOnly, meta=(BindWidget))
	UButton* ResetButton;
	UPROPERTY(EditDefaultsOnly, meta=(BindWidget))
	UInputKeySelector* InputKeySelector;
	


	UFUNCTION()
	void HandleResetButtonClicked();
	UFUNCTION()
	void HandleKeySelected(FInputChord InputChord);
};

UCLASS(Blueprintable)
class FLIGHT_API UFlightControlsMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	UFlightControlsMenu(const FObjectInitializer& Initializer);
	void Init(TWeakObjectPtr<UFlightMenuRoot> rootWidget);
private:
	TWeakObjectPtr<UFlightMenuRoot> RootWidget;
	TWeakObjectPtr<AFlightPlayerController> GetPlayerController() const;
	
	UPROPERTY(EditDefaultsOnly, meta=(BindWidget))
	UListView* CharacterBindingsList;
};
