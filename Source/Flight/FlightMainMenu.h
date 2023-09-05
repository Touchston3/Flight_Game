// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FlightMainMenu.generated.h"

/**
 * 
 */
UCLASS()
class FLIGHT_API UFlightMainMenu : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void SetVisibility(ESlateVisibility InVisibility) override;

};
