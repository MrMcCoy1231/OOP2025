#include "BMW.h"
BMW::BMW()
{
	fuelCapacity = 55;
	fuelConsumption = 25;
	speedRain = 170;
	speedSunny = 240;
	speedSnow = 150;
}

double BMW::getSpeed(Weather weather) const
{
	if (weather == Sunny)
		return speedSunny;
	else
		if (weather == Rain)
			return speedRain;
		else
			return speedSnow;

}

double BMW::getFuelCapacity()const
{
	return fuelCapacity;
}
double BMW::getFuelConsumption()const
{
	return fuelConsumption;
}

const char* BMW :: getName() const
{
	return "BMW";
}