#include "Fast-Camel.h"

Fast_Camel::Fast_Camel() :Camel(40, 10, 5) {
	//id = 5;
	name = "Верблюд-быстроход";
	second_rest_time = 6.5;
}

double Fast_Camel::race(int distance) {
	double result;
	result = (double)distance / speed;
	int times_of_rest = (int)result / non_stop_time;

	if (times_of_rest >= 1) {
		//если будет отдыхать 1 раз, то прибавляем только время первого отдыха
		result += rest_time;

		//если 2 то добавляем second_rest_time 
		if (times_of_rest >= 2) {
			result += second_rest_time;
			//если 3 и больше, то еще прибавляем next_rest_time умноженное на количество отдыхов -2
			if (times_of_rest >= 3) {
				//проверяем, будет ли на самом деле последний отдых
				if (will_it_rest_last_time(distance)) {
					result += next_rest_time * (times_of_rest - 2);
				}
				else {
					result += next_rest_time * (times_of_rest - 3);
				}
				
			}
		}
	}
	return result;
}