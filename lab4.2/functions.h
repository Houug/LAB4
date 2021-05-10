#pragma once
#include <cstdio>
#include <stdio.h>
#include "Doctor.h"

int checkInput(int n, int mode);
void printHeader();
void printMenu();
bool checkInput();
Doctor findDoctor(Doctor* m);
void sortData(Doctor* m);
void push_back(Doctor*& m);