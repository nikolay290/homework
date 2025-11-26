#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <float.h>
/*
* @brief Фунеция для проверки значения
* @param chislo - Число для проверки
*/
void checkvalue(const double chislo);
/*
* @brief Функция ввода значений пользователем
* @return Введённое пользователем значение
*/
double getValue(void);
/*
* @brief Функция для вычисления Y
* @param x - аргумент Y
* @return Возвращает значение y(x) 
*/
double getY(const double x);

/*
* @brief Точка входа в программу
* @return 0 если программа выполнена корректно
*/
int main(void)
{
    char* locale = setlocale(LC_ALL, "");

    printf("Введите начало интервал\n");
    double start_x = getValue();
    printf("Введите конец интервала\n");
    double end_x = getValue();
    printf("Введите шаг табулирования\n");
    double delta_x = getValue();
    checkvalue(delta_x);
    double x = 0;
    double num = 0;
    for (x = start_x; x <= end_x + 1e-9; x += delta_x)
    {
        num = getY(x);
        printf("%lf\n", x);
        printf("%lf\n", num);
        printf("-------------------------\n");
    }
    return 0;
}


void checkvalue(const double chislo)
{
    if (chislo < DBL_EPSILON)
    {
        fprintf(stderr, "Error\n");
        exit(1);
    }
}
double getY(const double x)
{
    checkvalue(x);
    return sin(log(x)) - cos(log(x)) + 2 * log(x);
}
double getValue(void)
{
    double value = 0;
    if (!scanf("%lf", &value))
    {
        fprintf(stderr,"Error\n");
        exit(1);
    };
    return value;
}
