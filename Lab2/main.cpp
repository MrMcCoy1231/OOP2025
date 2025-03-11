#include <iostream>
#include "NumberList.h"
#include "globals.h"
#include<iomanip>
#include "Student.h"
using namespace std;

int main()
{
	Student a, b, c;

	a.setname("Marius");
	b.setname("David");
	c.setname("Stefan");

	cout << "Numele elevilor este " << a.getname() << " " << b.getname() << " " << c.getname() << '\n';

	a.setmath(6);
	b.setmath(4);
	c.setmath(7);
	
	if (mathcomp(a, b) == 1)
		cout << "Nota mai mare o are " << a.getname() << '\n';
	else
		if (mathcomp(a, b) == 0)
			cout << "Cei doi au note egale";
		else
			cout << "Nota mai mare o are " << b.getname() << '\n';

	a.setenglish(7);
	b.setenglish(9);
	c.setenglish(4);
	
	a.sethistory(2);
	b.sethistory(9);
	c.sethistory(10);

	if (mediecomp(b, c) == 1)
		cout << "Media mai mare o are " << b.getname() <<", avand media "<<setprecision(3)<<b.getmedie()<< '\n';
	else
		if (mediecomp(a, b) == 0)
			cout << "Cei doi au medii egale, avand media "<<setprecision(3)<<b.getmedie();
		else
			cout << "Media mai mare o are " << c.getname() << ", avand media " << setprecision(3) << c.getmedie() << '\n';


	return 0;
}