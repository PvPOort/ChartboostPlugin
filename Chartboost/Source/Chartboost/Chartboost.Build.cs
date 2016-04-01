// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Chartboost : ModuleRules
{
	public Chartboost(TargetInfo Target)
	{
		
		PublicIncludePaths.AddRange(
			new string[] {
				"Chartboost/Public"
			});
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				"Chartboost/Private",
			});
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
            });
			
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
                "Core",
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
            });

        PrivateIncludePathModuleNames.AddRange(
                new string[] {
                    "Settings",
                });

        DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
			});

        if (Target.Platform == UnrealTargetPlatform.IOS)
        {
            PublicFrameworks.AddRange(new string[]
            {
                "Foundation",
                "UIKit",
                "CoreFoundation",
                "AdSupport",
                "CoreGraphics",
                "StoreKit",
                "Chartboost",
                "Foundation",
            });

            AddThirdPartyPrivateStaticDependencies(Target, "ChartboostLib");
        }
    }
}
