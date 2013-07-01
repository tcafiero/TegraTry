// File : .\class\B.h

#ifndef __B
#define __B

#include "A.h"
#include "C.h"
#include "I.h"

class H;


class B : public A
{


public:
  
  // Public|Package roles
  
  C rC;
  
  H * rH;
  I rI;
  
  
  // Public|Package operations
  
  int sub(
  	const int a,
  	const int b
  );

};

#endif
