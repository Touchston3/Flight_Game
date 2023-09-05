// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "FlightGameState.generated.h"

/**
 * 
 */
UCLASS()
class FLIGHT_API AFlightGameState : public AGameStateBase
{
	GENERATED_BODY()
public:
	void AddPlayerState(APlayerState* PlayerState) override;


	void RemovePlayerState(APlayerState* PlayerState) override;

};
