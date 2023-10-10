#include "Fast-Camel.h"

Fast_Camel::Fast_Camel() :Camel(40, 10, 5) {
	//id = 5;
	name = "�������-���������";
	second_rest_time = 6.5;
}

double Fast_Camel::race(int distance) {
	double result;
	result = (double)distance / speed;
	int times_of_rest = (int)result / non_stop_time;

	if (times_of_rest >= 1) {
		//���� ����� �������� 1 ���, �� ���������� ������ ����� ������� ������
		result += rest_time;

		//���� 2 �� ��������� second_rest_time 
		if (times_of_rest >= 2) {
			result += second_rest_time;
			//���� 3 � ������, �� ��� ���������� next_rest_time ���������� �� ���������� ������� -2
			if (times_of_rest >= 3) {
				//���������, ����� �� �� ����� ���� ��������� �����
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