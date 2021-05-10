#pragma once
#include <iostream>
class Fio {
	char* surname;
	char* name;
	char* father;
public:
	friend class Doctor;
	friend std::ostream& operator<<(std::ostream& out, Fio& obj);

	Fio();
	Fio(const Fio& obj);
	~Fio();

	char* getSurname();
	char* getName();
	char* getFather();

	void setSurname(const char* surname);
	void setName(char* name);
	void setFather(char* father);
	void setFIO(char* surname, char* name, char* father);
};