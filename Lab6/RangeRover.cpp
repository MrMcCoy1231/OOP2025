#include "RangeRover.h"

RangeRover::RangeRover()
{
	fuelCapacity = 75;
	fuelConsumption = 11.5;
	speedSunny = 160;
	speedRain = 120;
	speedSnow = 110;
}

double RangeRover::getSpeed(Weather weather) const
{
	if (weather == Sunny)
		return speedSunny;
	else
		if (weather == Rain)
			return speedRain;
		else
			return speedSnow;
}

double RangeRover::getFuelCapacity() const
{
	return fuelCapacity;
}

double RangeRover::getFuelConsumption() const
{
	return fuelConsumption;
}
const char* RangeRover::getName() const
{
	return "RangeRover";
}