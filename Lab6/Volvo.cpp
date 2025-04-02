#include "Volvo.h"

Volvo::Volvo()
{
	fuelCapacity = 60;
	fuelConsumption = 7.5;
	speedSunny = 150;
	speedRain = 90;
	speedSnow = 70;

}
double Volvo :: getSpeed(Weather weather) const
{
	if (weather == Sunny)
		return speedSunny;
	else
		if (weather == Rain)
			return speedRain;
		else
			return speedSnow;

}

double Volvo::getFuelCapacity() const
{
	return fuelCapacity;
}

double Volvo::getFuelConsumption()const
{
	return fuelConsumption;
}
const char* Volvo::getName()const
{
	return "Volvo";
}