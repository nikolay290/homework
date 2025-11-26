#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES 
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>

/**
* @brief Функция вычисления значения y по заданной формуле.
* @param a - Константа.
* @param x - Аргумент функции.
* @return Возвращает вычисленное значение y.
*/
double get_y(const double a, const double x);

/**
* @brief Функция считывания аргумента x с клавиатуры с проверкой ввода.
* @return Возвращает x при успешном вводе, завершает выполнение программы при ошибке.
*/
double get_x(void);
/**
* @brief Точка входа в программу
* @return Возвращает 0 если программа выполнена корректно.
*/
int main(void)
{
    char* locale = setlocale(LC_ALL, "");
    const double a = 1.65;

    printf("Программа вычисления функции y = f(x)\n");
    printf("Параметр a = %.2f\n", a);

    double x = get_x();
    double y = get_y(a, x);

    printf("\nРезультаты вычислений:\n");
    printf("a = %.2f\n", a);
    printf("x = %.2f\n", x);
    printf("y = %.6f\n", y);

    return 0;
}

double get_x(void)
{
    double x = 0;
    printf("Введите значение x: ");
    if (scanf("%lf", &x) != 1)
    {
        fprintf(stderr, "Ошибка ввода! Требуется вещественное число.\n");
        exit(1);
    }
    return x;
}

double get_y(const double a, const double x)
{
    double y = 0;


    if (x < 1.34 - DBL_EPSILON)
    { 
        if (fabs(x) < DBL_EPSILON) {
            fprintf(stderr, "Ошибка: деление на ноль (x не может быть 0)\n");
            exit(1);
        }
        y = M_PI * x * x - 7.0 / (x * x);
        printf("При: x < 1.34, y = pi * x^2 - 7/x^2\n");
    }
    // Сравнение с DBL_EPSILON для x >= 1.4
    else if (x >= 1.4 + DBL_EPSILON)
    {
        // Проверка области определения квадратного корня с использованием DBL_EPSILON
        if ((x + a) < -DBL_EPSILON) {
            fprintf(stderr, "Ошибка: подкоренное выражение (x + a) должно быть неотрицательным\n");
            exit(1);
        }

        double arg = x + 7.0 * sqrt(x + a);

        // Проверка области определения логарифма с использованием DBL_EPSILON
        if (arg <= DBL_EPSILON) {
            fprintf(stderr, "Ошибка: аргумент логарифма должен быть положительным\n");
            exit(1);
        }

        y = log(arg);
        printf("При: x >= 1.4, y = ln(x + 7(x + a)^0.5)\n");
    }
    else
    {
        fprintf(stderr, "Ошибка: значение x = %.6f находится в неопределенном диапазоне [1.34, 1.4)\n", x);
        exit(1);
    }

    return y;
}
