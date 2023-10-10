#include "AirTS.h"

AirTS::AirTS(int speed, double shortcut_percent) :Vehicle() {
	//type_ts_id = 300;
	this->speed = speed;
	this->shortcat_percent = shortcut_percent;
};

double AirTS::race(int distance) {
	double result;
	result = (double)distance * shortcat_percent / speed;
	
	return result;
}

