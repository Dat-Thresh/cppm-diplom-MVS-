#pragma once
#include "Vehicle.h"

class AirTS :public Vehicle {
protected:
	double shortcat_percent = 1.0;
public:
	VEHICLE_API AirTS(int speed, double shortcat_percent);
	VEHICLE_API double race(int distance) override;

};