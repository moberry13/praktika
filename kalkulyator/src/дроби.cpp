#include <iostream>
#include <locale.h>
#include <sstream>
#include <string>
#include <stdexcept>
#include "zag.h"
using namespace std;


static bool GetYesOrNo3() {
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

void dec_forma() {
    char slesh;
    char znak;
    int x = 1, y = 1, k = 0;
    do {
        cout << "\nВведите дробь: ";
        cin >> x;
        cin >> slesh;
        cin >> y;
        if (cin.fail() || slesh !='/') {
            cout << "Введите обыкновенную дробь." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            x = INT_MAX;
            y = INT_MAX;
        }
        if (y == 0) cout << "Знаменатель должен быть отличен от нуля.";
        if (x == 0) cout << "Числитель должен быть отличен от нуля.";
    } while (y == INT_MAX || x== INT_MAX || x==0 || y==0);
    if (x < 0 && y < 0) {
        x = abs(x);
        y = abs(y);
    }

    if (y < 0) {
        x = -x;
        y = abs(y);
    }
    cout << "\nДесятичная форма: " << x / (y * 1.0);
}

void socrati() {
    int x=1, y=1, k = 0;
    char slesh;
    do {
        cout << "\nВведите дробь: ";
        cin >> x;
        cin >> slesh;
        cin >> y;
        if (cin.fail() || slesh != '/') {
            cout << "Введите обыкновенную дробь." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            x = INT_MAX;
            y = INT_MAX;
        }
        if (y == 0) cout << "Знаменатель должен быть отличен от нуля.\n";
        if (x == 0) cout << "Числитель должен быть отличен от нуля.\n";
    } while (y == INT_MAX || x== INT_MAX || x==0 || y==0);

    if (x < 0 && y < 0) {
        x = abs(x);
        y = abs(y);
    }

    if (y < 0) {
        x = -x;
        y = -y;
    }
    int NOD = 1;
    for (int i = 2; i < abs(x) + 1; i++) {
        if (x % i == 0 && y % i == 0) NOD = i;
    }

    int chisl = x / NOD;
    int zn = y / NOD;

    if (chisl > zn) {
        int celay = chisl / zn;
        chisl = chisl % zn;
        if (chisl == 0) cout << "Сокращенная форма: " << celay;
        else cout << "Сокращенная форма: " << celay << ' ' << chisl << '/' << zn;
    }
    else {
        if (zn == 1) cout << "Сокращенная форма: " << chisl;
        else if (chisl == 0) cout << "Сокращенная форма: " << 0;
        else cout << "Сокращенная форма: " << chisl << '/' << zn;
    }

}

void sravni() {
    int a=1, b = 1, k = 0;
    char slesh;
    do {
        cout << "\nВведите первую дробь: ";
        cin >> a;
        cin >> slesh;
        cin >> b;
        if (cin.fail() || slesh!='/') {
            cout << "Введите обыкновенную дробь." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            a = INT_MAX;
            b = INT_MAX;
        }
        if (b == 0) cout << "Знаменатель должен быть отличен от нуля.\n";
        if (a == 0) cout << "Числитель должен быть отличен от нуля.\n";
    } while (b == INT_MAX || a==0 || b==0);

    if (a < 0 && b < 0) {
        a = abs(a);
        b = abs(b);
    }

    if (b < 0) {
        a = -a;
        b = -b;
    }

    int c=1, d = 1;
    do {
        cout << "Введите вторую дробь: ";
        cin >> c;
        cin >> slesh;
        cin >> d;
        if (cin.fail() || slesh !='/') {
            cout << "Введите обыкновенную дробь." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            c = INT_MAX;
            d = INT_MAX;
        }
        if (d == 0) cout << "Знаменатель должен быть отличен от нуля.\n";
        if (c == 0) cout << "Числитель должен быть отличен от нуля.\n";
    } while (d == INT_MAX || c==0 || d==0);

    if (c < 0 && d < 0) {
        c = abs(c);
        d = abs(d);
    }

    if (d < 0) {
        c = -c;
        d = -d;
    }
    int max_zn = b;
    if (max_zn < d) max_zn = d;
    int NOK_zn = 1;
    for (int i = max_zn; i < INT_MAX; i++) {
        if (i % b == 0 && i % d == 0) {
            NOK_zn = i;
            break;
        }
    }

    int a1 = a * (NOK_zn / b);
    int b1 = b * (NOK_zn / b);
    int c1 = c * (NOK_zn / d);
    int d1 = d * (NOK_zn / d);


    if (b == 1 && d != 1) {
        if (a1 > c1) cout << "Результат сравнения: " << a << " > " << c << '/' << d;
        else if (c1 > a1) cout << "Результат сравнения: " << a << " < " << c << '/' << d;
        else cout << "Результат сравнения: " << a << " = " << c << '/' << d;
    }

    else if (d == 1 && b != 1) {
        if (a1 > c1) cout << "Результат сравнения: " << a << '/' << b << " > " << c;
        else if (c1 > a1) cout << "Результат сравнения: " << a << '/' << b << " < " << c;
        else cout << "Результат сравнения: " << a << '/' << b << " = " << c;
    }

    else if (b == 1 && d == 1) {
        if (a1 > c1) cout << "Результат сравнения: " << a << " > " << c;
        else if (c1 > a1) cout << "Результат сравнения: " << a << " < " << c;
        else cout << "Результат сравнения: " << a << " = " << c;
    }
    else {
        if (a1 > c1) cout << "Результат сравнения: " << a << '/' << b << " > " << c << '/' << d;
        else if (c1 > a1) cout << "Результат сравнения: " << a << '/' << b << " < " << c << '/' << d;
        else cout << "Результат сравнения: " << a << '/' << b << " = " << c << '/' << d;
    }
}

void razdeli() {
    int a=1, b = 1, k = 0;
    char slesh;
    do {
        cout << "Введите первую дробь: ";
        cin >> a;
        cin >> slesh;
        cin >> b;
        if (cin.fail() || slesh!='/') {
            cout << "Введите обыкновенную дробь." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            a = INT_MAX;
            b = INT_MAX;
        }
        if (b == 0) cout << "Знаменатель должен быть отличен от нуля.\n";
        if (a == 0) cout << "Числитель должен быть отличен от нуля.\n";
    } while (b == INT_MAX || a==0 || b==0);
    if (a < 0 && b < 0) {
        a = abs(a);
        b = abs(b);
    }

    if (b < 0) {
        a = -a;
        b = abs(b);
    }

    int c=0, d=0;
    do {
        cout << "Введите вторую дробь: ";
        cin >> c;
        cin >> slesh;
        cin >> d;
        if (cin.fail() || slesh != '/') {
            cout << "Ошибка ввода! Вы ввели не " << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            c = INT_MAX;
            d = INT_MAX;
        }
    } while (d == INT_MAX || c==0 || d==0);

    if (c < 0 && d < 0) {
        c = abs(c);
        d = abs(d);
    }

    if (d < 0) {
        c = -c;
        d = -d;
    }

    int x = a * d;
    int y = b * c;
    int NOD = 1;
    for (int i = 2; i < abs(x) + 1; i++) {
        if (x % i == 0 && y % i == 0) NOD = i;
    }

    int chisl = x / NOD;
    int zn = y / NOD;

    if (chisl > zn) {
        int celay = chisl / zn;
        chisl = chisl % zn;
        if (chisl == 0) cout << "Результат деления: " << celay;
        else cout << "Результат деления: " << celay << ' ' << chisl << '/' << zn;
    }
    else {
        if (zn == 1) cout << "Результат деления: " << chisl;
        else if (chisl == 0) cout << "Результат деления: " << 0;
        else cout << "Результат деления: " << chisl << '/' << zn;
    }
}

void umnozh() {
    int a=0, b = 0, k = 0;
    char slesh;
    do {
        cout << "Введите первую дробь: ";
        cin >> a;
        cin >> slesh;
        cin >> b;
        if (cin.fail() || slesh != '/') {
            cout << "Введите обыкновенную дробь." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            a = INT_MAX;
            b = INT_MAX;
        }
        if (b == 0) cout << "Знаменатель должен быть отличен от нуля.\n";
        if (a == 0) cout << "Числитель должен быть отличен от нуля.\n";
    } while (b == INT_MAX || a==0 || b==0);
    if (a < 0 && b < 0) {
        a = abs(a);
        b = abs(b);
    }

    if (b < 0) {
        a = -a;
        b = -b;
    }

    int c=0, d=0;
    do {

        cout << "Введите вторую дробь: ";
        cin >> c;
        cin >> slesh;
        cin >> d;
        if (cin.fail() || slesh != '/') {
            cout << "Введите обыкновенную дробь." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            c = INT_MAX;
            d = INT_MAX;
        }
        if (d == 0) cout << "Знаменатель должен быть отличен от нуля.\n";
        if (c == 0) cout << "Числитель должен быть отличен от нуля.\n";
    } while (d == INT_MAX || c==0 || d==0);

    if (c < 0 && d < 0) {
        c = abs(c);
        d = abs(d);
    }

    if (d < 0) {
        c = -c;
        d = -d;
    }

    int x = a * c;
    int y = b * d;
    int NOD = 1;
    for (int i = 2; i < abs(x) + 1; i++) {
        if (x % i == 0 && y % i == 0) NOD = i;
    }

    int chisl = x / NOD;
    int zn = y / NOD;

    if (chisl > zn) {
        int celay = chisl / zn;
        chisl = chisl % zn;
        if (chisl == 0) cout << "Результат умножения: " << celay;
        else cout << "Результат умножения: " << celay << ' ' << chisl << '/' << zn;
    }
    else {
        if (zn == 1) cout << "Результат умножения: " << chisl;
        else if (chisl == 0) cout << "Результат умножения: " << 0;
        else cout << "Результат умножения: " << chisl << '/' << zn;
    }

}


void slozhi() {
    int a=0, b = 0, k = 0;
    char slesh;
    do {
        cout << "\nВведите первую дробь: ";
        cin >> a;
        cin >> slesh;
        cin >> b;
        if (cin.fail() || slesh != '/') {
            cout << "Введите обыкновенную дробь." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            a = INT_MAX;
            b = INT_MAX;
        }
        if (b == 0) cout << "Знаменатель должен быть отличен от нуля.\n";
        if (a == 0) cout << "Числитель должен быть отличен от нуля.\n";
    } while (b == INT_MAX || a==0 || b==0);
    
    if (a < 0 && b < 0) {
        a = abs(a);
        b = abs(b);
    }

    if (b < 0) {
        a = -a;
        b = -b;
    }
    int c=0, d = 0;
    do {
        cout << "Введите вторую дробь: ";
        cin >> c;
        cin >> slesh;
        cin >> d;
        if (cin.fail() || slesh != '/') {
            cout << "Введите обыкновенную дробь." << endl;
            cin.clear();
            cin.ignore(10000,'\n');
            c = INT_MAX;
            d = INT_MAX;
        }
        if (d == 0) cout << "Знаменатель должен быть отличен от нуля.\n";
        if (c == 0) cout << "Числитель должен быть отличен от нуля.\n";
    } while (d == 0 || c== INT_MAX || c==0);

    if (c < 0 && d < 0) {
        c = abs(c);
        d = abs(d);
    }

    if (d < 0) {
        c = -c;
        d = -d;
    }

    int max_zn = b;
    if (max_zn < d) max_zn = d;
    int NOK_zn = 1;
    for (int i = max_zn; i < INT_MAX; i++) {
        if (i % b == 0 && i % d == 0) {
            NOK_zn = i;
            break;
        }
    }

    int a1 = a * (NOK_zn / b);
    int b1 = b * (NOK_zn / b);
    int c1 = c * (NOK_zn / d);
    int d1 = d * (NOK_zn / d);


    int x = a1 + c1;
    int y = b1;
    int NOD = 1;
    for (int i = 2; i < abs(x) + 1; i++) {
        if (x % i == 0 && y % i == 0) NOD = i;
    }

    int chisl = x / NOD;
    int zn = y / NOD;

    if (chisl > zn) {
        int celay = chisl / zn;
        chisl = chisl % zn;
        if (chisl == 0) cout << "Сумма: " << celay;
        else cout << "Сумма: " << celay << ' ' << chisl << '/' << zn;
    }
    else {
        if (zn == 1) cout << "Сумма: " << chisl;
        else if (chisl == 0) cout << "Сумма: " << 0;
        else cout << "Сумма: " << chisl << '/' << zn;
    }
}

void vichti() {
    int a=0, b = 0, k = 0;
    char slesh;
    do {
        string input;
        cout << "\nВведите первую дробь: ";
        cin >> a;
        cin >> slesh;
        cin >> b;
        if (cin.fail() || slesh != '/') {
            cout << "Введите обыкновенную дробь." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            a = INT_MAX;
            b = INT_MAX;
        }
        if (b == 0) cout << "Знаменатель должен быть отличен от нуля.\n";
        if (a == 0) cout << "Числитель должен быть отличен от нуля.\n";
    } while (b == INT_MAX || a==0 || b==0);

    if (a < 0 && b < 0) {
        a = abs(a);
        b = abs(b);
    }

    if (b < 0) {
        a = -a;
        b = -b;
    }
    int c=0, d = 0;
    do {
        string input;
        cout << "Введите вторую дробь: ";
        cin >> c;
        cin >> slesh;
        cin >> d;
        if (cin.fail() || slesh != '/') {
            cout << "Введите обыкновенную дробь." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            c = INT_MAX;
            d = INT_MAX;
        }
        if (d == 0) cout << "Знаменатель должен быть отличен от нуля.\n";
        if (c == 0) cout << "Числитель должен быть отличен от нуля.\n";
    } while (d == INT_MAX || c==0 || d==0);

    if (c < 0 && d < 0) {
        c = abs(c);
        d = abs(d);
    }

    if (d < 0) {
        c = -c;
        d = -d;
    }
    int max_zn = b;
    if (max_zn < d) max_zn = d;
    int NOK_zn = 1;
    for (int i = max_zn; i < INT_MAX; i++) {
        if (i % b == 0 && i % d == 0) {
            NOK_zn = i;
            break;
        }
    }

    int a1 = a * (NOK_zn / b);
    int b1 = b * (NOK_zn / b);
    int c1 = c * (NOK_zn / d);
    int d1 = d * (NOK_zn / d);


    int x = a1 - c1;
    int y = b1;
    int NOD = 1;
    for (int i = 2; i < abs(x) + 1; i++) {
        if (x % i == 0 && y % i == 0) NOD = i;
    }

    int chisl = x / NOD;
    int zn = y / NOD;

    if (chisl > zn) {
        int celay = chisl / zn;
        chisl = chisl % zn;
        if (chisl == 0) cout << "Сумма: " << celay;
        else cout << "Разность: " << celay << ' ' << chisl << '/' << zn;
    }
    else {
        if (zn == 1) cout << "Разность: " << chisl;
        else if (chisl == 0) cout << "Разность: " << 0;
        else cout << "Разность: " << chisl << '/' << zn;
    }
}

void drobi() {
    int number  ;
    do {
        cout << "\nКалькулятор обыкновенных дробей. \n Функции: \n 0. Выход из меню \n 1. Сложение дробей \n 2. Вычитание дробей \n 3. Умножение дробей \n 4. Деление дробей \n 5. Сравнение дробей \n 6. Сокращение дробей \n 7. Десятичная форма";
        cout << "\nПример ввода: дробь вида 7/8";
        cout << "\nВыберите номер действия: ";
        
        do {
            cout << "\nВыберите номер действия: ";
            cin >> number;

            if (number < 0 || number > 8) {
                cout << "Число не подходит";

            }

            if (cin.fail()) {
                cout << "Ошибка ввода! Вы ввели не число" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "\nВыберите номер действия: ";
                cin >> number;

            }
        } while (number < 0 || number > 8);

        switch (number) {
        case 1: system("cls"); slozhi();break;
        case 2: system("cls"); vichti(); break;
        case 3: system("cls"); umnozh(); break;
        case 4: system("cls"); razdeli();break;
        case 5: system("cls"); sravni();break;
        case 6: system("cls"); socrati(); break;
        case 7: system("cls"); dec_forma();break;
        case 0: system("cls"); cout << "Выход в главное меню\n"; return; break;
        default:
            cout << "Действия с таким номером нет";
        }

    } while (true);
}

