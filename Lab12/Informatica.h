#pragma once
#include "Materie.h"

class Informatica : public Materie
{
public:
	Informatica() : Materie("Informatica", "obligatoriu", 6) {}
	string getNume() override
	{
		return "Informatica";
	}
	string getTip() override
	{
		return "Obligatorie";
	}
	int getCredite() override
	{
		return 6;
	}
};