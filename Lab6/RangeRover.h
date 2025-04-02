#pragma once
#include "Car.h"
class RangeRover : public Car
{
public:
	RangeRover();
	double getSpeed(Weather weather) const override;
	double getFuelConsumption() const override;
	double getFuelCapacity() const override;
	const char* getName() const override;

};

