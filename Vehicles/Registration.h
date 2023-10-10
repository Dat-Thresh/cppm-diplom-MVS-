#pragma once
#include "AllTransportsList.h"

//����� ��� ���������� �����������
class Registration {
protected:
	
	//��� (������������� �������� ���� �����)
	std::string name;

	//������ ������������� ����������
	std::string ts[7]{ "�������-���������", "�����", "�������", "�������", "���", "�������-���������", "�����-�������" };

	//������ ������, ������� ����� �������� � �������� ����������� ��
	//������ ������������� ������� �� �� ������� ����
	//���� true - �� ��������� ������������, false- ������ ���������
	bool able_to_reg[7]{};

	//�������� ������ � ������������ �� � ���� �����
	//������ ������������� ������� �� �� ������� ����
	//���� true - �� ��������� ������������, false- ������ ���������
	bool comparability_to_type_race[7]{};

	//�������� �������� ���� �����: 1 - ��������, 2 - ���������, 3- ��� ����
	int race_type;

	//���������� �������� �������������
	int distance;

	//��������� ����������� (������� �� ������������ ��������� ����������)
	bool more_than_one = false;

	//�������������� ������ � ������������������ ��, ��� ����� �������� ��
	std::string info_list;
	//���� ���������� id ������������������ ��
	std::string id_list;

	//������ ���������� ���������
	int count_reg;

	//����� ������� ���������
	VEHICLE_API void count_up();
	//������ � ������� able_to_reg ��������� ������ ��� ����������� ���������.(� ������������ � ��� ��������) c true �� false
	VEHICLE_API void change_repeat_status(int i);
	//���������� ��������� ������ able_to_reg
	VEHICLE_API bool check_repeat_status(int i);
	//���������� ��������� ������ comparability_to_reg
	VEHICLE_API bool check_comparability(int i);
	//��������� id ���������� � id_list
	VEHICLE_API void add_id(int i);

public:
	//����������� ��������� ����� ���� ����� � ����������
	VEHICLE_API Registration(int numb, int distance);
	//���������� �������� ���� �����
	VEHICLE_API std::string get_race_type();
	//���������� ����� ���������
	VEHICLE_API int get_distance();
	//���������� ��� ����������� ���������
	VEHICLE_API std::string get_ts_name(int i);
	//���������� ���������: ������� �� ����������
	VEHICLE_API bool get_status();
	//������ ������ ��������� �����������, ��� ����������� ���-�� ����������
	VEHICLE_API void check_if_enough(int i);
	//���������� ������ info_list
	VEHICLE_API std::string get_info_list();
	//��������� ����� ���������� � info_list
	VEHICLE_API void add_info(std::string);
	//���������� ���������� ���������
	VEHICLE_API int get_count_reg();
	//���������� ������ ������ id_list, ��� �������� ���� ���������� ��
	VEHICLE_API std::string get_id_list();

	/*����� ��������� ����������� ����������� �� ���� �� � ��� �������
	����������:
	0-����� ��������������
	1-��� ���������������
	-1-�� ������������� ���� �����*/
	VEHICLE_API int if_can_to_reg(int i);
};