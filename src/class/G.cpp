// File : .\class\G.cpp

#include "G.h"





// Operation implementations

int G::mul(
	const int a,
	const int b
)
{

// ## OperationBody [5fa45db6-66fc-44c1-a871-e8c0c0050419] 
int i,p=0;
for(i=0;i<b;i++)
p += a;
return p;
// ## OperationBody End 

}

