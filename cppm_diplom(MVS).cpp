// cppm_diplom(MVS).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <Windows.h>
#include "Registration.h"
#include "Race-ALL-Type.h"
#include <sstream>

//проверяет ввод до тех пор, пока юзер не введет цифры. При успехе возвращает введенное число
int check_input_if_int() {
    std::string buf;
    int numb;
    while (true) {
        //считываем ввод
        getline(std::cin, buf);
        //загоняем в потоковую строку из буфера
        std::stringstream reader(buf);
        //если успешно пишем из потока в int переменную, прекращаем цикл
        if (reader >> numb) {
            break;
        }
        //если нет, предупреждаем
        std::cout << "\nВводите цифры, а не символы!\nВводите одну из предложенных выше: ";
    }
    return numb;
}

//проверяет ввод юзера — попадает ли в нужные параметры (мин. знач, макс. знач, проверяемое значение)
//true - если попадает в значение
bool check_if_in_range(int a, int b, int answer) {
    bool flag = true;
    if (answer < a || answer > b) {
        system("cls");
        std::cout << "Вводите цифру из предложенного списка!\n" << std::endl;
        flag = false;
    }
    return flag;
}

//предлагает варианты гонок в начале игры и возвращает выбор пользователя
int greetings() {
    int number = 0;
    bool fail_status = true;
    std::string buf;
    //спрашиваем пользователя до тех пор, пока не введет правильно
    while (fail_status) {
        
        std::cout << "1. Гонка для наземного транспорта" << std::endl;
        std::cout << "2. Гонка для воздушного транспорта" << std::endl;
        std::cout << "3. Гонка для наземного и воздушного транспорта" << std::endl;
        std::cout << "Выберите тип гонки: ";
        number = check_input_if_int();
        system("cls");
        fail_status = !check_if_in_range(1, 3, number);

        
    }    
    return number;
}

//основной процесс регистрации:
//проверяет ввод пользователя, регистрирует ТС, меняет статус регистрации класса Registration
//проверяет - зареган ли участник, подходит ли по типу тс
void registration_process(Registration& reg_class) {
    //запоминает ответ юзера
    int answer;

    //для перечисления успешно зарегистрированных
    //если еще не регистрировали, то добавляем начальную сроку
    if (reg_class.get_count_reg() == 0) {
        system("cls");
        reg_class.add_info("Зарегистрированные транспортные средства: ");
    }
    //спрашиваем, пока не введет 0
    while (true) {
        //показываем тип гонки и расстояние
        std::cout << reg_class.get_race_type() << ". Расстояние: " << reg_class.get_distance() << std::endl;

        //если уже есть зареганые, показываем их
        if (reg_class.get_count_reg() > 0) {
            std::cout << reg_class.get_info_list() << std::endl;
        }
        //перечесляем список участников(их всего 7)
        for (int i = 0; i < 7; i++) {
            std::cout << i+1 <<". " << reg_class.get_ts_name(i) << std::endl;
        }
        std::cout << "0. Закончить регистрацию" << std::endl;
        std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: ";

        answer = check_input_if_int();
        //если не попадает в заданный промежуток, то выдаем список сначала
        if (!check_if_in_range(0, 7, answer)) {
            //system("cls");
            continue;
        }

        //когда ввел 0, меняем статус регистрации(если хватает участников) и выходим
        if (answer == 0) { system("cls"); reg_class.check_if_enough(reg_class.get_count_reg()); break; }

        //проверка на уже такоой же записанный тс по соответствию типа тс типу гонки
        //минус 1, потому что в списке ts класса Registration индексы идут с нуля
        switch (reg_class.if_can_to_reg(answer-1))
        {
        case 0:
            system("cls");
            std::cout << reg_class.get_ts_name(answer - 1) << " успешно зарегистрирован!" << std::endl;
            break;
        
        case 1:
            system("cls");
            std::cout << reg_class.get_ts_name(answer - 1) << " уже зарегистрирован!" << std::endl;
            break;
        case -1:
            system("cls");
            std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
            break;        
        }
    }

}


