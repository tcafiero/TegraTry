// File : .\class\I.h

#ifndef __I
#define __I

#include "RtsSM.h"
#include <iostream>
using namespace std;


class I
{


public:
  // \ART_SMG :: Created for state : I
  enum RtsI_States
  {
  	RtsI_States_State1,
  	RtsI_States_State2,
  	RtsI_States_State3,
  	RtsI_States_NotIn_I
  	
  };
  
  // Public|Package operations
  
  void event1(
  	const int code
  );
  
  void event2(
  	const int code
  );
  
  // \ART_SMG :: Constructor
  I();
  
  // \ART_SMG :: Destructor
  ~I();

private:
  
  // Private attributes
  
  // \ART_SMG :: Created for state : I
  RtsI_States RtsCurrent_I;
  
  // \ART_SMG :: Always Created
  RtsSemaphore RtsBusy;
  
  
  // Private operations
  
  bool RtsRunToCompletion();
  
  // \ART_SMG :: Created for state : State1
  void RtsEnter_State1();
  
  // \ART_SMG :: Created for state : State2
  void RtsEnter_State2();
  
  // \ART_SMG :: Created for state : State3
  void RtsEnter_State3();
  
  // \ART_SMG :: Created for state : State1
  void RtsExit_State1();
  
  // \ART_SMG :: Created for state : State2
  void RtsExit_State2();
  
  // \ART_SMG :: Created for state : State3
  void RtsExit_State3();
  
  bool event1_In_I(
  	const int code
  );
  
  bool event2_In_I(
  	const int code
  );

};

#endif
