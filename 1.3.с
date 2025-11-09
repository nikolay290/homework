#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

/*
* @brief Функция для ввода значений
* @param m - указатель на массу ложки
* @param Q - указатель на энергию
*/
void getvalue(double* m, double* Q);

/*
* @brief Функция для вычисления изменения температуры ложки
* @param c - теплоёмкость ложки
* @param m - масса ложки
* @param Q - энергия, которую отдала ложка
* @return - изменение температуры ложки
*/
double gettemp(const int c, double m, double Q);

int main()
{
    const int c = 460;
    double m = 0;  
    double Q = 0;  

    char* locale = setlocale(LC_ALL, "");
    getvalue(&m, &Q);  
    printf("Температура изменилась на: %lf", gettemp(c, m, Q));
    return 0;
}

double gettemp(const int c, double m, double Q)
{
    double temp = Q / (c * (m / 1000));
    return temp;
}

void getvalue(double* m, double* Q)
{
    printf("Введите массу ложки: ");
    if (scanf("%lf", m) != 1) {
        printf("Ошибка ввода массы\n");
        exit(1);
    }

    printf("Введите количество энергии, которую отдала ложка: ");
    if (scanf("%lf", Q) != 1) {
        printf("Ошибка ввода энергии\n");
        exit(1);
    }
}
