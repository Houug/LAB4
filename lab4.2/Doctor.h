//ÑÒ ÏÐÂÒ
#pragma once
#include "Fio.h"
#include <stdio.h>
#include <iostream>
#include "Common.h"
#include <fstream>
using namespace std;
class Doctor : public Common {
	int specialty;
	int qualification;
public:
	static int count;

	friend Doctor findDoctor(Doctor* m);
	friend void filterDoctor(Doctor* oldArr, Doctor*& newArr, int& count);
	friend istream& operator>> (istream& in, Doctor& obj);

	Doctor();
	Doctor(char* surname, char* name, char* father, int spec, int qual);
	Doctor(Doctor& obj);
	~Doctor();
	
	int getSpecialtyId();
	int getQualificationId();
	int getCount();

	void setSpecialtyId(int spec);
	void setQualificationId(int qual);

	void inputSpecialtyId();
	void inputQualificationId();

	void addDoctor(Doctor*& m);
	void standartObjectEvent(Doctor*& m);
	void printDoctor(int n);
	void printAllDoctors();

	bool operator== (Fio& obj);
	bool operator> (Doctor& obj);
	bool operator< (Doctor& obj);
	Doctor operator=(Doctor& obj);
};