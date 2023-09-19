// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FlightCharacterPawnMovement.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FLIGHT_API UFlightCharacterPawnMovement : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFlightCharacterPawnMovement();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void HandleForward(FKey Key);
	UFUNCTION()
	void HandleBackward(FKey Key);
	UFUNCTION()
	void HandleLeft(FKey Key);
	UFUNCTION()
	void HandleRight(FKey Key);
	UFUNCTION()
	void HandleInteract(FKey Key);
	
	// Called every frame

		
};
