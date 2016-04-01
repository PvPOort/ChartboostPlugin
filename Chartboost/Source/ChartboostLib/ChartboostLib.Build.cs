// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ChartboostLib : ModuleRules
{
    public ChartboostLib(TargetInfo Target)
    {
        Type = ModuleType.External;

        if (Target.Platform == UnrealTargetPlatform.IOS)
        {
			PublicAdditionalFrameworks.Add(
				new UEBuildFramework(
					"Chartboost",
					"IOS/ChartboostLib/Chartboost.embeddedframework.zip"
                )
            );

            PublicFrameworks.AddRange(new string[]
            {
                "AdSupport",
                "CoreGraphics",
                "StoreKit",
                "Chartboost",
                "Foundation",
                "CFNetwork",
                "Security",
                "Foundation",
            });
        }
    }
}
