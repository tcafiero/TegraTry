#ifndef __CallbackTimer
#define __CallbackTimer

#include <time.h>
#include <signal.h>

typedef void (*CALLBACKFUNCTION) (union sigval value);
	
class CallbackTimer
{
public:

	// public operations
	CallbackTimer();
	virtual ~CallbackTimer();

	void SetTimer(unsigned int value, CALLBACKFUNCTION callback, long address);
	void StopTimer();
private:

	// private attributes
	sigevent m_sigEvent;
	sigval_t m_sv;
	timer_t myTimer;
	struct itimerspec myTimerSpec;
};

#endif
