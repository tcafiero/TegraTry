/////////////////////////////////////////////////////////////////////////////////////////
// This header is a template for implementation of Rts identifiers for target builds
//
// Each definition should be customised to the target environment
#if (!defined(RTS_SYNC_INVOKED))

#ifndef _INC_RTSSMTGT_H
#define _INC_RTSSMTGT_H

#include "CallbackTimer.h"
#include "SMTimer.h"
#define CALLBACK

// the following constant is used to prevent the RunToCompletion function cycling forever
#define MAX_LOOP 1000


/////////////////////////////////////////////////////////////////////////////////////////
// Thread Synchronization Support
#include <semaphore.h>

// these definitions are used to implement a semaphore which protects the statemachine from
// access by more than one thread at a time

// RtsSemaphore is used as the type of an identifier for a semaphore
typedef sem_t* RtsSemaphore;

// the following macro is used to create a semaphore and return its id in the hSemparameter
#define RtsCreateSemaphore( hSem ) hSem = new sem_t(); \
sem_init(hSem,0,1)
#define RtsDeleteSemaphore( hSem ) sem_destroy((sem_t*)hSem)
#define RtsCreateBinarySemaphore( hSem, iTaken ) 	hSem = new sem_t(); \
sem_init(hSem,0, iTaken ? 0 : 1)
//#define RtsWaitForBinarySemaphore( hSem, timeout, result ) sem_trywait(hSem, timeout)
#define RtsReleaseBinarySemaphore( hSem ) sem_post((sem_t*)hSem)

// the following macro is used to wait for and lock a the specified semaphore
#define RtsLock( hSem ) sem_wait((sem_t*)hSem)
// the following macro is used to unlock the specified semaphore
#define RtsUnlock( hSem ) sem_post((sem_t*)hSem)

#define RtsIsLocked( hMutex ) 0

#endif
#endif


