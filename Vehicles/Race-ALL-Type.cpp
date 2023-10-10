#include "Race-ALL-Type.h"
#include <sstream>
#include <iomanip>

void RaceAllType::make_id_list_to_id_array(std::string id_list) {
	std::string buffer; //буфер для записи чисел строки
	//загоняем в потокувую строку  id_list
	std::stringstream reader(id_list);
	//пока не доберемся до конца массива с айди ТС
	for (int i = 0; i < count_reg; i++) {
		
		//записываем оттуда в массив инт
		while (true) {
			if (reader >> id_array[i]) {
				break;
			}
		}

	}
}

//тут мы просматриваем собранные айди, по этому айди создаем классс нужного тс, используем его метод race ->
//-> результат гонки записываем в массив result_array, а имя ТС в result_name_array
//  чтобы не потерять данные после разрушения класса при выходе за область видимости
void RaceAllType::create_ts_and_call_make_race() {
	for (int i = 0; i < count_reg; i++) {		
		/*0. Ботинки - вездеходы
		1. Метла
		2. Верблюд
		3. Кентавр
		4. Орел
		5. Верблюд - быстроход
		6. Ковер - самолет */
		if (id_array[i] == 0) { MagicBoots Mboots; result_array[i] = Mboots.race(distance); result_name_array[i] = Mboots.get_name(); }
		if (id_array[i] == 1) { Broom broom; result_array[i] = broom.race(distance); result_name_array[i] = broom.get_name(); }
		if (id_array[i] == 2) { Camel camel; result_array[i] = camel.race(distance); result_name_array[i] = camel.get_name(); }
		if (id_array[i] == 3) { Centaur centaur; result_array[i] = centaur.race(distance); result_name_array[i] = centaur.get_name(); }
		if (id_array[i] == 4) { Eagle eagle; result_array[i] = eagle.race(distance); result_name_array[i] = eagle.get_name(); }
		if (id_array[i] == 5) { Fast_Camel fast_camel; result_array[i] = fast_camel.race(distance); result_name_array[i] = fast_camel.get_name(); }
		if (id_array[i] == 6) { MagicCarpet Mcarpet; result_array[i] = Mcarpet.race(distance); result_name_array[i] = Mcarpet.get_name(); }
		//std::cout << ts_array[i]->get_name() << "создан!" << std::endl;
	}
	make_race_and_call_fill_result_board();
};

//сравнение результатов и сортировку будем проводить сразу в трех массивах: result_array(по результату), ->
//-> id_array и result_name_array - там будем перемщать содержимое ячейки в ячейку с таким же индексом, с каким будет ячейка в result_array
//так как id_array[i] содержит айди ТС, result_name_array[i] содержит имя того же ТС
//  результат которого хранится в result_array[i];
void RaceAllType::make_race_and_call_fill_result_board() {
	for (int i = 0; i < count_reg; i++) {

		for (int j = i + 1; j < count_reg; j++) {
			if (result_array[j] < result_array[i]) {

				//для сортировки result_array
				double buff_double = result_array[j];
				result_array[j] = result_array[i];
				result_array[i] = buff_double;
				//для сортировки result_name_array
				std::string buff_str = result_name_array[j];
				result_name_array[j] = result_name_array[i];
				result_name_array[i] = buff_str;
				//для сортировки id_array
				int buff_int = id_array[j];
				id_array[j] = id_array[i];
				id_array[i] = buff_int;
			}
		}
	}
	fill_result_board();
}

void RaceAllType::fill_result_board() {
	result_board = "Результаты гонки:\n";
	for (int i = 0; i < count_reg; i++) {
		result_board += std::to_string(i+1) + ". " + result_name_array[i] + ". Время: " + make_beaty(i) + "\n";
	}
}

std::string RaceAllType::get_result_board() { return result_board; }

RaceAllType::RaceAllType(int count_reg, std::string id_list, int distance) {
	this->distance = distance;
	this->count_reg = count_reg;

	result_array = new double[count_reg];
	if (result_array == NULL) { throw std::runtime_error("Недостаточно памяти!"); }

	id_array = new int[count_reg];
	if (id_array == NULL) { throw std::runtime_error("Недостаточно памяти!"); }

	result_name_array = new std::string[count_reg];
	if (result_name_array == NULL) { throw std::runtime_error("Недостаточно памяти!"); }

	make_id_list_to_id_array(id_list);
	create_ts_and_call_make_race();
}

RaceAllType::~RaceAllType() {
	
	delete[] result_array;
	delete[] id_array;
	delete[] result_name_array;
}

std::string RaceAllType::make_beaty(int i) {
	std::stringstream buff;//для подготовки результата к записи в строку
	int number = result_array[i];//запоминаем с откидыванием остатка
	int cifer_count = 0;
	//считаем количество цифр до запятой
	while (number != 0) {
		number /= 10;
		cifer_count++;
	}

	//если 0, то убираем знаки, если что-то есть, то оставляем только 2ого знака, если 2ой знак не 0
	double res_arr_plus = result_array[i] * 100;//для запоминания числа результата со смещением запятой вправо в два знака 
	//cмотрим на первый знак после запятой оригинального значения result_array[i]
	if ((int)res_arr_plus % 100 / 10== 0) {
		buff << (int)result_array[i];
		return buff.str();
	}
	//если не ноль, смотрим на второй
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
