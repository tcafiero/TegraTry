// File : .\class\C.h

#ifndef __C
#define __C

#include "D.h"
#include "G.h"

class C : public D
{


public:
  
  // Public|Package operations
  
  int mul(
  	const int a,
  	const int b
  );

private:
  
  // Private roles
  
  G rG;


};

#endif
