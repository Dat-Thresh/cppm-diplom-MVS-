#pragma once
#include <string>
#ifdef VEHICLES_EXPORTS
#define VEHICLE_API __declspec(dllexport)
#else
#define VEHICLE_API __declspec(dllimport)
#endif // VEHICLE_EXPORTS

//базовый родитель ТСx
class Vehicle {
protected:	
	/*id конкретного вида транспорта
	далее следует такому списку:
	0. Ботинки-вездеходы
	1. Метла
	2. Верблюд
	3. Кентавр
	4. Орел
	5. Верблюд-быстроход
	6. Ковер-самолет*/
	//int id;
	/*идентификатор типа транспорта:

	/*-200 - наземный тип транспорта
	300 - воздушный тип транспорта
	int type_ts_id = 300;*/
	
	std::string name = "Транспорт";
	int speed = 1; //скорость ТС
	Vehicle() {};
public:
	//возвращает имя
	VEHICLE_API std::string get_name();
	//возвращает время прохождения дистанции
	VEHICLE_API virtual double race(int distance);
	//VEHICLE_API int get_type_ts_id();
	//VEHICLE_API int get_id();
	


};