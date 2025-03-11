#include "Student.h"
#include <iostream>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
void Student::setname(const char* name)
{
	this->nume = name;

}
const char* Student::getname()
{
	return this->nume;
}

void Student::setmath(int x)
{
	this->mate = x;
}
int Student::getmath()
{
	return this->mate;

}
void Student::setenglish(int x)
{
	this->english = x;
}
int Student::getenglish()
{
	return this->english;
}

void Student::sethistory(int x)
{
	this->history = x;
}
int Student::gethistory()
{
	return this->history;
}

double Student::getmedie()
{
	return (double)((this->english + this->mate + this->history) / 3.0);

}