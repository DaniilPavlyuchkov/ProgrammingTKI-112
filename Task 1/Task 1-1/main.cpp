
#include <math.h>
#include <iostream>


/**
* \brief Эта функция вычисляет значение A
* \param x параметр x
* \param y параметр y
* \param z параметр z
* \return Возвращает значение A
*/
double getA(const double x, const double y, const double z);

/**
* \brief Эта функция вычисляет значение B
* \param x параметр x
* \param y параметр y
* \param z параметр z
* \return Возвращает значение B
*/
double getB(const double x, const double y, const double z);

/**
* \brief Точка входа в программу
* \return В случае успеха возвращает 0
*/
int main()
{
	const double x = 0.61;
	const double y = 0.9;
	const double z = 0.3;
	const double a = getA(x, y, z);
	const double b = getB(x, y, z);
	std::cout << "x = " << x << " y = " << y << " z = " << z << " a = " << a << " b = " << b << endl;
	
	return 0;
}

double getA(const double x, const double y, const double z)
{
	return (pow(z, 2 * x) + pow(y, -x) * cos(z + y) * x) / (x + 1);
}

double getB(const double x, const double y, const double z)
{
	return sqrt(x*x + y) - y * y * pow(sin((x + z) / x), 3);
}