// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedPlayerInput.h"
#include "EnhancedInputComponent.h"
#include "Components/ActorComponent.h"
#include "Flight/PlayerManagers/FlightInputComp.h"
#include "FlightCharacterPawn.h"
#include "FlightCharacterInput.generated.h"

UCLASS(Blueprintable)
class FLIGHT_API UFlightCharacterInput : public UEnhancedInputComponent 
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFlightCharacterInput();

	void SetupOnControlled(TWeakObjectPtr<AFlightPlayerController> PlayerController);

	void UpdateCharacterPosition(float DeltaTime); 
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	TWeakObjectPtr<AFlightCharacterPawn> GetCharacter() const { return Cast<AFlightCharacterPawn>(UEnhancedInputComponent::GetOwner()); }
protected:
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputMappingContext* CharacterMappingContext;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* MoveInputAction;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* LookInputAction;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* InteractInputAction;

	UPROPERTY(EditDefaultsOnly)
	FVector LocalAcceleration;
	UPROPERTY(EditDefaultsOnly)
	FVector LocalVelocity;
	UPROPERTY(EditDefaultsOnly)
	float MaxSpeed;
private:
	UFUNCTION()
	void HandleMove(const FInputActionValue& InputActionValue);
	UFUNCTION()
	void HandleLook(const FInputActionValue& InputActionValue);
	UFUNCTION()
	void HandleInteract(const FInputActionValue& InputActionValue);
		
};
