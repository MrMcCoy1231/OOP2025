#pragma once
#include "Materie.h"

class Optional1 : public Materie
{
public:
	Optional1() : Materie("Psihologie", "optional", 2) {}
	string getNume() override
	{
		return "Psihologie";
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