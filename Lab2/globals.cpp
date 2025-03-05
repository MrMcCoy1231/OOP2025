#include "NumberList.h"
#include <iostream>
#include <string.h>

using namespace std;

int namecomp(NumberList a, NumberList b)
{
	if (strcmp(a.getname(), b.getname()) < 0)
		return -1;
	else
		if (strcmp(a.getname(), b.getname()) == 0)
			return 0;
		else
			return 1;

}

int mathcomp(NumberList a, NumberList b)
{
	if (a.getmath() < b.getmath())
		return -1;
	else
		if (a.getmath() == b.getmath())
			return 0;
		else
			return 1;

}

int englishcomp(NumberList a, NumberList b)
{
	if (a.getenglish() < b.getenglish())
		return -1;
	else
		if (a.getenglish() == b.getenglish())
			return 0;
		else
			return 1;

}
int historycomp(NumberList a, NumberList b)
{
	if (a.gethistory() < b.gethistory())
		return -1;
	else
		if (a.gethistory() == b.gethistory())
			return 0;
		else
			return 1;

}

int mediecomp(NumberList a, NumberList b)
{
	if (a.getmedie() < b.getmedie())
		return -1;
	else
		if (a.getmedie() == b.getmedie())
			return 0;
		else
			return 1;

}