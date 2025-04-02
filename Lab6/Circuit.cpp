#include "Circuit.h"
#include <iostream>
#include <iomanip>
using namespace std;
Circuit::Circuit()
{
	this->length = 0;
	this->weather = Sunny;
	this->carCount = 0;
}
Circuit :: ~Circuit()
{
	for (int i = 0;i < carCount;i++)
		delete cars[i];
}

void Circuit::setLength(double x)
{
	this->length = x;
}
void Circuit::setWeather(Weather weather)
{
	this->weather = weather;
}
void Circuit::AddCar(Car* car)
{
	if (carCount < 10)
		cars[carCount++] = car;
}
void Circuit::Race()
{
	for (int i = 0;i < carCount;i++)
	{
		double speed = cars[i]->getSpeed(weather);
		double fuelNeeded = (length / 100) * cars[i]->getFuelConsumption();
		bool finished = fuelNeeded <= cars[i]->getFuelCapacity();
		
		if (finished)
			result[i] = { cars[i],length / speed,true };
		else
			result[i] = { cars[i],0,false };

		for(int i=0;i<carCount-1;i++)
			for(int j=i+1;j<carCount;j++)
				if ( result[i].finished && (!result[j].finished || result[i].time < result[j].time))
				{
					RaceResult aux = result[i];
					result[i] = result[j];
					result[j] = aux;
				}


	}
}

void Circuit::ShowFinalRanks() const
{
	cout << "The final ranks are: \n";
	for (int i = 0;i < carCount;i++)
		if (result[i].finished)
			cout << result[i].car->getName() << " finished in " <<setprecision(2)<< result[i].time << " hours.\n";

}

void Circuit::ShowWhoDidNotFinish() const
{	
	int ok = 1;
	for (int i = 0;i < carCount;i++)
		if (!result[i].finished)
			ok = 0;
	if(!ok)
	{
		cout << "The cars that haven't finished are:\n";
		
		for (int i = 0;i < carCount;i++)
			if (!result[i].finished)
				cout << result[i].car->getName() << " did not finish.\n";
		}
	
}