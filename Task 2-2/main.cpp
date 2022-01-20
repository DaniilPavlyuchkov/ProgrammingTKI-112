#include <iostream>
#include <cmath>

using namespace std;

/**
*\brief Функция для рассчета y1
*\param x число, вводимое пользователем
*\return Возвращает значение y1
**/
double getFirstY(const double a, double x);

/**
*\brief Функция для рассчета y2
*\param x число, вводимое пользователем
*\return Возвращает значение y2
**/
double getSecondY(const double a, double x);

/**
*\brief Функция для рассчета y3
*\param x число, вводимое пользователем
*\return Возвращает значение y3
**/
double getThirdY(const double a, double x);

int main()
{
	const double a = 2.5;
	const double eps = 0.5;
	cout << "Введите x = ";
	double x;
	cin >> x;

	if (x < eps)
	{
		double firstY = getFirstY(a, x);
		cout << firstY;
	}
	else if ((x - eps) == 0)
	{
		double secondY = getSecondY(a, x);
		cout << secondY;
	}
	else
	{
		double thirdY = getThirdY(a, x);
		cout << thirdY;
	}

	return 0;
}

double getFirstY(const double a, double x)
{
	return sqrt(a * x * x + 1);
}

double getSecondY(const double a, double x)
{
	return a * x + 3;
}

double getThirdY(const double a, double x)
{
	return sqrt(a * a * x - 1);
}