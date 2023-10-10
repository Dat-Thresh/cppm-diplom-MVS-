#include "Registration.h"

Registration::Registration(int numb, int distance) {
	this->distance = distance;
	count_reg = 0; //�������� �������
	//������ � ������� ���������� ����������� ����� true;
	for (int i = 0; i < 7; i++) {
		able_to_reg[i] = true;
	}
	//������������� ��� ����� � ����������� �� ������ �����
	//� ��������� ������ ������������ �� � ���� ����� � ����������� �� ���� �����
	switch (numb)
	{
	case 1:
		/*id ����������� ���� ����������
	����� ������� ������ ������:
	0. �������-���������
	1. �����
	2. �������
	3. �������
	4. ����
	5. �������-���������
	6. �����-�������*/
		name = "����� ��� ��������� ����������"; 
		race_type = 1;
		comparability_to_type_race[0] = true;
		comparability_to_type_race[2] = true;
		comparability_to_type_race[3] = true;
		comparability_to_type_race[5] = true;
		break;
	case 2:
		name = "����� ��� ���������� ����������"; 
		race_type = 2;
		comparability_to_type_race[1] = true;
		comparability_to_type_race[4] = true;
		comparability_to_type_race[6] = true;
		
		break;
	case 3:
		name = "����� ��� ��������� � ���������� ����������"; 
		race_type = 3; 
		for (int i = 0; i < 7; i++) {
			comparability_to_type_race[i] = true;
		}
		break;
	default:
		break;
	}
}

std::string Registration::get_race_type() { return name; }
int Registration::get_distance() { return distance; }
std::string Registration::get_ts_name(int i) { return ts[i]; }
bool Registration::get_status() { return more_than_one; }
void Registration::check_if_enough(int i) { if (i > 1) { more_than_one = true; } }
std::string Registration::get_info_list() { return info_list; }
void Registration::add_info(std::string word) { info_list += word; }
int Registration::get_count_reg() { return count_reg; }
void Registration::count_up() { count_reg++; }
void Registration::change_repeat_status(int i) { able_to_reg[i] = false; }
bool Registration::check_repeat_status(int i) { return able_to_reg[i]; }
bool Registration::check_comparability(int i) { return comparability_to_type_race[i]; }
void Registration::add_id(int i) { id_list += std::to_string(i) + " "; }
std::string Registration::get_id_list() { return id_list; }

int Registration::if_can_to_reg(int i) {
	int succes_state;
	//���� �������� �������� �� ������������ ���� �����
	if (check_comparability(i)) {
		//���� ��� �� �������
		if (check_repeat_status(i)) {			
			//������ ����������� ����������� ������� ��������� ��� ��� �� false
			change_repeat_status(i);
			//����� �������, ���� �����
			count_up();
			//��� ������, ���� ��� ���� ������������������, �� ��������� ������� � ������������
			if (get_count_reg() > 1) {
				add_info(", ");
			}
			//��������� � ������ ������� ������������������ ��� ������
			add_info(get_ts_name(i));
			//��������� � ������ ���� ����� ����������� ��
			add_id(i);
			succes_state = 0;
		}
		//���� ��� �������
		else {
			succes_state = 1;
		}
	}
	//���� �� �������� �������� �� ���� �����
	else {
		succes_state = -1;
	}
	return succes_state;
}