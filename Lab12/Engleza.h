#pragma once
#include "Materie.h"

class Engleza : public Materie
{
public:
	Engleza() : Materie("Engleza", "facultativ", 3) {}
	string getNume() override
	{
		return "Engleza";
	}
	string getTip() override
	{
		return "facultativ";
	}
	int getCredite() override
	{
		return 3;
	}

};