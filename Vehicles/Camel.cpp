#include "Camel.h"
//��� ���������� ��������-����������
Camel::Camel(int speed, int non_stop_time, float rest_time) :LandTS(speed, non_stop_time, rest_time) {
	next_rest_time = 8.0;
};
Camel::Camel() : LandTS(10, 30, 5.0) {
	//id = 2;
	name = "�������";
	next_rest_time = 8.0;
}

double Camel::race(int distance) {
	double result;
	result = (double)distance / speed;
	int times_of_rest;
	
	if ((times_of_rest = result / non_stop_time) >= 1) {
		//���� ����� �������� 1 ���, �� ���������� ������ ����� ������� ������
		result += rest_time;
		
		//���� 2 � ������, �� �������� next_rest_time �� ���������� ������� -1 (���� ������ ��� ��� ����)
		if(times_of_rest >= 2) {
			
			result += next_rest_time * (times_of_rest-1);
			//�� ��� ����� ���������, ����� �� ������� ��������� �����, ���� ���, �� ������� ��������� �����
			if (!will_it_rest_last_time(distance)) {
				result -= next_rest_time;
			}
		}
	}
	return result;
}
