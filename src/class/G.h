// File : .\class\G.h

#ifndef __G
#define __G

#include "A.h"

class G : public A
{


public:
  
  // Public|Package operations
  
  int mul(
  	const int a,
  	const int b
  );

private:
  
  // Private roles
  
  A rA;


};

#endif
