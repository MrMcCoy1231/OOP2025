#pragma once
#include "Car.h"

class Circuit
{
	double length;
	Weather weather;
	Car* cars[10];
	int carCount;
	
	struct RaceResult {
		Car* car;
		double time;
		bool finished;
	}result[10];
public:
	Circuit();
	~Circuit();
	void setLength(double x);
	void setWeather(Weather weather);
	void AddCar(Car* car);
	void Race();
	void ShowFinalRanks() const;
	void ShowWhoDidNotFinish() const;

};

