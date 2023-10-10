#pragma once
#include "AirTS.h"

class Eagle :public AirTS {
public:
	VEHICLE_API Eagle();
	VEHICLE_API double get_shortcat();
	VEHICLE_API int get_speed();
};