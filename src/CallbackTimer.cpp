#include "CallbackTimer.h"

// Operation implementations

CallbackTimer::CallbackTimer()
{
	struct timespec tp_settime;
	/* Set clock resolution */
	tp_settime.tv_sec = 0;
	tp_settime.tv_nsec = 1;
	clock_settime(CLOCK_REALTIME, &tp_settime) ;
}
void CallbackTimer::SetTimer(unsigned int value, CALLBACKFUNCTION callback, long address)
{
	/* Calculate timer interval from value(milliseconds)*/
	long nSeconds = value/1000;
	long nNanoSeconds = (value % 1000)*1000000;

	myTimerSpec.it_interval.tv_sec = nSeconds;
	myTimerSpec.it_interval.tv_nsec = nNanoSeconds;
	myTimerSpec.it_value.tv_sec = nSeconds;
	myTimerSpec.it_value.tv_nsec = nNanoSeconds;
	
	//Create a signal
	m_sigEvent.sigev_notify = SIGEV_THREAD;
	m_sigEvent.sigev_signo = SIGRTMIN;
	m_sigEvent.sigev_value.sival_ptr = (void*)(address);
	m_sigEvent.sigev_notify_function = callback;
	
	//Create a timer. Note that we have used the default signal
	timer_create (CLOCK_REALTIME, &m_sigEvent, &myTimer);
	//Start the timer with appropriate time for timeout
	timer_settime(myTimer, CLOCK_REALTIME, &myTimerSpec, NULL);
}

void CallbackTimer::StopTimer()
{
	timer_delete (myTimer);
}

CallbackTimer::~CallbackTimer()
{
}
