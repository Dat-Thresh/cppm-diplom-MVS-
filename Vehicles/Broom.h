#pragma once
#include "AirTS.h"

class Broom :public AirTS {
public:
	VEHICLE_API Broom();
	VEHICLE_API double race(int distance) override;
};