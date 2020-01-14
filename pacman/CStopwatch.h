#pragma once
#include "Windows.h"
class CStopwatch
{
public:
	CStopwatch();
	virtual ~CStopwatch();

	void Start();
	int Now();
	int Time();
private:
	LARGE_INTEGER m_liPerfFreq;
	LARGE_INTEGER m_liPerfStart;
};

