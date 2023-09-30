// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FlightPlayerController.generated.h"


class UFlightMenuComp;
class UFlightInputComp;

UCLASS(Blueprintable)
class FLIGHT_API AFlightPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AFlightPlayerController();
	virtual void SetupInputComponent() override;


	UPROPERTY(EditDefaultsOnly)
	UFlightMenuComp* MainMenuComponent;
	UPROPERTY(EditDefaultsOnly)
	UFlightInputComp* PlayerInputComponent;

protected:
	//IDK I might need these
	void OnPossess(APawn* aPawn) override;
	void OnUnPossess() override;



private:
};
