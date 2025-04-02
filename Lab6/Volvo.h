#pragma once
#include "Car.h"
class Volvo : public Car
{
public:
	Volvo();
	double getSpeed(Weather weather) const override;
	double getFuelConsumption() const override;
	double getFuelCapacity() const override;
	const char* getName() const override;

};

