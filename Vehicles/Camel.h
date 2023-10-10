#pragma once
#include "landTS.h"


class Camel : public LandTS{
protected:
	float next_rest_time;
	Camel(int speed, int non_stop_time, float rest_time);
public:
	//����������� �� ��������� �������� ���������� ����������� ������� ���������� � ����������� �� �������
	VEHICLE_API Camel();
	VEHICLE_API double race(int distance) override;
};