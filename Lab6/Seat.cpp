#include "Seat.h"

Seat::Seat()
{
	fuelCapacity = 60;
	fuelConsumption = 8.5;
	speedRain = 90;
	speedSnow = 75;
	speedSunny = 140;
}

double Seat::getSpeed(Weather weather) const
{
	if (weather == Sunny)
		return speedSunny;
	else
		if (weather == Rain)
			return speedRain;
		else
			return speedSnow;
}

double Seat::getFuelCapacity() const
{
	return fuelCapacity;
}
double Seat::getFuelConsumption() const
{
	return fuelConsumption;

}

const char* Seat :: getName() const
{
	return "Seat";
}