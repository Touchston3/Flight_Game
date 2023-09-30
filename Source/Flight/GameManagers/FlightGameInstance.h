// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "FlightGameInstance.generated.h"

class AFlightWorldSettings;

UCLASS(Blueprintable)
class FLIGHT_API UFlightGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UFlightGameInstance();
	//Register Online delegates. Add handlers to various input and network delegates
	//According to UGameInstace comments: virtual function to allow custom GameInstances an opportunity to set up what it needs 
	void Init() override; 


	void Shutdown() override;



	void StartGameInstance() override; //Loads default level. broadcasts delegates and eventually OnStart(). Also, what is an FURL


	void ReturnToMainMenu() override; //Literally just disconnects from world

protected:
	void OnStart() override; //Called after the OnStartGameInstance delegate is broadcasted
	
	UPROPERTY(EditDefaultsOnly)
	AFlightWorldSettings* WorldSettings;
private:

	UPROPERTY(VisibleDefaultsOnly)
	UWorld* DefaultWorld;
};
