// monochromator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "spectro.h"
#include <iostream>
#include <stdio.h>

using namespace std;


int main()
{
	spectro mySpectro;	
	mySpectro.print_idn();
	mySpectro.monoSpace();
	// mySpectro.motorLimits();
	// mySpectro.motorInit();
	// mySpectro.motorBusy();
	return 0;
}

