#ifndef _TESTRESULT_H
#define _TESTRESULT_H

#include"Field.h"

class TestResult
{
public:
	TestResult();
	~TestResult();
	void successTest();
	void failedTest();
};

#endif