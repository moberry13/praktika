// интегралы.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
#include <math.h>
#include <cmath>
#include "integral.h"

bool GetYesOrNo10() {
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

void stepen() {
    cout << "Определённый интеграл степенной функции: a*x^b+c\n";
    double a = 0, b = -1, c = 0, x1 = 0, x2 = 0;
    do {
        cout << "\nВведите а: ";
        cin >> a;
        if (cin.fail()) {
            cout << "Ошибка ввода! Вы ввели не число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            a = INT_MAX;
        }
    } while (a == INT_MAX);
    int check = 0;
    do {
        if (check > 0) cout << "b не может быть равно -1 \n";
        cout << "Введите b: ";
        cin >> b;
        if (cin.fail()) {
            cout << "Ошибка ввода! Вы ввели не число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            b = -1;
        }
        else check++;
    } while (b == -1);
    do {
        cout << "Введите c: ";
        cin >> c;
        if (cin.fail()) {
            cout << "Ошибка ввода! Вы ввели не число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            c = INT_MAX;
        }
    } while (c == INT_MAX);
    do {
        cout << "Введите нижний предел: ";
        cin >> x1;
        if (cin.fail()) {
            cout << "Ошибка ввода! Вы ввели не число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            x1 = INT_MAX;
        }
    } while (x1 == INT_MAX);
    do {
        cout << "Введите верхний предел: ";
        cin >> x2;
        if (cin.fail()) {
            cout << "Ошибка ввода! Вы ввели не число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            x2 = INT_MAX;
        }
    } while (x2 == INT_MAX);
    double integral;
    integral = a * (pow(x2, b + 1)) / (b + 1) + c * x2 - a * (pow(x1, b + 1)) / (b + 1) - c * x1;
    cout << "Результат: " << integral;
}

void pokazatel() {
    cout << "Определённый интеграл показательной функции: a*b^(c*x)+d";
    
    double a=0, b, c, d=0, x1=0, x2=0;
    do {
        cout << "\nВведите а: ";
        cin >> a;
        if (cin.fail()) {
            cout << "Ошибка ввода! Вы ввели не число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            a = INT_MAX;
        }
    } while (a == INT_MAX);
    int check = 0;
    do {
        if (check > 0) cout << "b не может быть равно 1 \n";
        cout << "Введите b: ";
        cin >> b;
        if (cin.fail()) {
            cout << "Ошибка ввода! Вы ввели не число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            b = 1;
        }
        else check++;
    } while (b == 1);
    check = 0;
    do {
        if (check > 0) cout << "b не может быть равно 0 \n";
        cout << "Введите c: ";
        cin >> c;
        if (cin.fail()) {
            cout << "Ошибка ввода! Вы ввели не число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            c = 0;
        }
        else check++;
    } while (c == 0);
    do {
        cout << "Введите d: ";
        cin >> d;
        if (cin.fail()) {
            cout << "Ошибка ввода! Вы ввели не число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            d = INT_MAX;
        }
    } while (d == INT_MAX);
    do {
        cout << "Введите нижний предел: ";
        cin >> x1;
        if (cin.fail()) {
            cout << "Ошибка ввода! Вы ввели не число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            x1 = INT_MAX;
        }
    } while (x1 == INT_MAX);
    do {
        cout << "Введите верхний предел: ";
        cin >> x2;
        if (cin.fail()) {
            cout << "Ошибка ввода! Вы ввели не число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            x2 = INT_MAX;
        }
    } while (x2 == INT_MAX);
    double integral;
    integral = a * (pow(b, c * x2)) / (c * log(b)) + d * x2 - a * (pow(b, c * x1)) / (c * log(b)) - d * x1;
    cout << "Результат: " << integral;
}

void logarifm() { 
    cout << "Определённый интеграл логарифмической функции: a*ln(b*x)+c";
    double a=0, b, c=0, d, x1, x2;
    do {
        cout << "\nВведите а: ";
        cin >> a;
        if (cin.fail()) {
            cout << "Ошибка ввода! Вы ввели не число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            a = INT_MAX;
        }
    } while (a == INT_MAX);
    int check = 0;
    do {
        if (check > 0) cout << "b не может быть отрицательным \n";
        cout << "Введите b: ";
        cin >> b;
        if (cin.fail()) {
            cout << "Ошибка ввода! Вы ввели не число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            b = -1;
        }
        else check++;
    } while (b == -1);
    check = 0;
    do {
        cout << "Введите c: ";
        cin >> c;
        if (cin.fail()) {
            cout << "Ошибка ввода! Вы ввели не число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            c = INT_MAX;
        }
    } while (c == INT_MAX);
    do {
        cout << "Введите d: ";
        cin >> d;
        if (cin.fail()) {
            cout << "Ошибка ввода! Вы ввели не число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            d = INT_MAX;
        }
    } while (d == INT_MAX);
    do {
        if (check > 0) cout << "Нижний предел не может быть отрицательным\n";
        cout << "Введите нижний предел: ";
        cin >> x1;
        if (cin.fail()) {
            cout << "Ошибка ввода! Вы ввели не число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            x1 = -1;
        }
        else check++;
    } while (x1 <0);
    check = 0;
    do {
        if (check > 0) cout << "Верхний предел не может быть отрицательным\n";
        cout << "Введите верхний предел: ";
        cin >> x2;
        if (cin.fail()) {
            cout << "Ошибка ввода! Вы ввели не число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            x2 = -1;
        }
    } while (x2 < 0);
    double integral;
    integral = a * x2 * log(x2) + (a * log(b) + c - a) * x2 - a * x1 * log(x1) - (a * log(b) + c - a) * x1;
    cout << "Результат: " << integral;
}

void sinycoida() {
    cout << "Определённый интеграл синусоиды: a*sin(b*x+c)+d";
    double a=INT_MAX, b=0, c=INT_MAX, d, x1, x2;
    do {
        cout << "\nВведите а: ";
        cin >> a;
        if (cin.fail()) {
            cout << "Ошибка ввода! Вы ввели не число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            a = INT_MAX;
        }
    } while (a == INT_MAX);
    int check = 0;
    do {
        if (check > 0) cout << "b не может быть равно нулю \n";
        cout << "Введите b: ";
        cin >> b;
        if (cin.fail()) {
            cout << "Ошибка ввода! Вы ввели не число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            b = 0;
        }
        else check++;
    } while (b == 0);
    do {
        cout << "Введите c: ";
        cin >> c;
        if (cin.fail()) {
            cout << "Ошибка ввода! Вы ввели не число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            c = INT_MAX;
        }
    } while (c == INT_MAX);
    do {
        cout << "Введите d: ";
        cin >> d;
        if (cin.fail()) {
            cout << "Ошибка ввода! Вы ввели не число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            d = INT_MAX;
        }
    } while (d == INT_MAX);
    do {
        cout << "Введите нижний предел: ";
        cin >> x1;
        if (cin.fail()) {
            cout << "Ошибка ввода! Вы ввели не число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            x1 = INT_MAX;
        }
    } while (x1 == INT_MAX);
    do {
        cout << "Введите верхний предел: ";
        cin >> x2;
        if (cin.fail()) {
            cout << "Ошибка ввода! Вы ввели не число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            x2 = INT_MAX;
        }
    } while (x2 == INT_MAX);

    double integral;

    integral = d * x2 - (a * cos((b * x2 + c))) / b - d * x1 + (a * cos((b * x1 + c))) / b;
    cout << "Результат: " << integral;
}

void cosinysoida() {
    cout << "Определённый интеграл косинусоиды: a*cos(b*x+c)+d";
    double a, b, c, d, x1, x2;
    do {
        cout << "\nВведите а: ";
        cin >> a;
        if (cin.fail()) {
            cout << "Ошибка ввода! Вы ввели не число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            a = INT_MAX;
        }
    } while (a == INT_MAX);
    int check = 0;
    do {
        if (check > 0) cout << "b не может быть равно нулю \n";
        cout << "Введите b: ";
        cin >> b;
        if (cin.fail()) {
            cout << "Ошибка ввода! Вы ввели не число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            b = 0;
        }
        else check++;
    } while (b == 0);
    do {
        cout << "Введите c: ";
        cin >> c;
        if (cin.fail()) {
            cout << "Ошибка ввода! Вы ввели не число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            c = INT_MAX;
        }
    } while (c == INT_MAX);
    do {
        cout << "Введите d: ";
        cin >> d;
        if (cin.fail()) {
            cout << "Ошибка ввода! Вы ввели не число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            d = INT_MAX;
        }
    } while (d == INT_MAX);
    do {
        cout << "Введите нижний предел: ";
        cin >> x1;
        if (cin.fail()) {
            cout << "Ошибка ввода! Вы ввели не число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            x1 = INT_MAX;
        }
    } while (x1 == INT_MAX);
    do {
        cout << "Введите верхний предел: ";
        cin >> x2;
        if (cin.fail()) {
            cout << "Ошибка ввода! Вы ввели не число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            x2 = INT_MAX;
        }
    } while (x2 == INT_MAX);

    double integral;

    integral = (a * sin((b * x2 + c))) / b + d * x2 - (a * sin((b * x1 + c))) / b - d * x1;
    cout << "Результат: " << integral;
}

double integralotx(double* a, int N, double x) {
    double res=0;
    for (int i = 0; i < N; i++) {
        res += a[i] * ((pow(x, i + 1)) / (i + 1));
    }
    return res;
}

void integral() {
    cout << "Определённый интеграл полинома степени N: a0+a1*x+a2*x^2+...+aN*x^N";
    int N;
    int check = 0;
    do {
        if (check > 0) cout << "Введите положительное число\n";
        cout << "\nВведите максимальную степень N: ";
        cin >> N;
        if (cin.fail()) {
            cout << "Ошибка ввода! Вы ввели не число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            N = -1;
        }
        else check++;
    } while (N < 0);
    double* a;
    a = (double*)malloc((N+1) * sizeof(double));
    for (int i = 0; i < N+1; i++) {
        do {
            cout << "Введите a" << i << ": ";
            cin >> a[i];
            if (cin.fail()) {
                cout << "Ошибка ввода! Вы ввели не число." << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                a[i] = INT_MAX;
            }
        } while (a[i] == INT_MAX);
    }
    double integral;
    double x1, x2;
    do {
        cout << "Введите нижний предел: ";
        cin >> x1;
        if (cin.fail()) {
            cout << "Ошибка ввода! Вы ввели не число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            x1 = INT_MAX;
        }
    } while (x1 == INT_MAX);
    do {
        cout << "Введите верхний предел: ";
        cin >> x2;
        if (cin.fail()) {
            cout << "Ошибка ввода! Вы ввели не число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            x2 = INT_MAX;
        }
    } while (x2 == INT_MAX);
    integral = integralotx(a, (N+1), x2) - integralotx(a, (N+1), x1);
    cout << "Результат: " << integral;
}

void integtalfun() {
    int num12;
    do {
        cout << "Вычисление определённого интеграла на отрезке. \n Функции: \n 0. Выход в главное меню \n 1. Cтепенная функция: a*x^b+c \n 2. Показательная функция: a*b^(c*x)+d \n 3. Логарифмическая функция: a*ln(b*x)+c \n 4. Синусоида: a*sin(b*x+c)+d \n 5. Косинусоида: a*cos(b*x+c)+d \n 6. Полином степени N: a0+a1*x+a2*x^2+...+aN*x^N";
        do {
            cout << "\nВыберите номер действия: ";
            cin >> num12;
            if (cin.fail()) {
                cout << "Ошибка ввода! Вы ввели не число." << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "\nВыберите номер действия: ";
                cin >> num12;
            }
        } while (num12 < 0 || num12 > 7);


        switch (num12) {
        case 0: system("cls"); cout << "Выход в меню\n"; return; break;
        case 1:
            do {
                stepen();
            } while (GetYesOrNo10());
            break;
        case 2:
            do {
                pokazatel();
            } while (GetYesOrNo10());
            break;
        case 3:
            do {
                logarifm();
            } while (GetYesOrNo10());

            break;
        case 4:
            do {
                sinycoida();
            } while (GetYesOrNo10());

            break;
        case 5:
            do {
                cosinysoida();
            } while (GetYesOrNo10());
            break;
        case 6:
            do {
                integral();
            } while (GetYesOrNo10());
            break;
        default:
            cout << "Функции с таким номером нет";

        }
    } while (num12 != 0);
}
