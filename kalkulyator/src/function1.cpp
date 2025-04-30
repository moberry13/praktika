#include"function1.h"
#include"SDL.h"

bool GetYesOrNo9() {
    string input;

    while (true) {
        cout << "\nХотите повторить? (yes/no): ";
        cin >> input;

        if (input == "y" || input == "yes") {
            return true;
        }
        else if (input == "n" || input == "no") {
            return false;
        }
        cout << "Ошибка! Пожалуйста, введите 'yes' или 'no': ";
    }
}

void function1() {
    setlocale(LC_ALL, "Rus");
    int numb2;
    do {
        cout << "\nРабота с функциями:\n";
        cout << "0. Выход в главное меню\n";
        cout << "1. Вычисление определенного интеграла на отрезке\n";
        cout << "2. Построение графика функции(Sdl)\n";
        cout << "3. Поиск корня Y = 0 на отрезке\n";
        cout << "4. Поиск экстремумов на отрезке\n";
        cout << "Выберите действие: \n";

        

        do {
            cout << "\nВыберите номер действия: ";
            cin >> numb2;
            
            if (numb2 < 0 || numb2 >= 5) {
                cout << "Число неподходит!!!";

            }

            if (cin.fail()) {
                cout << "Ошибка ввода! Вы ввели не число" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "\nВыберите номер действия: ";
                cin >> numb2;
            }
        } while (numb2 < 0 || numb2 >7);

        switch (numb2) {
        case 0: cout << "Выход в меню\n"; return; break;
        case 1: system("cls"); integtalfun(); break;
        case 2: system("cls"); graphici(); break;
        case 3: system("cls"); korny(); break;
        case 4: system("cls"); extremum_menu(); break;
        default: cout << "Неверный ввод\n";
        }

    } while (true);

}
