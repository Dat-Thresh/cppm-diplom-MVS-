#pragma once

#include "Vehicle.h"

class LandTS:public Vehicle {
protected:
	
	int non_stop_time; //время движения до отдыха
	double rest_time; //время отдыха
	//проверяет, будет ли отдыхать на самом деле последний раз
	VEHICLE_API bool will_it_rest_last_time(int distance);
public:
	VEHICLE_API LandTS(int speed, int non_stop_time, double rest_time);
	VEHICLE_API double race(int distance) override;
	
};