#pragma once
#include "CoreMinimal.h"
#include "FlightMovementMode.generated.h"
UCLASS(Blueprintable)
class FLIGHT_API UFlightMovementMode: public UObject
{
	GENERATED_BODY()
public:
	UFlightMovementMode();
	
	UPROPERTY(BlueprintReadWrite)
	FName MovementModeName;

	virtual float GetSpeed();
	virtual FVector GetVelocity();
	virtual FVector HandleImpulse();
private:
	
	
	
};
