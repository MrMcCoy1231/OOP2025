#pragma once
#include "Weather.h"
class Car
{
public:
	double fuelCapacity;
	double fuelConsumption;
	double speedSunny;
	double speedRain;
	double speedSnow;

	virtual double getSpeed(Weather weather) const = 0;
	virtual double getFuelConsumption() const = 0;
	virtual double getFuelCapacity() const = 0;
	virtual const char* getName() const = 0;


};
