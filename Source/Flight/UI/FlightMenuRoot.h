// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/WidgetSwitcher.h"
#include "FlightMenuRoot.generated.h"

class UFlightMainMenu;
class UFlightControlsMenu;
class UFlightMenuComp;

UCLASS(Blueprintable)
class FLIGHT_API UFlightMenuRoot : public UUserWidget
{
	GENERATED_BODY()

public:
	UFlightMenuRoot(const FObjectInitializer& Initializer);
	void Init(TWeakObjectPtr<UFlightMenuComp> MenuComponent);
	FORCEINLINE UWidgetSwitcher* GetPageSwitcher() const { return PageSwitcher;}
private:
	UPROPERTY(EditDefaultsOnly, meta=(BindWidget))
	UWidgetSwitcher* PageSwitcher;

	UPROPERTY(EditDefaultsOnly, meta=(BindWidget))
	UFlightMainMenu* MainMenu;
	
	UPROPERTY(EditDefaultsOnly, meta=(BindWidget))
	UFlightControlsMenu* ControlsMenu;
};
