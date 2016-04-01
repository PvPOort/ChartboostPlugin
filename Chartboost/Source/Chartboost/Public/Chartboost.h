// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "ModuleManager.h"


class CHARTBOOST_API FChartboostModule : public IModuleInterface
{
private:
	class UChartboostDelegateHandler *DelegateHandler;

public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	static inline FChartboostModule& Get()
	{
		return FModuleManager::LoadModuleChecked< FChartboostModule >("Chartboost");
	}

	class UChartboostDelegateHandler *GetDelegateHandlerInstance();

	virtual void ShowAd(bool bVideo = true);
};


