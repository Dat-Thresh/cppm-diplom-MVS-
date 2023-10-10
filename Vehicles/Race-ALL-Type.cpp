#include "Race-ALL-Type.h"
#include <sstream>
#include <iomanip>

void RaceAllType::make_id_list_to_id_array(std::string id_list) {
	std::string buffer; //����� ��� ������ ����� ������
	//�������� � ��������� ������  id_list
	std::stringstream reader(id_list);
	//���� �� ��������� �� ����� ������� � ���� ��
	for (int i = 0; i < count_reg; i++) {
		
		//���������� ������ � ������ ���
		while (true) {
			if (reader >> id_array[i]) {
				break;
			}
		}

	}
}

//��� �� ������������� ��������� ����, �� ����� ���� ������� ������ ������� ��, ���������� ��� ����� race ->
//-> ��������� ����� ���������� � ������ result_array, � ��� �� � result_name_array
//  ����� �� �������� ������ ����� ���������� ������ ��� ������ �� ������� ���������
void RaceAllType::create_ts_and_call_make_race() {
	for (int i = 0; i < count_reg; i++) {		
		/*0. ������� - ���������
		1. �����
		2. �������
		3. �������
		4. ����
		5. ������� - ���������
		6. ����� - ������� */
		if (id_array[i] == 0) { MagicBoots Mboots; result_array[i] = Mboots.race(distance); result_name_array[i] = Mboots.get_name(); }
		if (id_array[i] == 1) { Broom broom; result_array[i] = broom.race(distance); result_name_array[i] = broom.get_name(); }
		if (id_array[i] == 2) { Camel camel; result_array[i] = camel.race(distance); result_name_array[i] = camel.get_name(); }
		if (id_array[i] == 3) { Centaur centaur; result_array[i] = centaur.race(distance); result_name_array[i] = centaur.get_name(); }
		if (id_array[i] == 4) { Eagle eagle; result_array[i] = eagle.race(distance); result_name_array[i] = eagle.get_name(); }
		if (id_array[i] == 5) { Fast_Camel fast_camel; result_array[i] = fast_camel.race(distance); result_name_array[i] = fast_camel.get_name(); }
		if (id_array[i] == 6) { MagicCarpet Mcarpet; result_array[i] = Mcarpet.race(distance); result_name_array[i] = Mcarpet.get_name(); }
		//std::cout << ts_array[i]->get_name() << "������!" << std::endl;
	}
	make_race_and_call_fill_result_board();
};

//��������� ����������� � ���������� ����� ��������� ����� � ���� ��������: result_array(�� ����������), ->
//-> id_array � result_name_array - ��� ����� ��������� ���������� ������ � ������ � ����� �� ��������, � ����� ����� ������ � result_array
//��� ��� id_array[i] �������� ���� ��, result_name_array[i] �������� ��� ���� �� ��
//  ��������� �������� �������� � result_array[i];
void RaceAllType::make_race_and_call_fill_result_board() {
	for (int i = 0; i < count_reg; i++) {

		for (int j = i + 1; j < count_reg; j++) {
			if (result_array[j] < result_array[i]) {

				//��� ���������� result_array
				double buff_double = result_array[j];
				result_array[j] = result_array[i];
				result_array[i] = buff_double;
				//��� ���������� result_name_array
				std::string buff_str = result_name_array[j];
				result_name_array[j] = result_name_array[i];
				result_name_array[i] = buff_str;
				//��� ���������� id_array
				int buff_int = id_array[j];
				id_array[j] = id_array[i];
				id_array[i] = buff_int;
			}
		}
	}
	fill_result_board();
}

void RaceAllType::fill_result_board() {
	result_board = "���������� �����:\n";
	for (int i = 0; i < count_reg; i++) {
		result_board += std::to_string(i+1) + ". " + result_name_array[i] + ". �����: " + make_beaty(i) + "\n";
	}
}

std::string RaceAllType::get_result_board() { return result_board; }

RaceAllType::RaceAllType(int count_reg, std::string id_list, int distance) {
	this->distance = distance;
	this->count_reg = count_reg;

	result_array = new double[count_reg];
	if (result_array == NULL) { throw std::runtime_error("������������ ������!"); }

	id_array = new int[count_reg];
	if (id_array == NULL) { throw std::runtime_error("������������ ������!"); }

	result_name_array = new std::string[count_reg];
	if (result_name_array == NULL) { throw std::runtime_error("������������ ������!"); }

	make_id_list_to_id_array(id_list);
	create_ts_and_call_make_race();
}

RaceAllType::~RaceAllType() {
	
	delete[] result_array;
	delete[] id_array;
	delete[] result_name_array;
}

std::string RaceAllType::make_beaty(int i) {
	std::stringstream buff;//��� ���������� ���������� � ������ � ������
	int number = result_array[i];//���������� � ������������ �������
	int cifer_count = 0;
	//������� ���������� ���� �� �������
	while (number != 0) {
		number /= 10;
		cifer_count++;
	}

	//���� 0, �� ������� �����, ���� ���-�� ����, �� ��������� ������ 2��� �����, ���� 2�� ���� �� 0
	double res_arr_plus = result_array[i] * 100;//��� ����������� ����� ���������� �� ��������� ������� ������ � ��� ����� 
	//c������ �� ������ ���� ����� ������� ������������� �������� result_array[i]
	if ((int)res_arr_plus % 100 / 10== 0) {
		buff << (int)result_array[i];
		return buff.str();
	}
	//���� �� ����, ������� �� ������
	else {
		if ((int)res_arr_plus % 10 == 0) {
			buff << std::fixed << std::setprecision(1) << result_array[i];
		}
		else {
			buff << std::fixed << std::setprecision(2) << result_array[i];
		}
	}
	return buff.str();

}

//Vehicle** RaceAllType::get_ts_array() { return ts_array; }
//int* RaceAllType::get_id_arr() {
//	return id_array;
//}
