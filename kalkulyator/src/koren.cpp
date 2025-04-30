#include <iostream>
#include <locale>
#include <malloc.h>
#include <cmath>
#include "korrren.h"
using namespace std;

double x;
int n1;
double* Znacheniapolinoma;
double a, b;

double A_step, B_step, C_step, D_step;
double B_sin, C_sin, D_sin, A_sin;
double A_cos, B_cos, C_cos, D_cos;
double podshett_polinom(double chislo);
double podshett_stepennoy(double chislo);

void korny() {
    int deistvie1;
    do {
        cout << "\n\nПоиск корней y=0 на отрезке.\nФунции:\n0. Вернуться в глаавное меню\n1. Полином степени N: a0+a1*x+a2*x^2+...aN*x^N" <<
            "\n2. Степенная: A*x^B+C\n3. Показательная: A*B^(C*x)+D\n4. Логарифмическая: A*ln(B*x)+C\n5. Синусоида: A*sin(B*x+C)+D" <<
            "\n6. Косинусоида: A*cos(B*x+C)+D\n ";
        cout << "Предупреждение! Нахождение корней осуществляется по методу бисекций(дитохомии),где главным условием является разность знака функций на концах выбранного вами отрезка. В соответсвии с эим выбирайте начало и конец отрезка внимательней.\n";
        do {
            cout << "\nВыберите номер действия: ";
            cin >> deistvie1;
         

            if (deistvie1 < 0 || deistvie1 > 7) {
                cout << "Число не подходит";
            }  
            
            if (cin.fail()|| deistvie1 < 0 || deistvie1 > 7) {
                cout << "Ошибка ввода! Вы ввели не число" << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "\nВыберите номер действия: ";
                cin >> deistvie1;
            }
        } while (deistvie1 < 0 || deistvie1 > 7);

      

        switch (deistvie1) {
        case 0: cout << "Выход в меню"; return; break;
        case 1:
            system("cls");
            polinom();
            break;
        case 2:
            system("cls");
            stepennaya();
            break;
        case 3:
            system("cls");
            pokazatelnaya();
            break;
        case 4:
            system("cls");
            logarifmisheskaya();
            break;
        case 5:
            system("cls");
            sinusoidnaya();
            break;
        case 6:
            system("cls");
            kosinusoida();
            break;
        default:cout << "Действия с выбранным номером нет.";
        }
    } while (true);


}

