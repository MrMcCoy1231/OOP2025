#pragma once
#include "Materie.h"
class Math : public Materie
{
public:
	Math() : Materie("Matematica", "obligatoriu", 6) {}
	string getNume() override
	{
		return "Matematica";
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
