#include "Camel.h"
//для наследника верблюда-быстрохода
Camel::Camel(int speed, int non_stop_time, float rest_time) :LandTS(speed, non_stop_time, rest_time) {
	next_rest_time = 8.0;
};
Camel::Camel() : LandTS(10, 30, 5.0) {
	//id = 2;
	name = "Верблюд";
	next_rest_time = 8.0;
}

double Camel::race(int distance) {
	double result;
	result = (double)distance / speed;
	int times_of_rest;
	
	if ((times_of_rest = result / non_stop_time) >= 1) {
		//если будет отдыхать 1 раз, то прибавляем только время первого отдыха
		result += rest_time;
		
		//если 2 и больше, то умножаем next_rest_time на количество отдыхов -1 (ведь первый раз уже учли)
		if(times_of_rest >= 2) {
			
			result += next_rest_time * (times_of_rest-1);
			//но еще нужно проверить, будем ли считать последний отдых, если нет, то убираем последний отдых
			if (!will_it_rest_last_time(distance)) {
				result -= next_rest_time;
			}
		}
	}
	return result;
}
