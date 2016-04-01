#include "ChartboostPrivatePCH.h"

DEFINE_LOG_CATEGORY_STATIC(LogChartboostAnalytics, Log, All);


UChartboostDelegateHandler *UChartboostBlueprintFunctionLibrary::GetChartboostDelegateHandlerInstance()
{
	FChartboostModule *moduleInstance = &FChartboostModule::Get();
	if (moduleInstance)
	{
		return moduleInstance->GetDelegateHandlerInstance();
	}
	else
	{
		UE_LOG(LogChartboostAnalytics, Warning, TEXT("UChartboostBlueprintFunctionLibrary::GetChartboostDelegateListenerInstance: Chartboost module is NULL"));
	}

	return nullptr;
}

void UChartboostBlueprintFunctionLibrary::ShowAd(bool bVideo /*= true*/)
{
	FChartboostModule *moduleInstance = &FChartboostModule::Get();
	if (moduleInstance)
	{
		moduleInstance->ShowAd(bVideo);
	}
	else
	{
		UE_LOG(LogChartboostAnalytics, Warning, TEXT("UChartboostBlueprintFunctionLibrary::ShowAd: Chartboost module is NULL"));
	}
}


