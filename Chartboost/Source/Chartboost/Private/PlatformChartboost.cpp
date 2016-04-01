#include "ChartboostPrivatePCH.h"

#if PLATFORM_IOS

@interface ChartboostEventHandler : NSObject
{

}

+(id)StaticInit;
@end

@implementation ChartboostEventHandler

+ (id)StaticInit
{
	ChartboostEventHandler *instance = [[ChartboostEventHandler alloc] init];

	if (instance)
	{
		[[NSNotificationCenter defaultCenter] addObserver:instance
			selector : @selector(didFinishLaunchWithOptions : )
					   name:UIApplicationDidBecomeActiveNotification object : nil];
	}

	return instance;
}

-(void)didFinishLaunchWithOptions:(UIApplication *)application
{
	PlatformChartboostHelper::Init();
}

@end

static ChartboostEventHandler *EventHandlerStaticInitializer = [ChartboostEventHandler StaticInit];


@implementation IOSChartboost

+ (id)InitWithID:(NSString*)appID withSignature : (NSString*)signature
{
	IOSChartboost *instance = [[IOSChartboost alloc] init];

	if (![Chartboost class])
		return nil;

	if (instance)
	{
		[Chartboost startWithAppId : appID
			appSignature : signature
			delegate : instance];
	}

	return instance;
}

-(void)ShowAdInterstitial
{
	[Chartboost showInterstitial : CBLocationHomeScreen];
}

-(void)ShowAdVideo
{
	[Chartboost showRewardedVideo : CBLocationMainMenu];
}

// Вызывается после того, как вставка была прекращена.
-(void)didDismissInterstitial:(CBLocation)location
{
	FChartboostModule *chartboostModule = &FChartboostModule::Get();
	if (chartboostModule)
	{
		chartboostModule->GetDelegateHandlerInstance()->OnAdCompleted(false, false, true);
	}
}

// Вызывается после того, как вставка была закрыта.
-(void)didCloseInterstitial:(CBLocation)location
{
	FChartboostModule *chartboostModule = &FChartboostModule::Get();
	if (chartboostModule)
	{
		chartboostModule->GetDelegateHandlerInstance()->OnAdCompleted(false, false, false);
	}
}

// Вызывается после того, как вставка была нажата.
-(void)didClickInterstitial:(CBLocation)location
{
	FChartboostModule *chartboostModule = &FChartboostModule::Get();
	if (chartboostModule)
	{
		chartboostModule->GetDelegateHandlerInstance()->OnAdCompleted(false, true, false);
	}
}

// Вызывается после того, как вознаграждаемое видео было прекращено.
-(void)didDismissRewardedVideo:(CBLocation)location
{
	FChartboostModule *chartboostModule = &FChartboostModule::Get();
	if (chartboostModule)
	{
		chartboostModule->GetDelegateHandlerInstance()->OnAdCompleted(true, false, true);
	}
}

// Вызывается после того, как вознаграждаемое видео было закрыто.
-(void)didCloseRewardedVideo:(CBLocation)location
{
	FChartboostModule *chartboostModule = &FChartboostModule::Get();
	if (chartboostModule)
	{
		chartboostModule->GetDelegateHandlerInstance()->OnAdCompleted(true, false, false);
	}
}

// Вызывается после того, как вознаграждаемое видео было нажато.
-(void)didClickRewardedVideo:(CBLocation)location
{
	FChartboostModule *chartboostModule = &FChartboostModule::Get();
	if (chartboostModule)
	{
		chartboostModule->GetDelegateHandlerInstance()->OnAdCompleted(true, true, false);
	}
}

@end

static IOSChartboost *ChartboostInstance;
#endif // PLATFORM_IOS


void PlatformChartboostHelper::Init()
{
#if PLATFORM_IOS
	NSString *appID = [[NSBundle mainBundle] objectForInfoDictionaryKey:@"ChartboostApiKey"];
	NSString *signature = [[NSBundle mainBundle] objectForInfoDictionaryKey:@"ChartboostSignature"];

	ChartboostInstance = [IOSChartboost InitWithID : appID
		withSignature : signature];
#endif // PLATFORM_IOS
}

void PlatformChartboostHelper::ShowAdInterstitial()
{
#if PLATFORM_IOS
	dispatch_async(dispatch_get_main_queue(), ^
	{
		if (ChartboostInstance)
		{
			[ChartboostInstance ShowAdInterstitial];
		}
	});
#endif // PLATFORM_IOS
}

void PlatformChartboostHelper::ShowAdVideo()
{
#if PLATFORM_IOS
	dispatch_async(dispatch_get_main_queue(), ^
	{
		if (ChartboostInstance)
		{
			[ChartboostInstance ShowAdVideo];
		}
	});
#endif // PLATFORM_IOS
}


