// File : .\class\I.cpp

#include <iostream>
using namespace std;
#include "I.h"




// Operation implementations

void I::event1(
	const int code
)
{

// ## OperationBody [8714e3a0-0da8-4ae0-a196-e19e1c675fa7] 
/* START_SMG_BODY */
RtsLock(RtsBusy);
event1_In_I(code);
while(RtsRunToCompletion());
RtsUnlock(RtsBusy);
/* END_SMG_BODY */
// ## OperationBody End 

}

void I::event2(
	const int code
)
{

// ## OperationBody [618ca3be-0708-4e59-b27d-aab8f6a32d1a] 
/* START_SMG_BODY */
RtsLock(RtsBusy);
event2_In_I(code);
if (RtsCurrent_I != RtsI_States_NotIn_I)
{
	while(RtsRunToCompletion());
}
RtsUnlock(RtsBusy);
/* END_SMG_BODY */
// ## OperationBody End 

}

bool I::RtsRunToCompletion()
{


if (RtsCurrent_I == RtsI_States_NotIn_I)
{
	RtsEnter_State1();
	return true;
}
return false;
}

I::I()
{

RtsCreateSemaphore(RtsBusy);
RtsLock(RtsBusy);

/* Initializing State Vectors to NotIn */
RtsCurrent_I=RtsI_States_NotIn_I;

while(RtsRunToCompletion());
RtsUnlock(RtsBusy);
}

I::~I()
{

RtsDeleteSemaphore(RtsBusy);

}

void I::RtsEnter_State1()
{

RtsCurrent_I = RtsI_States_State1;

}

void I::RtsEnter_State2()
{

RtsCurrent_I = RtsI_States_State2;

}

void I::RtsEnter_State3()
{

RtsCurrent_I = RtsI_States_State3;

}

void I::RtsExit_State1()
{


}

void I::RtsExit_State2()
{


}

void I::RtsExit_State3()
{


}

bool I::event1_In_I(
	const int code
)
{

if (RtsCurrent_I == RtsI_States_State1)
{
	if (
// ## Guard [8015c375-e0a9-4ec2-90ae-fae9a63acfe0] 
code == 0
// ## Guard End 
)
	{
		RtsExit_State1();
		
// ## Action [5b6277fb-e06c-4175-b718-39e4dfe30434] 
cout << "event 0" << endl;
// ## Action End 

		RtsEnter_State2();
		
		return true;
	}
}
if (RtsCurrent_I == RtsI_States_State2)
{
	if (
// ## Guard [3a5e393e-622b-4511-a0c3-e085e464b3ae] 
code == 1
// ## Guard End 
)
	{
		RtsExit_State2();
		
// ## Action [4dc6677f-5e8e-4f24-a18a-382d433e0832] 
cout << "event 1" <<  endl;
// ## Action End 

		RtsEnter_State3();
		
		return true;
	}
}
return false;
}

bool I::event2_In_I(
	const int code
)
{

if (RtsCurrent_I == RtsI_States_State3)
{
	RtsExit_State3();
	
// ## Action [13779bfb-c7f1-448d-9920-3544decaa59e] 
cout << "event2" << endl;
// ## Action End 

	RtsCurrent_I = RtsI_States_NotIn_I;
	
	return true;
}
return false;
}

