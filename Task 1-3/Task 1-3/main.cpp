#include<iostream>

/**
* \brief Функция расчета расстояния между шарами
* \param mass параметр массы
* \param power параметр силы тяготения
* \return Возращает расстояние между шарами
*/
double getDistance(double mass, double power);

/**
* \brief Точка входа в программу
* \return В случае успеха возвращает 0
*/
int main()
{
	std::cout << "Введите массу шаров в тоннах: ";
	double mass;
	std::cin >> mass;
	std::cout << "Введите силу тяготения: ";
	double power;
	std::cin >> power;
	const double distance = getDistance(mass, power);
	std::cout << "Расстояние между шарами = " << distance << std::endl;

	return 0;
}

double getDistance(const double mass, const double power)
{
	return sqrt((6.67 * pow(10, -11) * mass * 1000 * mass * 1000) / power * pow(10, -5));
}
