#pragma once
class Date {
	int day;
	int month;
	int year;
public:
	Date();
	int getDay();
	int getMonth();
	int getYear();

	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
};

