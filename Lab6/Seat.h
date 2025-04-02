#pragma once
#include "Car.h"
class Seat : public Car
{
public:
	Seat();
	double getSpeed(Weather weather) const override;
	double getFuelConsumption() const override;
	double getFuelCapacity() const override;
	const char* getName() const override;

};

