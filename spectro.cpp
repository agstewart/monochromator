#include "StdAfx.h"
#include "spectro.h"
#include "ni4882.h"
#include "visa.h"
#include "string.h"
#include <iostream>
#include <stdlib.h>

using std::cout;
using std::endl;
using std::ofstream;

spectro::spectro(void) // constructor
{
	SendIFC(0); // clear the bus 
	if (ibsta & ERR)
	{
		std::cout << "Could not send IFC" << std::endl;
	}
	m_device = ibdev(0,1,0,T1s,1,0);
	cout << "Device ID: " << m_device << endl;
	if (m_device == -1)
	{
		std::cout << "Error connecting to monochromator" << std::endl;
	}

	char command[] = "*RST\r\n";
	ibwrt(m_device, command, strlen(command));
	char response[100];
	ibrd(m_device, response, 100);
	response[ibcnt] = '\0';
	cout << response << endl;

}

spectro::~spectro(void) // destructor
{
}

void spectro::print_idn()
{
	char command[] = "*IDN?\r\n";  
	ibwrt(m_device, command, strlen(command));
	char response[100];
	ibrd(m_device,response,100);
	response[ibcnt] = '\0';
	cout << response << endl;
}

bool spectro::motorBusy()
{
	char command[] = "E\r\n";
	ibwrt(m_device, command, strlen(command));
	char response[100];
	ibrd(m_device, response, 100);
	response[ibcnt] = '\0';
	cout << "Motor Response:" << response << endl;
	// printf("%s\n", response);
	return 1;
}

void spectro::motorInit()
{
	char command[] = "A\r\n";
	ibwrt(m_device, command, strlen(command));
	char response[100];
	ibrd(m_device, response, 100);
	response[ibcnt] = '\0';
	cout << "Initialise response: " << response << endl;
}

void spectro::monoSpace()
{
	char command[] =  " \n";
	ibwrt(m_device, command, strlen(command));
	char response[100];
	ibrd(m_device, response, 100);
	response[ibcnt] = '\0';
	printf("Response 1: %s\n", response);
	
	char command2[] = "O2000\00";
	ibwrt(m_device, command2, strlen(command2));
	
	char response2[100];
	ibrd(m_device, response2, 100);
	// cout << ibcnt << endl;
	response2[ibcnt] = '\0';
	cout << "CNT : " << ibcnt << endl;
	cout << "Response 2 : " << response2 << endl;
	

	ibwrt(m_device, command, strlen(command));
	char response3[100];
	ibrd(m_device, response3, 100);
	response3[ibcnt] = '\0';
	cout << "ibcnt = " << ibcnt << endl;
	cout << "Response 3 : " << response3 << endl; 
	/*
	if (strcmp(response, "B\r\0") == 1)
	{
		cout << "response == B" << endl;
	}
	*/
}

void spectro::motorLimits()
{
	char command[] = "K\r\n";
	ibwrt(m_device, command, strlen(command));
	char response[100];
	ibrd(m_device, response, 100);
	printf("%s", response);
}