#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
* @brief Функция проверяет, что второе число отлично от нуля
*/
void checkvalue(const double num);
/*
* @brief Функция для ввода 2 чисел и вычисления их суммы, разности, произведения, частного.
* @param num1 - первое число
* @param num2 - второе число число
* @return рассчитанное значения
*/
int main(void)
{
	double num1, num2;
	printf("Введите первое число ");
	scanf_s("%lf", &num1);
	printf("Введите второе число ");
	scanf_s("%lf", &num2);
	checkvalue(num2);
	printf("Сумма: %lf\n", num1 + num2);
	printf("Разность %lf\n", num1 - num2);
	printf("Произведение %lf\n", num1 * num2);
	printf("Частное %lf\n", num1 / num2);
	return 0;
}
void checkvalue(const double num)
{
	if (num == 0)
	{
		printf("Второе число должно быть отлично от нуля");
		abort();
	}
}
