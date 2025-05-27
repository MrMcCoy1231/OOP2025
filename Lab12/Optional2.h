#pragma once
#include "Materie.h"

class Optional2 : public Materie
{
public:
	Optional2() : Materie("Sport", "optional", 2) {}
	string getNume() override
	{
		return "Sport";
	}
	string getTip() override
	{
		return "optional";
	}
	int getCredite() override
	{
		return 2;
	}
};