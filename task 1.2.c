#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
#include <locale.h>
/*
* @brief Функция проверяет, что число отлично от нуля
* @param num - проверяемое значение
*/
void checkvalue(const double num);

/*
* @brief Функция для вычисления суммы 2 чисел
* @param num1 - первое число
* @param num2 - второе число
* @return сумму двух чисел
*/
double sumvalue(const double num1, const double num2);

/*
* @brief Функция для вычисления разности 2 чисел
* @param num1 - первое число
* @param num2 - второе число
* @return разность двух чисел
*/
double diffvalue(const double num1, const double num2);

/*
* @brief Функция для вычисления произведения 2 чисел
* @param num1 - первое число
* @param num2 - второе число
* @return произведение двух чисел
*/
double prodvalue(const double num1, const double num2);

/*
* @brief Функция для вычисления частного 2 чисел
* @param num1 - первое число
* @param num2 - второе число
* @return частное двух чисел
*/
double quovalue(const double num1, const double num2);

/*
* @brief Функция для ввода 2 чисел и вычисления их суммы, разности, произведения, частного.
* @param num1 - первое число
* @param num2 - второе число число
* @return рассчитанное значение
*/
int main(void)
{
	double num1 = 0;
	double num2 = 0;
	char* locale = setlocale(LC_ALL, "");
	printf("Введите первое число: ");
	scanf("%lf", &num1);
	printf("Введите второе число: ");
	scanf("%lf", &num2);

	checkvalue(num2);

	printf("Сумма: %lf\n", sumvalue(num1, num2));
	printf("Разность: %lf\n", diffvalue(num1, num2));
	printf("Произведение: %lf\n", prodvalue(num1, num2));
	printf("Частное: %lf\n", quovalue(num1, num2));

	return 0;
}

void checkvalue(const double num)
{
	if (fabs(num) < DBL_EPSILON)
	{
		fprintf(stderr, "Ошибка: второе число должно быть отлично от нуля\n");
		exit(1);
	}
}

double sumvalue(const double num1, const double num2)
{
	return num1 + num2;
}

double diffvalue(const double num1, const double num2)
{
	return num1 - num2;
}

double prodvalue(const double num1, const double num2)
{
	return num1 * num2;
}

double quovalue(const double num1, const double num2)
{
	return num1 / num2;
}
