#include "Broom.h"

Broom::Broom():AirTS(20, 1) {
	//id = 1;
	name = "�����";
}

double Broom::race(int distance) {
	//���� ��������� ������ 1000, �� ������ ������� ����������
	if (distance > 1000) {
		shortcat_percent = (double)(100-(int)distance / 1000)/100;
		//���� ��������� ����� ��� ������ 100�, �� ���� ��� �������, ����� �� ���� � �����(� �� �� ���� ��� �����������)
		if (distance >= 100000) {
			shortcat_percent = 0.05;
		}
	}
	double result = distance * shortcat_percent / speed;
	return result;
}