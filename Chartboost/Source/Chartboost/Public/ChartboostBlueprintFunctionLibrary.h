#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "ChartboostBlueprintFunctionLibrary.generated.h"


UCLASS()
class CHARTBOOST_API UChartboostBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Chartboost Ad Service")
	static class UChartboostDelegateHandler *GetChartboostDelegateHandlerInstance();

	UFUNCTION(BlueprintCallable, Category = "Chartboost Ad Service")
	static void ShowAd(bool bVideo = true);
};


