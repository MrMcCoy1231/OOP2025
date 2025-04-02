#pragma once
#include "Car.h"
class Fiat : public Car
{
public:
	Fiat();
	double getSpeed(Weather weather) const override;
	double getFuelConsumption() const override;
	double getFuelCapacity() const override;
	const char* getName() const override;
};

