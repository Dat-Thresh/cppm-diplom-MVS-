#pragma once
#include "Camel.h"
//��������� �� �������� ��������
class Fast_Camel :public Camel {
protected:
	double second_rest_time;//����� ������� ������
public:
	//����������� �� ��������� ��� ��������-����������(���������� ���������� ����������� �������� ��������)
	VEHICLE_API Fast_Camel();
	VEHICLE_API double race(int distance) override;
};