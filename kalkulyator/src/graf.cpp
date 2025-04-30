// graf.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


using namespace std;
#define WEIGHT 800
#define HEIGHT 600
#include "graf.h"

bool GetYesOrNo11() {
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
void stepen1() {
    cout << "График функции вида a*x^b+c\n";
    double a, b, c, x1, x2;
    do {
        cout << "\nВведите а: ";
        cin >> a;
        if (cin.fail()) {
            cout << "Вы ввели не число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            a = DBL_MAX;
        }
    } while (a == DBL_MAX);

    do {

        cout << "Введите b: ";
        cin >> b;
        if (cin.fail()) {
            cout << "Ошибка! Пожалуйста, введите число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            b = DBL_MAX;
        }
    } while (b == DBL_MAX);
    do {
        cout << "Введите c: ";
        cin >> c;
        if (cin.fail()) {
            cout << "Ошибка! Пожалуйста, введите число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            c = DBL_MAX;
        }
    } while (c == DBL_MAX);

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = SDL_CreateWindow(u8"График функции вида a*x^b+c",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WEIGHT, HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderDrawLine(renderer, WEIGHT / 2, 0, WEIGHT / 2, HEIGHT);
    SDL_RenderDrawLine(renderer, 0, HEIGHT / 2, WEIGHT, HEIGHT / 2);

    for (double x = 0; x < 800; x += 0.01) {
        if (x == 0) x += 0.01;
        double x_pic = (x - WEIGHT / 2) / 25;
        double y = -a * pow(x_pic, b) - c;


        SDL_RenderDrawPoint(renderer, int(x), int(y) + HEIGHT / 2);
    }
    SDL_RenderPresent(renderer);
    SDL_Delay(3000);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void pokazatel1() {
    cout << "График функции вида a*b^(c*x)+d\n";
    double a, b, c, d;
    do {
        cout << "\nВведите а: ";
        cin >> a;
        if (cin.fail()) {
            cout << "Ошибка! Пожалуйста, введите число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            a = DBL_MAX;
        }
    } while (a == DBL_MAX);
    int check = 0;
    do {
        if (check > 0) cout << "b должно быть положительным числом ";
        cout << "Введите b: ";
        cin >> b;

        if (cin.fail()) {
            cout << "Ошибка! Пожалуйста, введите число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            b = -1;
        }
        else check++;
    } while (b <= 0);
    do {
        cout << "Введите c: ";
        cin >> c;
        if (cin.fail()) {
            cout << "Ошибка! Пожалуйста, введите число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            c = DBL_MAX;
        }
    } while (c == DBL_MAX);
    do {
        cout << "Введите d: ";
        cin >> d;
        if (cin.fail()) {
            cout << "Ошибка! Пожалуйста, введите число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            d = DBL_MAX;
        }
    } while (d == DBL_MAX);
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = SDL_CreateWindow(u8"График функции вида a*b^(c*x)+d",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WEIGHT, HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderDrawLine(renderer, WEIGHT / 2, 0, WEIGHT / 2, HEIGHT);
    SDL_RenderDrawLine(renderer, 0, HEIGHT / 2, WEIGHT, HEIGHT / 2);

    for (double x = -WEIGHT; x < WEIGHT; x += 0.01) {

        if (x == 0) x += 0.01;
        double x_pic = (x - WEIGHT / 2) / 25;
        double y = -a * (pow(b, c * x_pic)) - d;

        SDL_RenderDrawPoint(renderer, int(x), HEIGHT / 2 + int(y));
    }
    SDL_RenderPresent(renderer);
    SDL_Delay(3000);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void logarifm1() {
    cout << "График функции вида a*ln(b*x)+c\n";
    double a, b, c;
    do {
        cout << "\nВведите а: ";
        cin >> a;
        if (cin.fail()) {
            cout << "Ошибка! Пожалуйста, введите число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            a = DBL_MAX;
        }
    } while (a == DBL_MAX);
    int check = 0;
    do {
        if (check > 0) cout << "b должно быть положительным числом.";
        cout << "Введите b: ";
        cin >> b;
        if (cin.fail()) {
            cout << "Ошибка! Пожалуйста, введите число. " << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            b = -1;
        }
        else check++;
    } while (b <= 0);
    do {
        cout << "Введите c: ";
        cin >> c;
        if (cin.fail()) {
            cout << "Ошибка! Пожалуйста, введите число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            c = DBL_MAX;
        }
    } while (c == DBL_MAX);
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = SDL_CreateWindow(u8"График функции вида a*ln(b*x)+c",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WEIGHT, HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderDrawLine(renderer, WEIGHT / 2, 0, WEIGHT / 2, HEIGHT);
    SDL_RenderDrawLine(renderer, 0, HEIGHT / 2, WEIGHT, HEIGHT / 2);

    for (double x = 0; x < WEIGHT; x += 0.01) {

        double x_pic = (x - WEIGHT / 2) / 25;
        double y = -a * log(b * x_pic) - c;

        SDL_RenderDrawPoint(renderer, int(x), int(y) + HEIGHT / 2);
    }
    SDL_RenderPresent(renderer);
    SDL_Delay(3000);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

}

void sinysoida1() {
    cout << "График функции вида a*sin(b*x+c)+d\n";
    double a, b, c, d;
    do {
        cout << "\nВведите a: ";
        cin >> a;
        if (cin.fail()) {
            cout << "Ошибка! Пожалуйста, введите число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            a = DBL_MAX;
        }
    } while (a == DBL_MAX);

    do {

        cout << "Введите b: ";
        cin >> b;
        if (cin.fail()) {
            cout << "Ошибка! Пожалуйста, введите число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            b = DBL_MAX;
        }
    } while (b == DBL_MAX);
    do {
        cout << "Введите c: ";
        cin >> c;
        if (cin.fail()) {
            cout << "Ошибка! Пожалуйста, введите число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            c = DBL_MAX;
        }
    } while (c == DBL_MAX);
    do {
        cout << "Введите d: ";
        cin >> d;
        if (cin.fail()) {
            cout << "Ошибка! Пожалуйста, введите число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            d = DBL_MAX;
        }
    } while (d == DBL_MAX);
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = SDL_CreateWindow(u8"График функции вида  a*sin(b*x+c)+d",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WEIGHT, HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderDrawLine(renderer, WEIGHT / 2, 0, WEIGHT / 2, HEIGHT);
    SDL_RenderDrawLine(renderer, 0, HEIGHT / 2, WEIGHT, HEIGHT / 2);

    for (double x = 0; x < WEIGHT; x += 0.01) {

        double x_pic = (x + WEIGHT / 2 - 5) / 25;
        double y = -10 * a * sin(b * x_pic + c) - d;

        SDL_RenderDrawPoint(renderer, int(x) + 10, int(y) + HEIGHT / 2);
    }
    SDL_RenderPresent(renderer);
    SDL_Delay(3000);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void polinom1() {
    cout << "График полинома максимальной степени N: a0+a1*x+a2*x^2+...+aN*x^N\n";
    int N;
    int check = 0;
    do {
        if (check > 0) cout << "Введите положительное число. \n";
        cout << "\nВведите максимальную степень N: ";
        cin >> N;
        if (cin.fail()) {
            cout << "Ошибка! Пожалуйста, введите число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            N = -1;
        }
        else check++;
    } while (N < 0);
    N++;
    double* a = (double*)malloc(N * sizeof(double));
    for (int i = 0; i < N; i++) {
        do {
            cout << "Введите a" << i << ": ";
            cin >> a[i];
            if (cin.fail()) {
                cout << "Ошибка! Пожалуйста, введите число." << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                a[i] = INT_MAX;
            }
        } while (a[i] == INT_MAX);
    }

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = SDL_CreateWindow(u8"График полинома максимальной степени N: a0+a1*x+a2*x^2+...+aN*x^N",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WEIGHT, HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderDrawLine(renderer, WEIGHT / 2, 0, WEIGHT / 2, HEIGHT);
    SDL_RenderDrawLine(renderer, 0, HEIGHT / 2, WEIGHT, HEIGHT / 2);

    double y = 0;
    for (double x = -WEIGHT; x < WEIGHT; x += 0.01) {

        double x_pic = (x - WEIGHT / 2) / 25;
        for (int i = 0; i < N; i++) {
            y += a[i] * pow(x_pic, i);
        }

        SDL_RenderDrawPoint(renderer, int(x), HEIGHT / 2 - int(y));
        y = 0;
    }
    SDL_RenderPresent(renderer);
    SDL_Delay(3000);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void cosinysoida1() {
    cout << "График функции вида a*cos(b*x+c)+d\n";
    double a, b, c, d;
    do {
        cout << "\nВведите a: ";
        cin >> a;
        if (cin.fail()) {
            cout << "Ошибка! Пожалуйста, введите число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            a = DBL_MAX;
        }
    } while (a == DBL_MAX);

    do {

        cout << "Введите b: ";
        cin >> b;
        if (cin.fail()) {
            cout << "Ошибка! Пожалуйста, введите число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            b = DBL_MAX;
        }
    } while (b == DBL_MAX);
    do {
        cout << "Введите c: ";
        cin >> c;
        if (cin.fail()) {
            cout << "Ошибка! Пожалуйста, введите число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            c = DBL_MAX;
        }
    } while (c == DBL_MAX);
    do {
        cout << "Введите d: ";
        cin >> d;
        if (cin.fail()) {
            cout << "Ошибка! Пожалуйста, введите число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            d = DBL_MAX;
        }
    } while (d == DBL_MAX);
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = SDL_CreateWindow(u8"График функции вида a*cos(b*x+c)+d",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WEIGHT, HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderDrawLine(renderer, WEIGHT / 2, 0, WEIGHT / 2, HEIGHT);
    SDL_RenderDrawLine(renderer, 0, HEIGHT / 2, WEIGHT, HEIGHT / 2);

    for (double x = -WEIGHT; x < WEIGHT; x += 0.01) {

        double x_pic = (x + WEIGHT / 2 - 5) / 25;
        double y = -10 * a * cos(b * x_pic + c) - d;

        SDL_RenderDrawPoint(renderer, int(x) + 10, int(y) + HEIGHT / 2);
    }
    SDL_RenderPresent(renderer);
    SDL_Delay(3000);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

}

void graphici() {
    int numb1;
    do {
        cout << "\nГрафик функции. \n Функции : \n 0. Выход в главное меню \n 1. Cтепенная функция: a*x^b+c \n 2. Показательная функция: a*b^(c*x)+d \n 3. Логарифмическая функция: a*ln(b*x)+c \n 4. Синусоида: a*sin(b*x+c)+d \n 5. Косинусоида: a*cos(b*x+c)+d \n 6. Полином степени N: a0+a1*x+a2*x^2+...+aN*x^N\n";
        
       
        do {
            cout << "\nВыберите номер действия: ";
            cin >> numb1;

            if (numb1 < 0 || numb1 > 7) {
                cout << "Число не подходит";}

            if (cin.fail() ) {
                cout << "Ошибка ввода! Вы ввели не число" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "\nВыберите номер действия: ";
                cin >> numb1;

            }
        } while (numb1 < 0 || numb1 > 7);

        switch (numb1) {
        case 0: cout << "Выход в меню"; return; break;
        case 1: system("cls"); stepen1(); break;
        case 2: system("cls");   pokazatel1();
            break;
        case 3:system("cls"); logarifm1();
            break;
        case 4:system("cls"); sinysoida1();
            break;
        case 5:system("cls"); cosinysoida1();
            break;
        case 6:system("cls"); polinom1();
            break;
        default:
            cout << "Действия с выбранным номером нет.";
        }
    } while (true);
}