//проверка в начале регистрации и вызов основной регистрации или гонки
void call_registration_procedure_or_start(Registration& reg_class) {
    //для ответа пользователя
    int answer = 1;
    //будем повторять процесс регистрации, пока пользователь не начнет гонку
    //то есть даже если он зарегает несколько тс, нажмет 0, а потом снова нажмет 1 ("Зарегистрировать транспорт")
    //мы вернемся в регистрацию снова и продолжим регать, пока он не нажмет 0, а потом не начнет гонку
    while (answer == 1) {
        //будем спрашивать, пока пользователь не станет сотрудничать
        do {
            //system("cls");
            //если не хватает участников, то выкатываем предупреждение
            if (!reg_class.get_status()) {
                std::cout << "Должно быть зарегестрировано хотя бы 2 транспортных средства" << std::endl;
                std::cout << "1. Зарегистрировать транспорт" << std::endl;
            }
            //иначе предлагаем начать гонку
            else {
                std::cout << "1. Зарегистрировать транспорт" << std::endl;
                std::cout << "2. Начать гонку" << std::endl;
            }
            std::cout << "Выберите действие: ";
            //проверяем ввод юзера
            answer = check_input_if_int();
            //для установки границ выбора
            int range;
            //в зависимости от статуса регистрации задаем границы
            if (reg_class.get_status()) { range = 2; }//если хватает
            else { range = 1; }//если не хватает участников

            //проверяем границы ввода, если попалпрекращаем спрашивать
            if (check_if_in_range(1, range, answer)) { break; }
        } while (true);

        if (answer == 1) { system("cls"); registration_process(reg_class); }
    }
    

}


int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "Добро пожаловать в гоночный симулятор!\n";
    int go_again_or_not = 0;
    //будем крутить, пока юзер не введет 2-Выйти
    do {
        if (go_again_or_not == 1){ system("cls"); }

        //узнаем номер режим
        int numb = greetings();

        //узнаем дистанцию
        int distance;
        do {
            
            std::cout << "Укажите длину дистанции (должна быть положительна): ";
            distance = check_input_if_int();
            if (distance <= 0) {
                system("cls");
                std::cout << "Пожалуйста, следуйте указаниям!\n" << std::endl;
            }
            else { system("cls"); break; }
        } while (true);
        //регистрируем транспорт 

        //тут нужно правильно выдавать список

        //короче, надо сначала проверить состояние регистрации, и из этого предупредить, если меньше двух -- оставить один вариант
        //если участников хватает, то уже можно предлагать начать гонку

        //создаем класс регистрации и используем его для запуска регистрации
        Registration reg_class(numb, distance);
        call_registration_procedure_or_start(reg_class);
        //из регистрации выходим после ввода юзером цифры 2
        //после чего запускаем непосредственно гонку
        //создаем класс гонки и передаем в конструктор кол-во регистрантов, строку с айди ТС, расстояние
        try {
            RaceAllType race_class(reg_class.get_count_reg(), reg_class.get_id_list(), distance);
            system("cls");
            std::cout << race_class.get_result_board() << std::endl;

            /*Eagle metla;
            std::cout << metla.get_speed() << "  " << metla.get_shortcat();*/

        }
        catch (const std::runtime_error& ex) { std::cout << ex.what(); }
        catch (...) { std::cout << "Что-то пошло не так..."; }
        //спрашиваем, пока юзер не буедт сотрудничать
        do {
            std::cout << "1. Провести еще одну гонку" << std::endl;
            std::cout << "2. Выйти\nВыберите действие: ";
            go_again_or_not = check_input_if_int();
            
        } while (!check_if_in_range(1, 2, go_again_or_not));

    } while (go_again_or_not != 2);
   
   
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
