#include <chrono>
#include <thread>
#include <stdio.h>
#include <Encoder.h>


HANDLE ev;

void t()
{
	
	printf("%lli\n", std::chrono::high_resolution_clock::now().time_since_epoch().count() / 1000000);
	SetEvent(ev);
}

int main()
{
	MMRESULT c;
	
	ev = CreateEvent(0, TRUE, FALSE, (LPCWSTR)"EVION");
	while(1)
	{
		ResetEvent(ev);
		c = timeSetEvent(20, 0, (LPTIMECALLBACK)t, 0, TIME_ONESHOT);
		WaitForSingleObject(ev, INFINITE);
		
		timeKillEvent(c);
		
	}
	
	

	
	return 0;
}