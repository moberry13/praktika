// func.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include"func.h"

using namespace std;

bool GetYesOrNo8() {
    string input;

    while (true) {
        cout << "\nХотите повторить? (yes/no): ";
        cin >> input;

        if (input == "y" || input == "yes") {
            system("cls");
            return true;
        }
        else if (input == "n" || input == "no") {
            system("cls");
            return false;
        }
        cout << "Ошибка! Пожалуйста, введите 'yes' или 'no': ";
    }
}

void search_min_max_of_ln() {
    do {
        double a, b, c;
        int x1, x2;
        cout << "y = a * ln(b * x) + c, x in [x1;x2]\n";
        cout << "a = "; cin >> a;
        cout << "b = "; cin >> b;
        cout << "c = "; cin >> c;
        cout << "x1 = "; cin >> x1;
        cout << "x2 = "; cin >> x2;

        if (a == 0 || b == 0 || x1 >= x2) cout << "Ошибка ввода значений.\n";
        else {
            if (b * x1 > 0) {
                double maxx = a * log(b * x1) + c;
                double minn = a * log(b * x1) + c;
                for (int i = x1 + 1; i <= x2; i++) {
                    if ((a * log(b * i) + c) > maxx && b * i > 0) maxx = a * log(b * i) + c;
                    if ((a * log(b * i) + c) < minn && b * i > 0) minn = a * log(b * i) + c;
                }
                cout << "Минимум: " << minn << endl;
                cout << "Максимум: " << maxx << endl;
            }
            else cout << "Функция не определена на данном отрезке.\n";
        }
    } while (GetYesOrNo8());
}

void search_min_max_of_sin() {
    do {
        double a, b, c, d;
        int x1, x2;
        cout << "y = a * sin(b * x + c) + d, x in [x1;x2]\n";
        cout << "a = "; cin >> a;
        cout << "b = "; cin >> b;
        cout << "c = "; cin >> c;
        cout << "d = "; cin >> d;
        cout << "x1 = "; cin >> x1;
        cout << "x2 = "; cin >> x2;

        if (a == 0 || x1 >= x2) cout << "Ошибка ввода значений.\n";
        else {
            double minn = a * sin(b * x1 + c) + d;
            double maxx = a * sin(b * x1 + c) + d;
            for (int i = x1 + 1; i <= x2; i++) {
                if ((a * sin(b * i + c) + d) < minn) minn = a * sin(b * i + c) + d;
                if ((a * sin(b * i + c) + d) > maxx) maxx = a * sin(b * i + c) + d;
            }
            cout << "Минимум: " << minn << endl;
            cout << "Максимум: " << maxx << endl;
        }
    } while (GetYesOrNo8());
}

 void search_min_max_of_cos() {
    do {
        double a, b, c, d;
        int x1, x2;
        cout << "y = a * cos(b * x + c) + d, x in [x1;x2]\n";
        cout << "a = "; cin >> a;
        cout << "b = "; cin >> b;
        cout << "c = "; cin >> c;
        cout << "d = "; cin >> d;
        cout << "x1 = "; cin >> x1;
        cout << "x2 = "; cin >> x2;

        if (a == 0 || x1 >= x2) cout << "Ошибка ввода значений.\n";
        else {
            double minn = a * cos(b * x1 + c) + d;
            double maxx = a * cos(b * x1 + c) + d;
            for (int i = x1 + 1; i <= x2; i++) {   
                if ((a * cos(b * i + c) + d) < minn) minn = a * cos(b * i + c) + d;
                if ((a * cos(b * i + c) + d) > maxx) maxx = a * cos(b * i + c) + d;
            }
            cout << "Минимум: " << minn << endl;
            cout << "Максимум: " << maxx << endl;
        }
    } while (GetYesOrNo8());
}

