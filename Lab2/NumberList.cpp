#include "NumberList.h"
#include <iostream>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
void NumberList::Init()
{
	this->count = 0;
}

bool NumberList::Add(int x)
{
	if (this->count >= 10)
		return false;
	this->count++;
	this->numbers[count] = x;
}

void NumberList::Sort()
{
	int aux;
	for(int i=1;i<=this->count-1;i++)
		for (int j = i + 1;j <= this->count;j++)
			if(this->numbers[i]>this->numbers[j])
		{
			aux = this->numbers[i];
			this->numbers[i] = this->numbers[j];
			this->numbers[j] = aux;
		}

}

void NumberList::Print()
{
	for (int i = 1;i <= count;i++)
		std :: cout << numbers[i] << " ";
}

void NumberList ::  setname(const char* name)
{
	this->nume = name;

}
const char* NumberList :: getname()
{
	return this->nume;
}

void NumberList::setmath(int x)
{
	this->mate = x;
}
int NumberList::getmath()
{
	return this->mate;

}
void NumberList::setenglish(int x)
{
	this->english = x;
}
int NumberList::getenglish()
{
	return this->english;
}

void NumberList::sethistory(int x)
{
	this->history = x;
}
int NumberList::gethistory()
{
	return this->history;
}

double NumberList::getmedie()
{
	return (double)((this->english + this->mate + this->history) / 3.0);

}