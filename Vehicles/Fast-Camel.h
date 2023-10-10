#pragma once
#include "Camel.h"
//наследуем от обычного верблюда
class Fast_Camel :public Camel {
protected:
	double second_rest_time;//время второго отдыха
public:
	//конструктор по умолчанию для верблюда-быстрохода(использует защищенный конструктор обычного Верблюда)
	VEHICLE_API Fast_Camel();
	VEHICLE_API double race(int distance) override;
};