void search_min_max_of_step() {
    do {
        double a, b, c;
        int x1, x2;
        cout << "y = a * x^b + c, x in [x1;x2]\n";
        cout << "a = "; cin >> a;
        cout << "b = "; cin >> b;
        cout << "c = "; cin >> c;
        cout << "x1 = "; cin >> x1;
        cout << "x2 = "; cin >> x2;

        if (a == 0 || x1 >= x2) cout << "Ошибка ввода значений.\n";
        else {
            double minn = a * pow(x1, b) + c;
            double maxx = a * pow(x1, b) + c;
            for (int i = x1 + 1; i <= x2; i++) {
                if ((a * pow(i, b) + c) < minn) minn = a * pow(i, b) + c;
                if ((a * pow(i, b) + c) > maxx) maxx = a * pow(i, b) + c;
            }
            cout << "Минимум: " << minn << endl;
            cout << "Максимум: " << maxx << endl;
        }
    } while (GetYesOrNo8());
}

void search_min_max_of_pok() {
    do {
        double a, b, c, d;
        int x1, x2;
        cout << "y = a * b^(c * x) + d, x in [x1;x2]\n";
        cout << "a = "; cin >> a;
        cout << "b = "; cin >> b;
        cout << "c = "; cin >> c;
        cout << "d = "; cin >> d;
        cout << "x1 = "; cin >> x1;
        cout << "x2 = "; cin >> x2;

        if (a == 0 || x1 >= x2) cout << "Ошибка ввода значений.\n";
        else {
            double minn = a * pow(b, c * x1) + d;
            double maxx = a * pow(b, c * x1) + d;
            for (int i = x1 + 1; i < x2; i++) {
                if ((a * pow(b, c * i) + d) < minn) minn = a * pow(b, c * i) + d;
                if ((a * pow(b, c * i) + d) > maxx) maxx = a * pow(b, c * i) + d;
            }
            cout << "Минимум: " << minn << endl;
            cout << "Максимум: " << maxx << endl;
        }
    } while (GetYesOrNo8());
}

void search_min_max_of_polinom() {
    do {
        cout << "y = a0 + a1 * x + a2 * x^2 + ... + aN * x^N, x in [x1;x2]\n";
        int N, x1, x2;
        cout << "x1 = "; cin >> x1;
        cout << "x2 = "; cin >> x2;
        cout << "Степень полинома: "; cin >> N;
        if (N > 0 && x1 < x2) {
            double* a = (double*)malloc(N * sizeof(double));
            double minn = 0, maxx = 0;
            for (int i = 0; i < N; i++) {
                cout << "a" << i << " = "; cin >> a[i];
                minn += a[i] * pow(x1, i);
                maxx += a[i] * pow(x1, i);
            }
            for (int i = x1 + 1; i < x2; i++) {
                double s = 0;
                for (int j = 0; j < N; j++) {
                    s += a[j] + pow(i, j);
                }
                if (s < minn) minn = s;
                if (s > maxx) maxx = s;
            }
            cout << "Минимум: " << minn << endl;
            cout << "Максимум: " << maxx << endl;
        }
    } while (GetYesOrNo8());
}

void extremum_menu() {
    int number2;
    do {
        cout << "Поиск экстремумов на отрезке.\n";
        cout << "Функции:\n";
        cout << "0. Вернуться в главное меню\n";
        cout << "1. Полином степени N\n";
        cout << "2. Степенная\n";
        cout << "3. Показательная\n";
        cout << "4. Логарифмическая\n";
        cout << "5. Синусоида\n";
        cout << "6. Косинусоида\n";
        cout << "Выберите номер действия: ";
        cin >> number2;


        do {
            cout << "\nВыберите номер действия: ";
            cin >> number2;

            if (number2 < 0 || number2 > 7) {
                cout << "Число не подходит";

            }

            if (cin.fail()) {
                cout << "Ошибка ввода! Вы ввели не число" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "\nВыберите номер действия: ";
                cin >> number2;

            }
        } while (number2 < 0 || number2 > 7);

        switch (number2) {
        case 0: { system("cls"); cout << "Выход в меню"; return; break; }
        case 1: { system("cls"); search_min_max_of_polinom(); break; }
        case 2: { system("cls"); search_min_max_of_step(); break; }
        case 3: { system("cls"); search_min_max_of_pok(); break; }
        case 4: { system("cls"); search_min_max_of_ln(); break; }
        case 5: { system("cls"); search_min_max_of_sin(); break; }
        case 6: { system("cls"); search_min_max_of_cos(); break; }
        default: { cout << "Ошибка ввода.\n\n"; break; }
        }
    } while (true);
}

