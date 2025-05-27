#pragma once
#include <iostream>
#include <string>
using namespace std;

class Materie
{
	
	string nume;
	string tip;
	int credite;

public:
	Materie(string nume, string tip, int credite) : nume(nume), tip(tip), credite(credite) {}
	virtual ~Materie() {}
	virtual string getNume() = 0;
	virtual string getTip() = 0;
	virtual int getCredite() = 0;
	

};

