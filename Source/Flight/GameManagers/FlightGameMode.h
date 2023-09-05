// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Flight/WorldEntities/CharacterPawn.h"
#include "FlightGameMode.generated.h"

/**
 * 
 */
UCLASS()
class FLIGHT_API AFlightGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	AFlightGameMode();
	void InitGameState() override;

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<ACharacterPawn> DefaultPawnClassProperty;

};
