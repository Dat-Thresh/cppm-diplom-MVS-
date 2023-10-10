#include "Registration.h"

Registration::Registration(int numb, int distance) {
	this->distance = distance;
	count_reg = 0; //обнул€ем счетчик
	//ставим в массиве разрешени€ регистрации везде true;
	for (int i = 0; i < 7; i++) {
		able_to_reg[i] = true;
	}
	//устанавливаем тип гонки в зависимости от выбора юзера
	//и заполн€ем массив соответстви€ “— к типу гонки в зависимости от типа гонки
	switch (numb)
	{
	case 1:
		/*id конкретного вида транспорта
	далее следует такому списку:
	0. Ѕотинки-вездеходы
	1. ћетла
	2. ¬ерблюд
	3.  ентавр
	4. ќрел
	5. ¬ерблюд-быстроход
	6.  овер-самолет*/
		name = "√онка дл€ наземного транспорта"; 
		race_type = 1;
		comparability_to_type_race[0] = true;
		comparability_to_type_race[2] = true;
		comparability_to_type_race[3] = true;
		comparability_to_type_race[5] = true;
		break;
	case 2:
		name = "√онка дл€ воздушного транспорта"; 
		race_type = 2;
		comparability_to_type_race[1] = true;
		comparability_to_type_race[4] = true;
		comparability_to_type_race[6] = true;
		
		break;
	case 3:
		name = "√онка дл€ наземного и воздушного транспорта"; 
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
	//если проходит проверку по соответствию типу гонки
	if (check_comparability(i)) {
		//если еще не зареган
		if (check_repeat_status(i)) {			
			//мен€ем возможность регистрации данного участника еще раз на false
			change_repeat_status(i);
			//апаем счетчик, если успех
			count_up();
			//при успехе, если уже есть зарегистрированный, то добавл€ем зап€тую в перечислении
			if (get_count_reg() > 1) {
				add_info(", ");
			}
			//добавл€ем в список успешно зарегистрированных при успехе
			add_info(get_ts_name(i));
			//добавл€ем в список айди номер зареганного “—
			add_id(i);
			succes_state = 0;
		}
		//если уже зареган
		else {
			succes_state = 1;
		}
	}
	//если не проходит проверку по типу гонки
	else {
		succes_state = -1;
	}
	return succes_state;
}