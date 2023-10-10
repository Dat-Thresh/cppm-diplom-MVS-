#include "Broom.h"

Broom::Broom():AirTS(20, 1) {
	//id = 1;
	name = "Метла";
}

double Broom::race(int distance) {
	//если дистанция больше 1000, то меняем процент сокращения
	if (distance > 1000) {
		shortcat_percent = (double)(100-(int)distance / 1000)/100;
		//если дистанция равна или больше 100к, то ввел доп правило, чтобы не ушло в минус(в тз не было это обусловлено)
		if (distance >= 100000) {
			shortcat_percent = 0.05;
		}
	}
	double result = distance * shortcat_percent / speed;
	return result;
}