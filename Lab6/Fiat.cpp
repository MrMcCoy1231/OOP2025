#include "Fiat.h"
Fiat::Fiat()
{
	fuelCapacity = 50;
	fuelConsumption = 5.3;
	speedRain = 45;
	speedSnow = 35;
	speedSunny = 80;
}

double Fiat::getSpeed(Weather weather) const
{
	if (weather == Sunny)
		return speedSunny;
	else
		if (weather == Rain)
			return speedRain;
		else
			return speedSnow;

}

double Fiat::getFuelCapacity() const
{
	return fuelCapacity;
}

double Fiat::getFuelConsumption() const
{
	return fuelConsumption;
}

const char* Fiat::getName() const
{
	return "Fiat";
}