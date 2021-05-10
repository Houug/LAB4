#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <fstream>
#include "Doctor.h"
#include "Reception.h"
#include "functions.h"
#include "Data.h"

#define path "data.txt"
using namespace std;

// Default count of Doctor's class objects
int Doctor::count = 0;

int main()
{
	setlocale(LC_ALL, "Russian");

	// Block of variables
	fstream data;
	Doctor* arr = NULL;
	Doctor* foundDoctors = NULL;
	int menu, count = 0;

	// Load/create database
	data.open(path);
	if (!data.is_open())
	{
		cout << "Файл не открылся!" << endl;
		data.open(path, fstream::app);
		if (data.is_open())
		{
			cout << "Создание нового файла!" << endl;
			createData(arr);
		}
		else
		{
			cout << "Обратитесь к администратору!" << endl;
			return 0;
		}
		return 0;
	}
	else
	{
		loadData(arr, data);
	}

	// Menu
	do
	{
		printMenu();
		do
		{
			cout << "Выберите пункт меню: ";
			cin >> menu;
			getchar();
		} while (checkInput());

		switch (menu)
		{
		case 1:
			arr->addDoctor(arr);
			break;
		case 2:
			findDoctor(arr);
			break;
		case 3:
			filterDoctor(arr, foundDoctors, count);

			if (count != 0)
			{
				printHeader();
				for (int i = 0; i < count; i++)
				{
					foundDoctors->printDoctor(i);
				}
			}
			delete[] foundDoctors;
			break;
		case 4:
			sortData(arr);
			break;
		case 5:
			arr->printAllDoctors();
			break;
		case 6:
			arr->standartObjectEvent(arr);
			break;
		case 7:
			saveData(arr, data);
			data.close();
			delete[] arr;
			return 0;
		default:
			cout << "Введенный вами пункт меню не существует" << endl;
			break;
		}
	} while (TRUE);
}