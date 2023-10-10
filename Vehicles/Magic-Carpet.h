#pragma once
#include "AirTS.h"
class MagicCarpet :public AirTS {
public:
	VEHICLE_API MagicCarpet();
	VEHICLE_API double race(int distance) override;
};