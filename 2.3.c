#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

/**
* @brief Функция проверки корректности ввода чисел.
* @param prompt - сообщение для пользователя.
* @return Возвращает введенное значение при успешном вводе.
*/
double input_num(const char* prompt);

/**
* @brief Функция вычисления новых значений по заданным формулам.
* @param x - Первое число.
* @param y - Второе число.
* @param new_x - Указатель для результата преобразования первого числа.
* @param new_y - Указатель для результата преобразования второго числа.
*/
void calc_values(const double x, const double y, double* new_x, double* new_y);

/**
* @brief Функция для вывода результатов.
* @param x - Первое исходное число.
* @param y - Второе исходное число.
* @param new_x - Преобразованное первое число.
* @param new_y - Преобразованное второе число.
*/
void output_res(const double x, const double y, const double new_x, const double new_y);

/**
* @brief Точка входа в программу.
* @return Возвращает 0 если программа выполнена корректно.
*/
int main(void)
{
    char* locale = setlocale(LC_ALL, "");

    printf("Программа преобразования двух различных чисел\n");
    printf("=============================================\n");
    printf("Меньшее число заменяется полусуммой, большее - удвоенным произведением\n\n");

    double x = input_num("Введите первое число x: ");
    double y = input_num("Введите второе число y: ");

    if (fabs(x - y) < DBL_EPSILON)
    {
        fprintf(stderr, "Ошибка: числа должны быть различны!\n");
        exit(1);
    }

    double new_x, new_y;
    calc_values(x, y, &new_x, &new_y);
    output_res(x, y, new_x, new_y);

    return 0;
}

double input_num(const char* prompt)
{
    double num = 0;
    printf("%s", prompt);
    if (scanf("%lf", &num) != 1)
    {
        fprintf(stderr, "Ошибка ввода! Требуется вещественное число.\n");
        exit(1);
    }
    return num;
}

void calc_values(const double x, const double y, double* new_x, double* new_y)
{
    if (x < y - DBL_EPSILON)
    {
        // x - меньшее, y - большее
        *new_x = (x + y) / 2.0;        // полусумма
        *new_y = 2.0 * x * y;          // удвоенное произведение
    }
    else
    {
        // y - меньшее, x - большее  
        *new_x = 2.0 * x * y;          // удвоенное произведение
        *new_y = (x + y) / 2.0;        // полусумма
    }

}

void output_res(const double x, const double y, const double new_x, const double new_y)
{
    printf("\nРезультаты преобразования:\n");
    printf("===========================\n");
    printf("Исходные числа:\n");
    printf("x = %.8f\n", x);
    printf("y = %.8f\n", y);

    printf("\nПреобразованные числа:\n");
    if (x < y - DBL_EPSILON)
    {
        printf("x (меньшее) заменено на полусумму: %.8f\n", new_x);
        printf("y (большее) заменено на удвоенное произведение: %.8f\n", new_y);
    }
    else if (y < x - DBL_EPSILON)
    {
        printf("x (большее) заменено на удвоенное произведение: %.8f\n", new_x);
        printf("y (меньшее) заменено на полусумму: %.8f\n", new_y);
    }

    printf("\nИтоговые значения:\n");
    printf("новое x = %.8f\n", new_x);
    printf("новое y = %.8f\n", new_y);
}
