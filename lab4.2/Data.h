#pragma once
#include <stdio.h>
#include "Doctor.h"
#include <fstream>

void loadData(Doctor*& m, fstream& data);
void createData(Doctor*& m);
void saveData(Doctor* m, fstream& data);