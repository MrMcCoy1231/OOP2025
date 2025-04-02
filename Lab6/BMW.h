#pragma once
#include "Car.h"
class BMW : public Car
{
public:
	BMW();
	double getSpeed(Weather weather) const override;
	double getFuelConsumption() const override;
	double getFuelCapacity() const override;
	const char* getName() const override;
};

