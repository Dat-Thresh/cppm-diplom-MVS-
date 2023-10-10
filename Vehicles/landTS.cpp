#include "landTS.h"

LandTS::LandTS(int speed, int non_stop_time, double rest_time) :Vehicle() {
	//type_ts_id = -200;
	this->speed = speed;
	this->non_stop_time = non_stop_time;
	this->rest_time = rest_time;
}

double LandTS::race(int distance) {
	double result;
	result = distance / speed;
	//если время пути будет больше времени без отдыха, то добавляем время отдыха умноженное на количество отдыхов
	if ((int)result/non_stop_time >= 1) { 
		
		result += rest_time*((int)result/non_stop_time); }
	return result;
}
//если время пути с учетом дробного остатка будет больше чем кол-во отдыхов умноженное на время отдыха
//то вернем true - надо будет и правда отдохнуть этот последний раз
//false-не будем учитывать последний отдых
bool LandTS::will_it_rest_last_time(int distance) {
	int times_of_rest = distance / speed / non_stop_time;//чистое количество отдыхов
	if ((float)distance / speed > times_of_rest * non_stop_time) {
		return true;
	}
	return false;
}
