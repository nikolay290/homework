#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

/*
* @brief Функция для ввода значения с проверкой
* @param prompt - сообщение для пользователя
* @return - введенное значение
*/
double getvalue(const char* prompt);

/*
* @brief Функция для вычисления изменения температуры ложки
* @param c - теплоёмкость ложки
* @param m - масса ложки
* @param Q - энергия, которую отдала ложка
* @return - изменение температуры ложки
*/
double gettemp(const int c, const double m, const double Q);

int main(void)
{
    double c = 0;
    double m = 0;
    double Q = 0;

    char* locale = setlocale(LC_ALL, "");
    c = getvalue("Введите удельную теплоёмкость ложки: ");
    m = getvalue("Введите массу ложки: ");
    Q = getvalue("Введите количество энергии, которую отдала ложка: ");

    printf("Температура изменилась на: %lf", gettemp(c, m, Q));
    return 0;
}

double getvalue(const char* prompt)
{
    double value;
    printf("%s", prompt);
    if (scanf("%lf", &value) != 1) {
        fprintf(stderr, "Ошибка ввода значения\n");
        exit(1);
    }
    return value;
}

double gettemp(const int c, const double m, const double Q)
{
    return Q / (c * (m / 1000));
}
