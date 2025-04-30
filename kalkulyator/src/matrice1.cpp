#include"matrice.h"
#include<iostream>
#include<locale>
#include <limits>
#include <string>


int GetChoice() {
	int choice;
	while (!(cin >> choice) || (choice < 0 || choice > 9)) {
		cout << "Введите число от 0 до 9: ";
		cin.clear();
		cin.ignore(10000, '\n');
	}
	return choice;
}

void Matrice(int stroki, int stolbcy) {
	for (int i = 0; i < stroki; i++) {
		for (int j = 0; j < stolbcy; j++) {
			cout << "a" << i + 1 << j + 1 << "\t";
		}
		cout << endl;
	}
}

void OutputMatrice(int stroki, int stolbcy, double matrice[MAX_SIZE][MAX_SIZE]) {
	for (int i = 0; i < stroki; i++) {
		for (int j = 0; j < stolbcy; j++) {
			cout << matrice[i][j] << "\t";
		}
		cout << endl;
	}
}

void InputSingleMatrice(int stroki, int stolbcy, double matrice[MAX_SIZE][MAX_SIZE]) {
	Matrice(stroki, stolbcy);

	cout << "Введите элементы матрицы " << stroki << "x" << stolbcy << ":\n";

	for (int i = 0; i < stroki; i++) {
		for (int j = 0; j < stolbcy; j++) {
			while (true) {
				cout << "a" << i + 1 << j + 1 << " = ";
				cin >> matrice[i][j];

				if (!cin.fail() && stolbcy > 0 ) break;

				
				cin.clear();
				cin.ignore(10000, '\n');
			}
		}
	}
	cout << "Введенная матрица\n";
	OutputMatrice(stroki, stolbcy, matrice);
}




void InputTwoMatrice(int stroki1, int stolbcy1, double matrice1[MAX_SIZE][MAX_SIZE], 
	int stroki2, int stolbcy2, double matrice2[MAX_SIZE][MAX_SIZE]) {
	cout << "Введите элементы первой матрицы " << stroki1 << "x" << stolbcy1 << ":\n";
	InputSingleMatrice(stroki1, stolbcy1, matrice1);

	cout << "Введите элементы второй матрицы " << stroki2 << "x" << stolbcy2 << ":\n";
	InputSingleMatrice(stroki2, stolbcy2, matrice2);
}

void InputMatriceAndNumber(int stroki, int stolbcy, double matrice[MAX_SIZE][MAX_SIZE], 
	double& chislo) {
	cout << "Введите элементы матрицы " << stroki << "x" << stolbcy << ":\n";
	InputSingleMatrice(stroki, stolbcy, matrice);

	cout << "Введите число: ";
	while (!(cin >> chislo)) {
		cout << "Ошибка ввода числа. Попробуйте снова: ";
		cin.clear();
		cin.ignore(10000, '\n');
	}
}

void PlusMatrice(int stroki, int stolbcy, double matrice1[MAX_SIZE][MAX_SIZE],
	double matrice2[MAX_SIZE][MAX_SIZE], double result[MAX_SIZE][MAX_SIZE]) {
	for (int i = 0; i < stroki; i++) {
		for (int j = 0; j < stolbcy; j++) {
			result[i][j] = matrice1[i][j] + matrice2[i][j];
		}
	}
}


void MinusMatrice(int stroki, int stolbcy, double matrice1[MAX_SIZE][MAX_SIZE],
	double matrice2[MAX_SIZE][MAX_SIZE], double result[MAX_SIZE][MAX_SIZE]) {
	for (int i = 0; i < stroki; i++) {
		for (int j = 0; j < stolbcy; j++) {
			result[i][j] = matrice1[i][j] - matrice2[i][j];
		}
	}
}
void ymnozhenieMatrice(int stroki1, int stolbcy1, double matrice1[MAX_SIZE][MAX_SIZE],
	int stroki2, int stolbcy2, double matrice2[MAX_SIZE][MAX_SIZE],double result[MAX_SIZE][MAX_SIZE]) {
	for (int i = 0; i < stroki1; i++) {
		for (int j = 0; j < stolbcy2; j++) {
			result[i][j] = 0;
			for (int k = 0; k < stolbcy1; k++) {
				result[i][j] += matrice1[i][k] * matrice2[k][j];
			}
		}
	}
}

void ymnozhenieMatriceNaChislo(int stroki, int stolbcy, double matrice[MAX_SIZE][MAX_SIZE], 
	double chislo, double result[MAX_SIZE][MAX_SIZE]) {
	for (int i = 0; i < stroki; i++) {
		for (int j = 0; j < stolbcy; j++) {
			result[i][j] = matrice[i][j] * chislo;
		}
	}
}


