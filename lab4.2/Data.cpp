#define _CRT_SECURE_NO_WARNINGS
#include "Data.h"
#include "functions.h"
#include <iostream>
#include <fstream>

using namespace std;

void loadData(Doctor*& m, fstream& data)
{
	for (int i = 0; !data.eof(); i++)
	{
		char bufName[20], bufSurname[20], bufFather[20];
		int spec, qual;

		data >> bufSurname >> bufName >> bufFather >> spec >> qual;
		push_back(m);

		m[i].getFIO().setSurname(bufSurname);
		m[i].getFIO().setName(bufName);
		m[i].getFIO().setFather(bufFather);

		m[i].setSpecialtyId(spec);
		m[i].setQualificationId(qual);
	}
	cout << "‘айл успешно открыт!\n";
}
void createData(Doctor*& m)
{
	int n;
	Doctor* arr = m;
	do
	{
		cout << "¬ведите кол-во позиций в базе: ";
		cin >> n;

	} while (checkInput());

	for (int i = 0; i < n; i++)
	{
		cout << "\n¬вод элемента базы номер %d:\n" << i + 1;
		arr->addDoctor(m);
	}
}
void saveData(Doctor* m, fstream& data)
{
	data.seekg(ios_base::beg);

	data << m[0].getFIO().getSurname() << " "
		<< m[0].getFIO().getName() << " "
		<< m[0].getFIO().getFather() << " "
		<< m[0].getSpecialtyId() << " "
		<< m[0].getQualificationId();

	for (int i = 1; i < m->getCount(); i++)
	{
		data << endl 
			<< m[i].getFIO().getSurname() << " "
			<< m[i].getFIO().getName() << " "
			<< m[i].getFIO().getFather() << " "
			<< m[i].getSpecialtyId() << " "
			<< m[i].getQualificationId();
	}
}