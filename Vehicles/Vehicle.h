#pragma once
#include <string>
#ifdef VEHICLES_EXPORTS
#define VEHICLE_API __declspec(dllexport)
#else
#define VEHICLE_API __declspec(dllimport)
#endif // VEHICLE_EXPORTS

//������� �������� ��x
class Vehicle {
protected:	
	/*id ����������� ���� ����������
	����� ������� ������ ������:
	0. �������-���������
	1. �����
	2. �������
	3. �������
	4. ����
	5. �������-���������
	6. �����-�������*/
	//int id;
	/*������������� ���� ����������:

	/*-200 - �������� ��� ����������
	300 - ��������� ��� ����������
	int type_ts_id = 300;*/
	
	std::string name = "���������";
	int speed = 1; //�������� ��
	Vehicle() {};
public:
	//���������� ���
	VEHICLE_API std::string get_name();
	//���������� ����� ����������� ���������
	VEHICLE_API virtual double race(int distance);
	//VEHICLE_API int get_type_ts_id();
	//VEHICLE_API int get_id();
	


};