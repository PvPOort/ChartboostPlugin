#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "ChartboostDelegateHandler.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnChartboostAdCompleted, bool, bVideo, bool, bWillPresentProductSheet, bool, bDidDismiss);

UCLASS()
class CHARTBOOST_API UChartboostDelegateHandler : public UObject
{
	GENERATED_BODY()

public:
	UChartboostDelegateHandler();

	UPROPERTY(BlueprintAssignable, Category = "Chartboost Ad Service")
	FOnChartboostAdCompleted OnChartboostAdCompleted;

	virtual void OnAdCompleted(bool bVideo, bool bWillPresentProductSheet, bool bDidDismiss);
};


