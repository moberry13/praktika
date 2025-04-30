#pragma once

#include<iostream>
#include<stdexcept>
#include <limits>
#include <string>


using namespace std;

#define MAX_SIZE 10

//void matriceMenu();
int GetChoice();
void MatriceOperation();

void OutputMatrice(int stroki, int stolbcy, double matrice[MAX_SIZE][MAX_SIZE]);
void InputSingleMatrice(int stroki, int stolbcy, double matrice[MAX_SIZE][MAX_SIZE]);
void InputTwoMatrice(int stroki1, int stolbcy1, double matrice1[MAX_SIZE][MAX_SIZE], int stroki2,int stolbcy2, double matrice2[MAX_SIZE][MAX_SIZE]);
void InputMatriceAndNumber(int stroki, int stolbcy, double matrice[MAX_SIZE][MAX_SIZE],double& chislo);
void ShabloMatrice(int stroki, int stolbcy);

void PlusMatrice(int stroki, int stolbcy, double matrice1[MAX_SIZE][MAX_SIZE], double matrice2[MAX_SIZE][MAX_SIZE], double result[MAX_SIZE][MAX_SIZE]);
void MinusMatrice(int stroki, int stolbcy, double matrice1[MAX_SIZE][MAX_SIZE], double matrice2[MAX_SIZE][MAX_SIZE], double result[MAX_SIZE][MAX_SIZE]);
void ymnozhenieMatrice(int stroki1, int stolbcy1, double matrice1[MAX_SIZE][MAX_SIZE], double stroki2, int stolbcy2, double matrice2[MAX_SIZE][MAX_SIZE], double result[MAX_SIZE][MAX_SIZE]);
void ymnozhenieMatriceNaChislo(int stroki, int stolbcy, double matrice[MAX_SIZE][MAX_SIZE], double chislo, double result[MAX_SIZE][MAX_SIZE]);
void PlusNumMatrice(int stroki, int stolbcy, double matrice[MAX_SIZE][MAX_SIZE], double chislo, double result[MAX_SIZE][MAX_SIZE]);
void MinusNumMatrice(int stroki, int stolbcy, double matrice[MAX_SIZE][MAX_SIZE], double chislo, double result[MAX_SIZE][MAX_SIZE]);
void TransponentMatrice(int stroki, int stolbcy, double matrice[MAX_SIZE][MAX_SIZE], double result[MAX_SIZE][MAX_SIZE]);
int Opredelitel(int n, double matrice[MAX_SIZE][MAX_SIZE]);
void PodMatrice(int n, double matrice[MAX_SIZE][MAX_SIZE], double podmatrice[MAX_SIZE][MAX_SIZE],int strokaremove, int stolbecremove);
void MatriceDop(int size, double matrice[MAX_SIZE][MAX_SIZE], double dop[MAX_SIZE][MAX_SIZE]);
bool ObratMatrice(int n, double matrice[MAX_SIZE][MAX_SIZE], double obr[MAX_SIZE][MAX_SIZE]);
static bool GetYesOrNo3();