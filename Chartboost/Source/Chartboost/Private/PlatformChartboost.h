#ifndef PlatformChartboost_h
#define PlatformChartboost_h

#include "ChartboostPrivatePCH.h"

#if PLATFORM_IOS
#import <Foundation/Foundation.h>
#import <Chartboost/Chartboost.h>
#import <CommonCrypto/CommonDigest.h>
#import <AdSupport/AdSupport.h>


@interface IOSChartboost : NSObject <ChartboostDelegate>

+(id)InitWithID : (NSString*)appID withSignature : (NSString*)signature;
-(void)ShowAdInterstitial;
-(void)ShowAdVideo;

@end
#endif // PLATFORM_IOS

class PlatformChartboostHelper
{
protected:

	PlatformChartboostHelper() {};
public:
	virtual ~PlatformChartboostHelper() {};

	static void Init();
	static void ShowAdInterstitial();
	static void ShowAdVideo();
};

#endif /* PlatformChartboost_h */
