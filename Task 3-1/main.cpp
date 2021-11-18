#include <iostream>
#include <cmath> 
#include <iomanip>

/**
 * \brief Рассчитывает значение функции в заданной точке
 * \param x Заданная точка
 * \return Возвращает значение функции в заданной точке
 */
double calculateFunc(double x);

/**
 * \brief Проверяет, существует ли функция в заданной точке
 * \param x Заданная точка
 * \return Возвращает true, если значение функции в заданной точке существует
 */
bool isCalculated(double x);


int main()
{
	const double X_START = 1;
	const double X_FINISH = 3;
	const double STEP = 0.2;
	double x = X_START;

	while (x <= X_FINISH)
	{
		if (isCalculated(x))
		{
			const double y = calculateFunc(x);
			std::cout << "x = " << std::setw(5) << std::left << std::setprecision(5) << x << " y = " << y << "\n";
		}
		else
		{
			std::cout << "x = " << x << " y = не существует" << "\n";
		}

		x += STEP;
	}


	return 0;
}

double calculateFunc(const double x)
{
	return 3 * log(x) * log(x) + 6 * log(x) - 5;
}

bool isCalculated(const double x)
{
	return x > 0;
}
