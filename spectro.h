

#pragma once

class spectro
{
public:
	spectro(void); // constructor
	~spectro(void); // destructor

	void print_idn();
	bool motorBusy();
	void motorInit();
	void monoSpace();
	void motorLimits();

	int m_device; // device id from ibdev
};