void PlusNumMatrice(int stroki, int stolbcy, double matrice[MAX_SIZE][MAX_SIZE],
	double chislo, double result[MAX_SIZE][MAX_SIZE]) {
	for (int i = 0; i < stroki; i++) {
		for (int j = 0; j < stolbcy; j++) {
			result[i][j] = matrice[i][j] + chislo;
		}
	}
}

void MinusNumMatrice(int stroki, int stolbcy, double matrice[MAX_SIZE][MAX_SIZE],
	double chislo, double result[MAX_SIZE][MAX_SIZE]) {
	for (int i = 0; i < stroki; i++) {
		for (int j = 0; j < stolbcy; j++) {
			result[i][j] = matrice[i][j] - chislo;
		}
	}
}

void TransponentMatrice(int stroki, int stolbcy, 
	double matrice[MAX_SIZE][MAX_SIZE], double result[MAX_SIZE][MAX_SIZE]) {
	for (int i = 0; i < stroki; i++) {
		for (int j = 0; j < stolbcy; j++) {
			result[j][i] = matrice[i][j];
		}
	}
}

int Opredelitel(int n, double matrice[MAX_SIZE][MAX_SIZE]) {
	if (n == 1) {
		return matrice[0][0];
	}
	else if (n == 2) {
		return matrice[0][0] * matrice[1][1] - matrice[0][1] * matrice[1][0];
	}
	else if (n == 3) {
		return matrice[0][0] * (matrice[1][1] * matrice[2][2] - matrice[1][2] * matrice[2][1])
			- matrice[0][1] * (matrice[1][0] * matrice[2][2] - matrice[1][2] * matrice[2][0])
			+ matrice[0][2] * (matrice[1][0] * matrice[2][1] - matrice[1][1] * matrice[2][0]);
	}
}

void PodMatrice(int n, double matrice[MAX_SIZE][MAX_SIZE], double podmatrice[MAX_SIZE][MAX_SIZE],
	int strokaremove, int stolbecremove) {
	int stroka = 0, stolbec = 0;
	for (int i = 0; i < n; i++) {
		if (i == strokaremove) {
			continue;
		}
		stolbec = 0;
		for (int j = 0; j < n; j++) {
			if (j == stolbecremove) {
				continue;
			}
			podmatrice[stroka][stolbec] = matrice[i][j];
			stolbec++;
		}
		stroka++;
	}
}

void MatriceDop(int size, double matrice[MAX_SIZE][MAX_SIZE], 
	double dop[MAX_SIZE][MAX_SIZE]) {
	double podmatrice[MAX_SIZE][MAX_SIZE];
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			PodMatrice(size, matrice, podmatrice, i, j);
			int minorOpred = Opredelitel(size - 1, podmatrice);
			dop[i][j] = ((i + j) % 2 == 0 ? 1 : -1) * minorOpred;
		}
	}
}

bool ObratMatrice(int n, double matrice1[MAX_SIZE][MAX_SIZE], double obr[MAX_SIZE][MAX_SIZE]) {
		int opredmatrice1 = Opredelitel(n, matrice1);
		if (opredmatrice1 == 0) {
			return false;
		}
		double dop[MAX_SIZE][MAX_SIZE];
		MatriceDop(n, matrice1, dop);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				obr[i][j] = dop[j][i] / opredmatrice1;
			}
		}
		return true;
}

static bool GetYesOrNo() {
	string input;

	while (true) {
		cout << "\nХотите повторить? (yes/no): ";
		cin >> input;

		if (input == "y" || input == "yes") {
			return true;
		}
		else if (input == "n"||  input == "no") {

			return false;
		}
		cout << "Ошибка! Пожалуйста, введите 'yes' или 'no': ";
	}
}

