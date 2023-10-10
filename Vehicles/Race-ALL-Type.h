#pragma once
#include "AllTransportsList.h"

VEHICLE_API class RaceAllType {
protected:
	//��������� ������������
	int distance;
	//���-�� ����������
	int count_reg;
	//��� ������ ���������� �����
	std::string result_board;
	//��������� �� ������ � ������� ��
	std::string* result_name_array;
	//��������� �� ������ � ������������ �����
	double* result_array;
	//��������� �� ������ � ���� ��
	int* id_array;
	//��������� ������ � ����������� ���� �� � ���������� � ������ ���� ���
	VEHICLE_API void make_id_list_to_id_array(std::string id_list);
	//������� ������ �� �������� id � ��������� ������ result_array � result_name_array
	VEHICLE_API void create_ts_and_call_make_race();

	//��������� ������� result_name_array, id_array � result_array: �� �������� ��������� result_array(�� �������� � ��������)
	VEHICLE_API void make_race_and_call_fill_result_board();
	//��������� result_board ��� �� ��������������� ��������
	VEHICLE_API void fill_result_board();
	//������������ ���-�� ������ ����� ������� ��� ������ �������(���������� ��� ������ � result_board)
	VEHICLE_API std::string make_beaty(int i);
public:
	VEHICLE_API ~RaceAllType();
	//�����������, � ������� ����� ����� ����������� ��������� �� ������ � ������������ ��, ���� �� � ������� ��
	//� ��������� �� �������������� ��� ������ ������� ����
	VEHICLE_API RaceAllType(int count_reg, std::string id_list, int distance);
	//����������
	VEHICLE_API std::string get_result_board();




};