#include "Magic-Carpet.h"

MagicCarpet::MagicCarpet() :AirTS(10, 0) {
	//id = 6;
	name = "Ковер-самолет";
}

double MagicCarpet::race(int distance) {
	//если равно или больше 10к
	if (distance >= 10000) {
		shortcat_percent = 0.95;
	}
	else {
		//если меньше 10к меняем процент сокращения, но ниже проверяем еще условия
		shortcat_percent = 0.9;
		
		if (distance < 5000 && distance > 1000) {
			shortcat_percent = 0.97;
		}
	}
	double result = distance * shortcat_percent / speed;

	return result;
}