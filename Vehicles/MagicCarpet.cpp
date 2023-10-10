#include "Magic-Carpet.h"

MagicCarpet::MagicCarpet() :AirTS(10, 0) {
	//id = 6;
	name = "�����-�������";
}

double MagicCarpet::race(int distance) {
	//���� ����� ��� ������ 10�
	if (distance >= 10000) {
		shortcat_percent = 0.95;
	}
	else {
		//���� ������ 10� ������ ������� ����������, �� ���� ��������� ��� �������
		shortcat_percent = 0.9;
		
		if (distance < 5000 && distance > 1000) {
			shortcat_percent = 0.97;
		}
	}
	double result = distance * shortcat_percent / speed;

	return result;
}