void MatriceOperation() {
	int operation;
	do {
		cout << "Матричный калькулятор:\n";
		cout << "Функции: \n";
		cout << "0. Выход в меню\n";
		cout << "1. Сложение матриц\n";
		cout << "2. Вычитание матриц\n";
		cout << "3. Умножение матриц\n";
		cout << "4. Умножение матрицы на число\n";
		cout << "5. Сложение матрицы с числом\n";
		cout << "6. Вычитание матрицы с числом\n";
		cout << "7. Транспонирование матрицы\n";
		cout << "8. Определитель матрицы\n";
		cout << "9. Обратная матрица\n";

		do {
			cout << "\nВыберите номер действия: ";
			cin >> operation;

			if (operation < 0 || operation > 10) {
				cout << "Число не подходит";

			}

			if (cin.fail()) {
				cout << "Ошибка ввода! Вы ввели не число." << endl;
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "\nВыберите номер действия: ";
				cin >> operation;
			}
		} while (operation < 0 || operation > 10);


		

		double matrice1[MAX_SIZE][MAX_SIZE], matrice2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE], chislo;
		int stroki, stolbcy;

		switch (operation) {
		case 1:
			system("cls");
			do {
				do {
					cout << "Введите количество строк для матрицы: ";
					cin >> stroki;
					if (stroki <= 0 || cin.fail()) {
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "Число должно быть положительным\n";
					}
				} while (stroki <= 0);

				do {
					cout << "Введите количество столбцов для матрицы: ";
					cin >> stolbcy;
					if (stolbcy <= 0 || cin.fail()) {
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "Число должно быть положительным\n";
					}
				} while (stolbcy <= 0);
				cout << "Введите элементы первой матрицы:\n";
				InputSingleMatrice(stroki, stolbcy, matrice1);
				cout << "Введите элементы второй матрицы:\n";
				InputSingleMatrice(stroki, stolbcy, matrice2);

					PlusMatrice(stroki, stolbcy, matrice1, matrice2, result);
					cout << "Результат сложения матриц:\n";				
				
				OutputMatrice(stroki, stolbcy, result);
			} while (GetYesOrNo());
			break;

		case 2:
			system("cls");
			do {
				do {
					cout << "Введите количество строк для матрицы: ";
					cin >> stroki;
					if (stroki <= 0 || cin.fail()) {
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "Число должно быть положительным\n";
					}
				} while (stroki <= 0);

				do {
					cout << "Введите количество столбцов для матрицы: ";
					cin >> stolbcy;
					if (stolbcy <= 0 || cin.fail()) {
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "Число должно быть положительным\n";
					}
				} while (stolbcy <= 0);
				cout << "Введите элементы первой матрицы:\n";
				InputSingleMatrice(stroki, stolbcy, matrice1);
				cout << "Введите элементы второй матрицы:\n";
				InputSingleMatrice(stroki, stolbcy, matrice2);
		
				MinusMatrice(stroki, stolbcy, matrice1, matrice2, result);
				cout << "Результат вычитания матриц:\n";
				
				OutputMatrice(stroki, stolbcy, result);
			} while (GetYesOrNo());
			break;
		case 3: {
			system("cls");
			do {
				int stroki1, stolbcy1, stroki2, stolbcy2;

				do {
					cout << "Введите значение для строк первой матрицы\n";
					cin >> stroki1;
					if (stroki1 <= 0 || cin.fail()) {
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "Число должно быть положительным\n";
					}
				} while (stroki1 <= 0);

				do {
					cout << "Число значение для столбцов первой матрицы\n";
					cin >> stolbcy1;
					if (stolbcy1 <= 0 || cin.fail()) {
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "Число должно быть положительным\n";
					}
				} while (stolbcy1 <= 0);

				do {
					cout << "Введите значение для строк второй матрицы\n";
					cin >> stroki2;
					if (stroki2 <= 0 || cin.fail()) {
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "Число должно быть положительным\n";
					}
				} while (stroki2 <= 0);

				do {
					cout << "Введите значение для столбцов второй матрицы\n";
					cin >> stolbcy2;
					if (stolbcy2 <= 0 || cin.fail()) {
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "Число должно быть положительным\n";
					}
				} while (stolbcy2 <= 0);



				if (stolbcy1 != stroki2) {
					cout << "Число столбцов первой матрицы должно быть равно числу строк второй.\n";
					return;
				}

				InputTwoMatrice(stroki1, stolbcy1, matrice1, stroki2, stolbcy2, matrice2);

				ymnozhenieMatrice(stroki1, stolbcy1, matrice1, stroki2, stolbcy2, matrice2, result);
				cout << "Результат умножения:\n";
				OutputMatrice(stroki1, stolbcy2, result);
			} while (GetYesOrNo());
			break;
		}
		case 4: {
			system("cls");
			do {
				do {
					cout << "Введите количество строк для матрицы: ";
					cin >> stroki;
					if (stroki <= 0 || cin.fail()) {
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "Число должно быть положительным числом \n";
					}
				} while (stroki <= 0);
				do {
					cout << "Введите количество столбцов для матрицы: ";
					cin >> stolbcy;
					if (stolbcy <= 0 || cin.fail()) {
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "Значение должно быть положительным числом\n";
					}
				} while (stolbcy <= 0);
				InputMatriceAndNumber(stroki, stolbcy, matrice1, chislo);
				ymnozhenieMatriceNaChislo(stroki, stolbcy, matrice1, chislo, result);
				cout << "Результат умножения матрицы на число:\n";
				OutputMatrice(stroki, stolbcy, result);
			} while (GetYesOrNo());
			break;
		}

		case 5: {
			system("cls");
			do {
				do {
					cout << "Введите количество строк для матрицы: ";
					cin >> stroki;
					if (stroki <= 0 || cin.fail()) {
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "Число должно быть положительным числом\n";
					}
				} while (stroki <= 0);
				do {
					cout << "Введите количество столбцов для матрицы: ";
					cin >> stolbcy;
					if (stolbcy <= 0 || cin.fail()) {
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "Число должно быть положительным числом\n";
					}
				} while (stolbcy <= 0);
				InputMatriceAndNumber(stroki, stolbcy, matrice1, chislo);
				PlusNumMatrice(stroki, stolbcy, matrice1, chislo, result);
				cout << "Результат сложения матрицы с числом:\n";
				OutputMatrice(stroki, stolbcy, result);
			} while (GetYesOrNo());
			break;
		}

		case 6: {
			system("cls");
			do {
				do {
					cout << "Введите количество строк для матрицы: ";
					cin >> stroki;
					if (stroki <= 0 || cin.fail()) {
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "Число должно быть положительным числом\n";
					}
				} while (stroki <= 0);
				do {
					cout << "Введите количество столбцов для матрицы: ";
					cin >> stolbcy;
					if (stolbcy <= 0 || cin.fail()) {
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "Число должно быть положительным числом\n";
					}
				} while (stolbcy <= 0);
				InputMatriceAndNumber(stroki, stolbcy, matrice1, chislo);
				MinusNumMatrice(stroki, stolbcy, matrice1, chislo, result);
				cout << "Результат вычитания числа из матрицы:\n";
				OutputMatrice(stroki, stolbcy, result);
			} while (GetYesOrNo());
			break;
		}

		case 7: {
			system("cls");
			do {
				do {
					cout << "Введите количество строк для матрицы: ";
					cin >> stroki;
					if (stroki <= 0 || cin.fail()) {
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "Число должно быть положительным числом\n";
					}
				} while (stroki <= 0);
				do {
					cout << "Введите количество столбцов для матрицы: ";
					cin >> stolbcy;
					if (stolbcy <= 0 || cin.fail()) {
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "Число должно быть положительным числом\n";
					}
				} while (stolbcy <= 0);
				InputSingleMatrice(stroki, stolbcy, matrice1);
				TransponentMatrice(stroki, stolbcy, matrice1, result);
				cout << "Транспонированная матрица:\n";
				OutputMatrice(stolbcy, stroki, result);
			} while (GetYesOrNo());
			break;
		}

		case 8: {
			system("cls");
			do {
				do {
					cout << "Введите количество строк для матрицы: ";
					cin >> stroki;
					if (stroki <= 0 || stroki > 3 || cin.fail()) {
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "Введите число от 1 до 3\n";
					}
				} while (stroki <= 0 || stroki > 3);
				do {
					cout << "Введите количество столбцов для матрицы: ";
					cin >> stolbcy;
					if (stolbcy <= 0 || stolbcy > 3 || cin.fail()) {
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "Введите число от 1 до 3\n";
					}
				} while (stolbcy <= 0 || stroki > 3);
				if (stroki != stolbcy) {
					cout << "Определитель может быть вычислен только для квадратной матрицы.\n";
					return;
				}
				InputSingleMatrice(stroki, stolbcy, matrice1);
				int opred = Opredelitel(stroki, matrice1);
				cout << "Определитель матрицы равен: " << opred << "\n";
			} while (GetYesOrNo());
			break;
		}

		case 9: {
			system("cls");
			do {
				do {
					cout << "Введите количество строк для матрицы: ";
					cin >> stroki;
					if (stroki <= 0 || stroki > 3 || cin.fail()) {
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "Введите число от 1 до 3\n";
					}
				} while (stroki <= 0 || stroki > 3);
				do {
					cout << "Введите количество столбцов для матрицы: ";
					cin >> stolbcy;
					if (stolbcy <= 0 || stolbcy > 3 || cin.fail()) {
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "Введите число от 1 до 3\n";
					}
				} while (stolbcy <= 0 || stroki > 3);
				if (stroki != stolbcy) {
					cout << "Обратная матрица может быть вычислен только для квадратной матрицы.\n";
					return;
				}
				InputSingleMatrice(stroki, stolbcy, matrice1);
				if (stroki != stolbcy) {
					cout << "Обратная матрица возможна только для квадратной матрицы.\n";
					return;
				}
				double obr[MAX_SIZE][MAX_SIZE];
				if (ObratMatrice(stroki, matrice1, obr)) {
					cout << "Обратная матрица:\n";
					for (int i = 0; i < stroki; i++) {
						for (int j = 0; j < stolbcy; j++) {
							cout << obr[i][j] << "\t";
						}
						cout << endl;
					}
				}
				else {
					cout << "Матрица вырождена.\n";
				}
			} while (GetYesOrNo());
			break;
		}
		case 0:
			cout << "Выход в главное меню\n";return;break;

		default:
			cout << "Неизвестная операция.\n";
			break;
		}
	}while (true);
}

