#include <stdio.h>
#include <math.h>
/**
 * @brief Ðàññ÷èòûâàåò ôóíêöèþ A ïî çàäàííîé ôîðìóëå
 * @param x - çíà÷åíèå ïàðàìåòðà x
 * @param y - çíà÷åíèå ïàðàìåòðà y
 * @param z - çíà÷åíèå ïàðàìåòðà z
 * @return ðàññ÷èòàííîå çíà÷åíèå
 */
double getA(const double x, const double y, const double z);
/**
 * @brief Ðàññ÷èòûâàåò ôóíêöèþ Â ïî çàäàííîé ôîðìóëå
 * @param x - çíà÷åíèå ïàðàìåòðà x
 * @param y - çíà÷åíèå ïàðàìåòðà y
 * @param z - çíà÷åíèå ïàðàìåòðà z
 * @return ðàññ÷èòàííîå çíà÷åíèå
 */
double getB(const double x, const double y, const double z, double a);

const double x = -0.5;
const double y = 1.7;
const double z = 0.44;
double a;
double b;
/**
 * @brief Òî÷êà âõîäà â ïðîãðàììó
 * @return Âîçâðàùàåò 0, åñëè ïðîãðàììà âûïîëíåíà êîððåêòíî
 */
int main()
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
