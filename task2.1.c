#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#define EPSILON 1e-9

/*
* @brief Функция ввода значений пользователем
* @param value - Вводимое пользователем значение
* @return введённое пользователем значение
*/
double getValue(void);
/*
* @brief Функция для выбора операции пользователем
* @return Результат выбранной оперции
*/
int vibor(const double num1, const double num2);
/*
* @brief Функция для вычисления суммы 2 чисел
* @param num1 - первое число
* @param num2 - второе число
* @return сумму двух чисел
*/
double sumvalue(double num1, double num2);
/*
* @brief Функция для вычисления разности 2 чисел
* @param num1 - первое число
* @param num2 - второе число
* @return разность двух чисел
*/
double diffvalue(double num1, double num2);
/*
* @brief Функция для вычисления произведения 2 чисел
* @param num1 - первое число
* @param num2 - второе число
* @return произведение двух чисел
*/
double prodvalue(double num1, double num2);
/*
* @brief Функция для вычисления частного 2 чисел
* @param num1 - первое число
* @param num2 - второе число
* @return частное двух чисел
*/
double quovalue(double num1, double num2);
/**
@brief PERIMETR - периметр прямоугольника
@brief SQUARE - площадь прямоугольника
*/
enum { SUMMA = 1, RAZNOST, YMNOJENIE, DELENIE };

/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программма выполнена корректно
 */
int main(void)
{
    setlocale(LC_ALL, "ru");
    printf("Введите числа: ");
    double num1 = getValue();
    double num2 = getValue();
    printf("Выберите нужный расчет: %d-сумма, %d-разность, %d-умножение, %d-деление\n", SUMMA, RAZNOST, YMNOJENIE, DELENIE);
    vibor(num1, num2);
    return 0;
}



double getValue()
{
    double value = 0;
    if (!scanf("%lf", &value))
    {
        printf("Error\n");
        exit(1);
    };
    return value;
}

double sumvalue(const double num1, const double num2)
{
    double sum = num1 + num2;
    return sum;
}
double diffvalue(const double num1, const double num2)
{
    double diff = num1 - num2;
    return diff;
}
double prodvalue(const double num1, const double num2)
{
    double prod = num1 * num2;
    return prod;
}
double quovalue(const double num1, const double num2)
{
    double quo = num1 / num2;
    return quo;
}

int vibor(const double num1, const double num2)
{
    int choice = (int)getValue();
    switch (choice)
    {
    case SUMMA:
        printf("Сумма равна %.2lf", sumvalue(num1, num2));
        break;
    case RAZNOST:
        printf("Разность равна %.2lf", diffvalue(num1, num2));
        break;
    case YMNOJENIE:
        printf("Произведение равно %.2lf", prodvalue(num1, num2));
        break;
    case DELENIE:
        if (num2 == 0 + EPSILON)
        {
            printf("error\n");
            exit(1);
        };
        printf("Частное равно %.2lf", quovalue(num1, num2));
        break;
    default:
        printf("Неправильный выбор");
        exit(1);
    }
}
