#pragma once
#include "Materie.h"

class Romana : public Materie
{
public:
	Romana() : Materie("Romana", "obligatoriu", 5) {}
	string getNume() override
	{
		return "Romana";
	}
	string getTip() override
	{
		return "obligatoriu";
	}
	int getCredite() override
	{
		return 5;
	}
};