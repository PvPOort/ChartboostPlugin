#include "ChartboostPrivatePCH.h"


UChartboostDelegateHandler::UChartboostDelegateHandler()
{

}

void UChartboostDelegateHandler::OnAdCompleted(bool bVideo, bool bWillPresentProductSheet, bool bDidDismiss)
{
#if PLATFORM_IOS
	// Report back to the game thread whether this succeeded.
	[FIOSAsyncTask CreateTaskWithBlock : ^ bool(void) 
	{
#endif
			OnChartboostAdCompleted.Broadcast(bVideo, bWillPresentProductSheet, bDidDismiss);
#if PLATFORM_IOS
		return true;
	}];
#endif
}


