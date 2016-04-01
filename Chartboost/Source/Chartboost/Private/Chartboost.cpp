// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "ChartboostPrivatePCH.h"

#define LOCTEXT_NAMESPACE "FChartboostModule"

void FChartboostModule::StartupModule()
{
	DelegateHandler = NewObject<UChartboostDelegateHandler>();
}

void FChartboostModule::ShutdownModule()
{

}

UChartboostDelegateHandler *FChartboostModule::GetDelegateHandlerInstance()
{
	return DelegateHandler;
}

void FChartboostModule::ShowAd(bool bVideo /*= true*/)
{
	if (bVideo)
	{
		PlatformChartboostHelper::ShowAdVideo();
	}
	else
	{
		PlatformChartboostHelper::ShowAdInterstitial();
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FChartboostModule, Chartboost)