bool GetYesOrNo12() {
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

void vvod_a_b() {
    cout << "Введите значения границы отрезка, где a = "; cin >> a; cout << "b = "; cin >> b;
}

void metod_bisektsii(double a, double b, double (*func)(double)) {
    const double toshnost = 1e-6;
    const int Maximalnoe_Kolvo_vichisleniy = 10000;
    double c;

    double fa = func(a);
    double fb = func(b);

    //cout << "f(a) = " << fa << endl;
    //cout << "f(b) = " << fb << endl;

    if (fa * fb >= 0) {
        cout << "\nФункция должна иметь разные знаки на концах отрезка!";
        return;
    }

    for (int i = 0; i < Maximalnoe_Kolvo_vichisleniy; i++) {
        c = (a + b) / 2;
        double fc = func(c);

        if (abs(fc) < toshnost || (b - a) / 2 < toshnost) {
            cout << "Найден корень: x = " << c << endl;
            return;
        }

        if (fc * fa < 0) {
            b = c;
            fb = fc;
        }
        else {
            a = c;
            fa = fc;
        }
    }

    cout << "Достигнуто максимальное количество итераций" << endl;
}

void findAllKorny(double start, double end, double (*func)(double), int segments) {
    double step = (end - start) / segments;
    double fa = func(start);
    double fb = func(end);
    if (fa * fb >= 0) {
        cout << "Функция не меняет знак на отрезке [" << start << ", " << end << "]\n";
        return;
    }

    for (int i = 0; i < segments; ++i) {
        double segment_start = start + i * step;
        double segment_end = segment_start + step;

        double fa = func(segment_start);
        double fb = func(segment_end);

        if (fa * fb < 0) {
            metod_bisektsii(segment_start, segment_end, func);
        }
    }
}

void vvod_chisel(double a) {
    while (!(cin >> a) || a <= 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Ошибка! Введите положительное целое число: ";
    }

}

double vozvedenie_v_stepen(double osnovanie, int stepen) {
    if (stepen == 0) return 1;
    if (stepen == 1) return osnovanie;
    double half = vozvedenie_v_stepen(osnovanie, stepen / 2);
    if (stepen % 2 == 0)
        return half * half;
    else
        return half * half * osnovanie;
}

double podshett_polinom(double chislo) {
    double sum = 0.0;
    for (int i = 0; i <= n1; i++) {
        sum += Znacheniapolinoma[i] * vozvedenie_v_stepen(chislo, i);
    }
    return sum;
}

double podshett_stepennoy(double chislo) {
    return A_step * vozvedenie_v_stepen(chislo, B_step) + C_step;
}

double podshett_pokazatelnoy(double chislo) {
    return A_step * pow(B_step, C_step * chislo) + D_step;
}

double podshett_logarifmichesok(double chislo) {
    if (chislo * B_step <= 0) {
        cout << "Логарифм не определен при x = " << chislo << endl;
        return 0;
    }
    return A_step * log(B_step * chislo) + C_step;
}

double podshett_sinusoidnaya(double chislo) {
    return A_sin * sin(B_sin * chislo + C_sin) + D_sin;
}


double podshett_kosinusoida(double chislo) {
    return A_cos * cos(B_cos * chislo + C_cos) + D_cos;
}

void polinom() {
    do
    {


        do {
            cout << "\nВведите степень полинома n = ";
            cin >> n1;
            if (n1 <= 0) {
                cout << "Степень полинома должна быть положительной\n";
            }
        } while (n1 <= 0);

        delete[] Znacheniapolinoma;
        Znacheniapolinoma = new double[n1 + 1];

        cout << "Введите коэффициенты полинома:\n";
        for (int i = 0; i < n1 + 1; i++) {
            cout << "a[" << i << "] = ";
            cin >> Znacheniapolinoma[i];
        }
        vvod_a_b();
        findAllKorny(a, b, podshett_polinom);
    } while (GetYesOrNo12());
}

void stepennaya() {
    do
    {
        cout << "Введите значения для степенной функции:\nA = "; vvod_chisel(A_step);
        cout << "B = "; vvod_chisel(B_step);
        cout << "C = "; vvod_chisel(C_step);
        vvod_a_b();
        findAllKorny(a, b, podshett_stepennoy);
    } while (GetYesOrNo12());
}

void pokazatelnaya() {
    do
    {
        cout << "Введите значения для показательной функции:\nA = "; cin >> A_step;
        cout << "B = "; cin >> B_step;
        cout << "C = "; cin >> C_step;
        cout << "D = "; cin >> D_step;
        vvod_a_b();
        findAllKorny(a, b, podshett_pokazatelnoy);
    } while (GetYesOrNo12());
}

void logarifmisheskaya() {
    do
    {
        cout << "Введите значения для показательной функции:\nA = "; cin >> A_step;
        cout << "B = "; cin >> B_step;
        cout << "C = "; cin >> C_step;
        vvod_a_b();
        findAllKorny(a, b, podshett_logarifmichesok);
    } while (GetYesOrNo12());
}


void sinusoidnaya() {
    do
    {

        cout << "Введите значения для синусоиды:\nA = "; cin >> A_sin;
        cout << "B = "; cin >> B_sin;
        cout << "C = "; cin >> C_sin;
        cout << "D = "; cin >> D_sin;
        vvod_a_b();
        findAllKorny(a, b, podshett_sinusoidnaya, 10000);
    } while (GetYesOrNo12());
}

void kosinusoida() {
    do
    {

        cout << "Введите значения для косинусоиды:\nA = "; cin >> A_cos;
        cout << "B = "; cin >> B_cos;
        cout << "C = "; cin >> C_cos;
        cout << "D = "; cin >> D_cos;
        vvod_a_b();
        findAllKorny(a, b, podshett_kosinusoida, 10000);
    } while (GetYesOrNo12());

}