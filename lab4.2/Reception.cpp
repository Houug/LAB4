#include "Reception.h"

Reception::Reception()
{
	countPatient = 0;
}

Date& Reception::getDate()
{
	return date;
}

void Reception::addPatient()
{
	countPatient++;
}

void Reception::removeParient()
{
	countPatient--;
}

int Reception::getCount()
{
	return countPatient;
}
