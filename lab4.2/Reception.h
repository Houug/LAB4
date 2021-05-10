#pragma once
#include "Date.h"
#include "Common.h"
class Reception : public Common {
	Date date;
	int countPatient;
public:
	Reception();

	Date& getDate();

	void addPatient();
	void removeParient();

	int getCount();
};

