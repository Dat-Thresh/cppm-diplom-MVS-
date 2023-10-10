#include "Eagle.h"

Eagle::Eagle() :AirTS(8, 0.94) {
	//id = 4;
	name = "Îð¸ë";
}
double Eagle::get_shortcat() { return shortcat_percent; }
int Eagle::get_speed() { return speed; }