//============================================================================
// Name        : TegraTry.cpp
// Author      : Toni Cafiero
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include "./class/H.h"
#include "./class/B.h"
#include "./class/F.h"
using namespace std;

int i2c_main(void);

int main() {
	H Hinstance;
	B calculator;
	calculator.rH=&Hinstance;
	F op1;
	I Machine;
	cout << "6+2=" << calculator.sum(6,2) << endl;
	cout << "6-2=" << calculator.sub(6,2) << endl;
	cout << "6/2=" << calculator.rC.div(6,2 ) << endl;
	cout << "6*2=" << calculator.rC.mul(6,2 )<< endl;
	cout << "Compare(5,5)=" << op1.Compare(5,5) << endl;
	cout << "square(4)=" << calculator.rH->square(4) << endl;
	calculator.rI.event1(0);
	calculator.rI.event1(1);
	calculator.rI.event2(0);
	i2c_main();
	return 0;
}
