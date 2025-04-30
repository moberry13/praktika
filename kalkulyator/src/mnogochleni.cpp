// mnogochleni.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include"mnogochleni.h"


using namespace std;

struct mnog {
    int deg;
    double* coeffs;
};

bool GetYesOrNo6() {
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


mnog create_mnog(int deg) {
    mnog p;
    p.deg = deg;
    p.coeffs = (double*)malloc((deg + 1) * sizeof(double));
    cout << "Введите множители при х:\n";
    for (int i = deg; i >= 0; i--) {
        cout << "x^" << i << " = ";
        cin >> p.coeffs[i];
    }
    return p;
}

void out_mnog(mnog p) {
    bool first = 1;
    for (int i = p.deg; i >= 0; i--) {
        if (p.coeffs[i] == 0) continue;
        if (!first && p.coeffs[i] > 0) cout << " + ";
        else if (!first && p.coeffs[i] < 0) cout << " - ";
        if (i == 0 || abs(p.coeffs[i]) != 1) cout << abs(p.coeffs[i]);
        if (i > 1) cout << "x^" << i;
        if (i == 1) cout << "x";
        first = 0;
    }
}

void check_deg(int deg) {
    if (deg <= 0) {
        cout << "Ошибка ввода значений.\n";
        exit(1);
    }
}

void sum_mnogs() {
    int deg1, deg2;
    cout << "Степень первого многочлена: "; cin >> deg1; check_deg(deg1);
    mnog m1 = create_mnog(deg1);
    cout << "Степень второго многочлена: "; cin >> deg2; check_deg(deg2);
    mnog m2 = create_mnog(deg2);
    mnog res;
    res.coeffs = (double*)malloc((max(deg1, deg2) + 1) * sizeof(double));
    for (int i = 0; i <= min(deg1, deg2); i++) res.coeffs[i] = m1.coeffs[i] + m2.coeffs[i];
    if (deg1 > deg2) { res.deg = deg1; for (int i = deg2 + 1; i <= deg1; i++) res.coeffs[i] = m1.coeffs[i]; }
    else { res.deg = deg2; for (int i = deg1 + 1; i <= deg2; i++) res.coeffs[i] = m2.coeffs[i]; }
    out_mnog(res);
    free(m1.coeffs);
    free(m2.coeffs);
    free(res.coeffs);
}

void minus_mnogs() {
    int deg1, deg2;
    cout << "Степень первого многочлена: "; cin >> deg1; check_deg(deg1);
    mnog m1 = create_mnog(deg1);
    cout << "Степень второго многочлена: "; cin >> deg2; check_deg(deg2);
    mnog m2 = create_mnog(deg2);
    mnog res;
    res.coeffs = (double*)malloc((max(deg1, deg2) + 1) * sizeof(double));
    for (int i = 0; i <= min(deg1, deg2); i++) res.coeffs[i] = m1.coeffs[i] - m2.coeffs[i];
    if (deg1 > deg2) { res.deg = deg1; for (int i = deg2 + 1; i <= deg1; i++) res.coeffs[i] = m1.coeffs[i]; }
    else { res.deg = deg2; for (int i = deg1 + 1; i <= deg2; i++) res.coeffs[i] = m2.coeffs[i]; }
    out_mnog(res);
    free(m1.coeffs);
    free(m2.coeffs);
    free(res.coeffs);
}

void proizv_mnogs() {
    int deg1, deg2;
    cout << "Степень первого многочлена: "; cin >> deg1; check_deg(deg1);
    mnog m1 = create_mnog(deg1);
    cout << "Степень второго многочлена: "; cin >> deg2; check_deg(deg2);
    mnog m2 = create_mnog(deg2);
    mnog res;
    res.deg = deg1 * deg2;
    res.coeffs = (double*)malloc((deg1 * deg2 + 1) * sizeof(double));
    for (int i = 0; i < deg1 * deg2 + 1; i++) res.coeffs[i] = 0.0;
    for (int i = 0; i <= deg1; i++) {
        for (int j = 0; j <= deg2; j++) {
            res.coeffs[i + j] += m1.coeffs[i] * m2.coeffs[j];
        }
    }
    out_mnog(res);
    free(m1.coeffs);
    free(m2.coeffs);
    free(res.coeffs);
}

void proizv_mnog_num() {
    int deg;
    double num;
    cout << "Степень многочлена: "; cin >> deg; check_deg(deg);
    mnog m = create_mnog(deg);
    cout << "Число, на которое нужно умножить многочлен: "; cin >> num;
    for (int i = 0; i <= deg; i++) m.coeffs[i] *= num;
    out_mnog(m);
    free(m.coeffs);
}

void del_mnogs_stolbik() {
    int deg1, deg2;
    cout << "Степень первого многочлена: "; cin >> deg1; check_deg(deg1);
    mnog m1 = create_mnog(deg1);
    cout << "Степень второго многочлена: "; cin >> deg2; check_deg(deg2);
    mnog m2 = create_mnog(deg2);
    mnog res;
    res.deg = deg1 - deg2;
    res.coeffs = (double*)malloc((deg1 - deg2 + 1) * sizeof(double));
    for (int i = 0; i <= deg1 - deg2; i++) res.coeffs[i] = 0.0;
    out_mnog(m1); cout << " | "; out_mnog(m2); cout << endl;
    for (int i = deg1; i >= deg2; i--) {
        res.coeffs[i - deg2] = m1.coeffs[i] / m2.coeffs[deg2];
        int cnt = 0;
        for (int j = i; j >= (deg1 - deg2); j--) {
            m1.coeffs[j] -= res.coeffs[i - deg2] * m2.coeffs[deg2 - cnt];
            cnt++;
        }
        out_mnog(m1); cout << " | "; out_mnog(res); cout << endl;
    }
    cout << "Результат деления: ("; out_mnog(res); cout << ") * ("; out_mnog(m2); cout << ") + ("; out_mnog(m1); cout << ").\n";
}

void proizvodnaya_mnog() {
    int deg;
    cout << "Степень многочлена: "; cin >> deg; check_deg(deg);
    mnog m = create_mnog(deg);
    mnog res;
    res.deg = m.deg - 1;
    res.coeffs = (double*)malloc((res.deg + 1) * sizeof(double));
    for (int i = 1; i <= deg; i++) res.coeffs[i - 1] = m.coeffs[i] * i;
    out_mnog(res);
}

void mnog_menu() {
    int numbr;
    do {
        cout << "\nКалькулятор многочленов.\n";
        cout << "Функции:\n";
        cout << "0. Вернуться в главное меню\n";
        cout << "1. Сложение многочленов\n";
        cout << "2. Вычитание многочленов\n";
        cout << "3. Умножение многочленов\n";
        cout << "4. Умножение многочлена на число\n";
        cout << "5. Деление многочленов в столбик\n";
        cout << "6. Вычисление производной от многочлена\n";
       

        do {
            cout << "\nВыберите номер деxxйствия: ";
            cin >> numbr;

            if (numbr < 0 || numbr > 7) {
                cout << "Число не подходит";

            }

            if (cin.fail()) {
                cout << "Ошибка ввода! Вы ввели не число" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "\nВыберите номер действия: ";
                cin >> numbr;

            }
        } while (numbr < 0 || numbr > 7);
        
    
        switch (numbr) {
        case 0: cout << "Выход в меню\n"; return; break;
        case 1: system("cls"); sum_mnogs();break;
        case 2: system("cls"); minus_mnogs(); break;
        case 3: system("cls"); proizv_mnogs();break;
        case 4: system("cls"); proizv_mnog_num();break;
        case 5: system("cls"); del_mnogs_stolbik(); break;
        case 6: system("cls"); proizvodnaya_mnog();break;
        default: { cout << "Ошибка ввода значений.\n"; break; }
        }
    } while (true);
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
