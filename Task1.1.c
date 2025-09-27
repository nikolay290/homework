#include <stdio.h>
#include <math.h>
/**
 * @brief Рассчитывает функцию A по заданной формуле
 * @param x - значение параметра x
 * @param y - значение параметра y
 * @param z - значение параметра z
 * @return рассчитанное значение
 */
double getA(const double x, const double y, const double z);
/**
 * @brief Рассчитывает функцию В по заданной формуле
 * @param x - значение параметра x
 * @param y - значение параметра y
 * @param z - значение параметра z
 * @return рассчитанное значение
 */
double getB(const double x, const double y, const double z, double a);

const double x = -0.5;
const double y = 1.7;
const double z = 0.44;
double a;
double b;
/**
 * @brief Точка входа в программу
 * @return Возвращает 0, если программа выполнена корректно
 */
int main1()
{
	double a = getA(x, y, z);
	double b = getB(x, y, z, a);
	printf("x = %lf\n", x);
	printf("y = %lf\n", y);
	printf("z = %lf\n", z);
	printf("a = %lf\n", a);
	printf("b = %lf\n", b);

	return 0;
}

double getA(const double x, const double y, const double z)
{
	double a = pow(exp(1.0), y * z) * sin(x * z - y) - pow(fabs(y * z + x), 0.5);
	return a;
}

double getB(const double x, const double y, const double z, double a)
{
	double b = y * sin(a * pow(z, 2) * cos(2 * z)) - 1;
	return b;
}