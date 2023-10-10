#pragma once
#include "AllTransportsList.h"

VEHICLE_API class RaceAllType {
protected:
	//дистанци€ пользовател€
	int distance;
	//кол-во участников
	int count_reg;
	//дл€ записи результата гонки
	std::string result_board;
	//указатель на массив с именами “—
	std::string* result_name_array;
	//указатель на массив с результатами гонки
	double* result_array;
	//указатель на массив с айди “—
	int* id_array;
	//принимает строку с записанными айди “— и превращает в массив типа инт
	VEHICLE_API void make_id_list_to_id_array(std::string id_list);
	//создает классы “— согласно id и заполн€ет массив result_array и result_name_array
	VEHICLE_API void create_ts_and_call_make_race();

	//сортирует массивы result_name_array, id_array и result_array: по значению элементов result_array(от меньшего к большему)
	VEHICLE_API void make_race_and_call_fill_result_board();
	//заполн€ет result_board уже по отсортированным массивам
	VEHICLE_API void fill_result_board();
	//ограничивает кол-во знаков после зап€той или вообще убирает(используем при записи в result_board)
	VEHICLE_API std::string make_beaty(int i);
public:
	VEHICLE_API ~RaceAllType();
	//конструктор, в котором сразу будем прив€зывать указатели на массив с результатами “—, айди “— и именами “—
	//и заполн€ть их соответственно при помощи методов выше
	VEHICLE_API RaceAllType(int count_reg, std::string id_list, int distance);
	//возвращает
	VEHICLE_API std::string get_result_board();




};