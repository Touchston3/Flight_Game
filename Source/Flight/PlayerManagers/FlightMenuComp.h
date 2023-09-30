// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FlightInputComp.h"
#include "FlightPlayerController.h"
#include "Flight/UI/FlightMenuRoot.h"
#include "FlightMenuComp.generated.h"


class AFlightPlayerController;
//class UFlightMenuRoot;

UCLASS(Blueprintable)
class FLIGHT_API UFlightMenuComp : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFlightMenuComp();

	FORCEINLINE AFlightPlayerController* GetParentController() const { return Cast<AFlightPlayerController>(UActorComponent::GetOwner()); } 
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UFlightMenuRoot> MainMenuRootClass;
	TStrongObjectPtr<UFlightMenuRoot> MainMenuRoot;
};
