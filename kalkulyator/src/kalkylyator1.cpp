#include<iostream>
#include"mnogochleni.h"
#include"zag.h"
#include"matrice.h"
#include"kooombi.h"
#include"teer.h"
#include"function1.h"
#define SDL_MAIN_HANDLED
#include"SDL.h"

bool GetYesOrNo7() {
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

int main() {
    setlocale(LC_ALL, "RUS");
    int num ;

    do {
        cout << "0. Выход\n";
        cout << "1. Матричный калькулятор\n";
        cout << "2. Калькулятор обыкновенных дробей\n";
        cout << "3. Многочлены\n";
        cout << "4. Калькулятор форм комбинаторики\n";
        cout << "5. Теория вероятности и мат. статистика\n";
        cout << "6. Работа с функциями\n";     

        do {

            cout << "\nВыберите номер действия: ";
            cin >> num;


            if (num < 0 || num > 7) {
                cout << "Число не подходит";
            }

            if (cin.fail()) {
                cout << "Ошибка ввода! Вы ввели не число" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "\nВыберите номер действия: ";
                cin >> num;
            }
        } while (num < 0 || num > 7);



        switch (num) {
        case 0: cout << "Выход\n"; return 0; break;
        case 1: system("cls"); MatriceOperation(); break;
        case 2: system("cls"); drobi(); break;
        case 3: system("cls"); mnog_menu(); break;
        case 4: system("cls"); kombinator(); break;
        case 5: system("cls"); TerVer_MatStat();break;
        case 6: system("cls"); function1(); break;
        default: cout << "Неверный ввод\n";
        }
        
    } while (true);

    return 0;
}