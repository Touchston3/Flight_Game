// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FlightInputComp.h"
#include "FlightPlayerController.generated.h"


class UFlightMenuComp;

UCLASS(Blueprintable)
class FLIGHT_API AFlightPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AFlightPlayerController();
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

	UPROPERTY(EditDefaultsOnly)
	UFlightInputComp* UserInputComponent;

	UPROPERTY(EditDefaultsOnly)
	UFlightMenuComp* MainMenuComponent;
protected:
	//IDK I might need these
	void OnPossess(APawn* aPawn) override;
	void OnUnPossess() override;
	void AttachToPawn(APawn* InPawn) override;
	void DetachFromPawn() override;



private:
};
