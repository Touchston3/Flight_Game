#pragma once

#include "CoreMinimal.h"
#include "FlightInputActionEvent.generated.h"

UINTERFACE(MinimalAPI)
class UFlightInputActionEvent : public UInterface
{
	GENERATED_BODY()	
};

class IFlightInputActionEvent
{
	GENERATED_BODY()
public:
//	DECLARE_EVENT_OneParam(IFlightInputActionEvent, FFlightInputActionEvent, FKey);
//	virtual void OnInputAction(FKey) = 0;
	
};