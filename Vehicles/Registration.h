#pragma once
#include "AllTransportsList.h"

//нужен для проведения регистрации
class Registration {
protected:
	
	//имя (подразумевает название вида гонки)
	std::string name;

	//список потенциальных участников
	std::string ts[7]{ "Ботинки-вездеходы", "Метла", "Верблюд", "Кентавр", "Орёл", "Верблюд-быстроход", "Ковер-самолет" };

	//булеан массив, который будет меняться в процессе регистрации ТС
	//индекс соответствует индеску тс из массива выше
	//если true - то разрещено учавствовать, false- нельзя допускать
	bool able_to_reg[7]{};

	//содержит данные о соответствии ТС к типу гонки
	//индекс соответствует индеску тс из массива выше
	//если true - то разрещено учавствовать, false- нельзя допускать
	bool comparability_to_type_race[7]{};

	//номерное значение вида гонки: 1 - наземная, 2 - воздушная, 3- оба вида
	int race_type;

	//расстояние заданное пользователям
	int distance;

	//состояние регистрации (хватает ли минимального количесва участников)
	bool more_than_one = false;

	//информационная строка о зарегистрированных тс, где пишем названия тс
	std::string info_list;
	//сюда запоминаем id зарегистрированных тс
	std::string id_list;

	//помнит количество зареганых
	int count_reg;

	//апает счетчик зареганых
	VEHICLE_API void count_up();
	//меняет в массиве able_to_reg состояние ячейки при регистрации участника.(в соответствии с его индексом) c true на false
	VEHICLE_API void change_repeat_status(int i);
	//возвращает состояние ячейки able_to_reg
	VEHICLE_API bool check_repeat_status(int i);
	//возвращает состояние ячейки comparability_to_reg
	VEHICLE_API bool check_comparability(int i);
	//добавляет id участников в id_list
	VEHICLE_API void add_id(int i);

public:
	//конструктор принимает номер типа гонки и расстояние
	VEHICLE_API Registration(int numb, int distance);
	//возвращает название вида гонки
	VEHICLE_API std::string get_race_type();
	//возвращает число дистанции
	VEHICLE_API int get_distance();
	//возвращает имя конкретного участника
	VEHICLE_API std::string get_ts_name(int i);
	//возвращает состояние: хватает ли участников
	VEHICLE_API bool get_status();
	//меняет статус состояния регистрации, при достаточном кол-ве участников
	VEHICLE_API void check_if_enough(int i);
	//возвращает строку info_list
	VEHICLE_API std::string get_info_list();
	//добавляет имена участников в info_list
	VEHICLE_API void add_info(std::string);
	//возвращает количество зареганых
	VEHICLE_API int get_count_reg();
	//возвращает массив строки id_list, где записали айди зареганных ТС
	VEHICLE_API std::string get_id_list();

	/*метод проверяет возможность регистрации по виду ТС и его повтору
	возвращает:
	0-можно регистрировать
	1-уже зарегистрирован
	-1-не соответствует типу гонки*/
	VEHICLE_API int if_can_to_reg(int i);
};