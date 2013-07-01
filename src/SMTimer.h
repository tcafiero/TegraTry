#ifndef _SMTIMER
	#define _SMTIMER
	/////////////////////////////////////////////////////////////////////////////////////////
	// Timer Support

	struct TimerDetails
	{
	public:
		void* m_pThisPtr;
		void* m_pCallback;
		TimerDetails(void* pThis, void* pCallback) : m_pThisPtr(pThis), m_pCallback(pCallback){}

	};
	// these definitions are used to implement timer events i.e. 'after(...)' in state diagrams
	#if (!defined(RTS_SYNC_INVOKED))

		/////////////////////////////////////////////////////////////////////////////////////////
		// Timer Support
		// these definitions are used to implement timer events i.e. 'after(...)' in state diagrams
		// RtsTimer is used as the type of an identifier/handle for a timer
		#include "CallbackTimer.h"
		typedef CallbackTimer RtsTimer;

		// the following macro is used to start a timer
		//
		// nTimerId must be implemented as a reference to an RtsTimer and returns the id of the timer started.
		// pCallback takes a pointer to a callback function which takes a void* parameter which must be
		//   the 'this' pointer of the statemachine object. The function is called when the timer expires, it
		//   then passes the call to the relevant member function using the pointer to establish the object.
		// nTime is a time value which is passed straight through from the RtS model. The units used in the
		//   model may need the value to be scaled before being used.
		#ifdef RTS_SIMULATION
			#define RtsStartTimer( nTimerId, pCallback, nTime ) \
			if(SimHandler::GetTimersPaused() == false) \
			{ \
				nTimerId.SetTimer(nTime, (CALLBACKFUNCTION)pCallback, (long)this); \
				TimerDetails *pTimerDetails = new TimerDetails(this, (void*)pCallback); \
				if(gSimHandler) gSimHandler->TrackTimer(this, &nTimerId, nTime, pTimerDetails); \
			} \
			else \
			{ \
				TimerDetails *pTimerDetails = new TimerDetails(this, (void*)pCallback); \
				if(gSimHandler) gSimHandler->TrackTimer(this, &nTimerId, nTime, pTimerDetails); \
			}
			#define RtsReStartTimer( nTimerId, nTime, pTimerDetails ) \
			{ \
				if(SimHandler::GetTimersPaused() == false) \
					((RtsTimer*)pTimerID)->SetTimer(ulTimeToFire, (CALLBACKFUNCTION)((TimerDetails*)pTimerDetails)->m_pCallback, (long)((TimerDetails*)pTimerDetails)->m_pThisPtr); \
			}
		#else
			#define RtsStartTimer( nTimerId, pCallback, nTime ) \
				nTimerId.SetTimer(nTime, (CALLBACKFUNCTION)pCallback, (long)this)
			#define RtsReStartTimer( nTimerId, nTime, pTimerDetails ) \
				nTimerId.SetTimer(nTime, (CALLBACKFUNCTION)pTimerDetails->pCallback, (long)pTimerDetails->m_pThisPtr)
		#endif
		// the following macro is used to stop a timer and takes the timers id
		//   it is called both after the timer has gone off and if it needs to be cancelled before expiring
		#ifdef RTS_SIMULATION
			#define RtsStopTimer( nTimerId ) \
				if(gSimHandler) \
				{ \
						nTimerId.StopTimer(); \
						gSimHandler->UntrackTimer(&nTimerId); \
				}
			#define RtsPauseTimer( nTimerId) \
			{ \
					((RtsTimer*)nTimerId)->StopTimer(); \
			}
		#else
			#define RtsStopTimer( nTimerId ) \
				nTimerId.StopTimer()
		#endif
	#endif
#endif
