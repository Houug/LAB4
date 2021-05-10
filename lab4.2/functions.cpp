#define _CRT_SECURE_NO_WARNINGS

#include "functions.h"
#include <cstring>
#include <iostream>
#include <iomanip>
#include "Doctor.h"
using namespace std;

int checkInput(int n, int mode)
{
	if (checkInput()) {
		if (mode == 0)
		{
			switch (n)
			{
			case 1:
				return 0;
			case 2:
				return 0;
			case 3:
				return 0;
			default:
				return 1;
			}
		}
		if (mode == 1)
		{
			switch (n)
			{
			case 0:
				return 0;
			case 1:
				return 0;
			case 2:
				return 0;
			default:
				return 1;
			}
		}
	}
}
void printHeader()
{
	cout << "\n========================================================================\n"
		 << setw(40) << "Ф.И.О Врача" << setw(16) << "Cпециальность" << setw(16) << "Квалификация"
		 << "\n========================================================================\n";
}
void printMenu()
{
	cout << "\n\n***************Меню**************\n"
		 << "1 - Добавить врача в базу\n2 - Поиск врача по Ф.И.О\n3 - Поиск врачей по специальности и квалификации\n"
		 << "4 - Сортировка базы по алфавиту\n5 - Вывод базы с врачами\n6 - Эталонный объект\n7 - Выход из программы"
		 << "\n*********************************\n";
}
bool checkInput()
{
	if (!cin)
	{
		cerr << endl << "Ошибка ввода!" << endl;
		cin.clear();
		cin.ignore(4096, '\n');
		return true;
	}
	return false;
}
Doctor findDoctor(Doctor* m)
{
	char bufSurname[20], bufName[20], bufFather[20];
	int count = 0;

	cout << "Поиск врача по Ф.И.О\n";
	cout << "Введите фамилию: ";
	cin.getline(bufSurname, 20);
	cout << "Введите имя: ";
	cin.getline(bufName, 20);
	cout << "Введите отчество: ";
	cin.getline(bufFather, 20);

	Doctor foundDoctor(bufSurname, bufName, bufFather, -1, -1);

	for (int i = 0; i < m->getCount() - 1; i++)
	{
		Fio fD = foundDoctor.getFIO();
		if (m[i] == fD)
		{
			count++;
			foundDoctor = m[i];
			break;
		}
	}
	if (count == 0) cout <<  "Поиск не выдал результов\n";
	else
	{
		printHeader();
		foundDoctor.printDoctor(0);
		return foundDoctor;
	}
}
void sortData(Doctor* m)
{
	int min;
	int size = m->getCount();
	Doctor temp;

	for (int i = 0; i < size; i++)
	{
		min = i;

		for (int j = i + 1; j < size; j++)
		{
			if (m[min] > m[j])
			{
				min = j;
			}
		}

		temp = m[i];
		m[i] = m[min];
		m[min] = temp;
	}
}
void push_back(Doctor*& m)
{
	int size = m->count;
	Doctor* temp = new Doctor[size + 1];
	for (int i = 0; i < size; i++)
	{
		temp[i] = m[i];
	}

	delete[] m;
	m = temp;
}
void filterDoctor(Doctor* oldArr, Doctor*& newArr, int& count)
{
	int spec = 0, qual = 0;

	do
	{
		cout << "Введите специальность (1-3): ";
		cin >> spec;
	} while (checkInput(spec, 0));

	do
	{
		cout << "Введите квалификация (0-2): ";
		cin >> qual;
	} while (checkInput(qual, 1));

	for (int i = 0; i < oldArr->getCount(); i++)
	{
		if ((spec == oldArr[i].specialty) && (qual == oldArr[i].qualification))
		{
			Doctor* temp = new Doctor[count + 1];
			count++;
			for (int i = 0; i < count; i++)
			{
				temp[i] = oldArr[i];
			}

			delete[] newArr;
			newArr = temp;
		}
	}
	if (count == 0)
	{
		cout << "Поиск не выдал результов\n";
	}
}

istream& operator>>(istream& in, Doctor& obj)
{
	char buf[20];
	int spec, qual;

	cout << "Введите фамилию: ";
	in.getline(buf, 20);
	obj.getFIO().setSurname(buf);
	cout << "Введите имя: ";
	in.getline(buf, 20);
	obj.getFIO().setName(buf);
	cout << "Введите отчество: ";
	in.getline(buf, 20);
	obj.getFIO().setFather(buf);

	do
	{
		cout << "Введите специальность (1-3): ";
		in >> spec;
	} while (checkInput(spec, 0));
	obj.setSpecialtyId(spec);

	do
	{
		cout << "Введите квалификация (0-2): ";
		in >> qual;
	} while (checkInput(qual, 1));
	obj.setQualificationId(qual);

	return in;
}
ostream& operator<<(ostream& out, Fio& obj)
{
	char buf[60];
	strcpy(buf, obj.getSurname());
	strcat(buf, " ");
	strcat(buf, obj.getName());
	strcat(buf, " ");
	strcat(buf, obj.getFather());

	out << buf;
	return out;
}
