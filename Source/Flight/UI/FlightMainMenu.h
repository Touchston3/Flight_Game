// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Flight/PlayerManagers/FlightMenuComp.h"
#include "FlightMainMenu.generated.h"

UENUM()
enum class EMenuIndex : uint8
{
	MainMenu = 0,
	ControlsMenu,
	GraphicsMenu,
};

UCLASS()
class FLIGHT_API UFlightMainMenu : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFlightMainMenu(const FObjectInitializer& Initializer);
	void Init(TWeakObjectPtr<UFlightMenuRoot> rootWidget, TWeakObjectPtr<UFlightMenuComp> parentComponent);
private:
	TWeakObjectPtr<UFlightMenuRoot>  RootWidget;
	TWeakObjectPtr<UFlightMenuComp>  ParentComponent;

	UPROPERTY(EditDefaultsOnly, meta=(BindWidget))
	UButton* ReturnButton;
	UPROPERTY(EditDefaultsOnly, meta=(BindWidget))
	UButton* ControlsSettingsButton;
	UPROPERTY(EditDefaultsOnly, meta=(BindWidget))
	UButton* GraphicsSettingsButton;

	UFUNCTION()
	void ReturnButtonClicked();
	UFUNCTION()
	void ControlsSettingsButtonClicked();
	UFUNCTION()
	void GraphicsSettingsButtonClicked();
};
