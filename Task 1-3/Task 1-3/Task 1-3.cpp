#include<iostream>

/**
* \brief Функция расчета расстояния между шарами
* \param mass параметр массы
* \param power параметр силы тяготения
* \return Возращает расстояние между шарами
*/
float getDistance(float mass, float power);

/**
* \brief Точка входа в программу
* \return В случае успеха возвращает 0
*/
int main()
{
	std::cout << "Введите массу шаров в тоннах: ";
	float mass;
	std::cin >> mass;
	std::cout << "Введите силу тяготения: ";
	float power;
	std::cin >> power;
	const float distance = getDistance(mass, power);
	std::cout << "Расстояние между шарами = " << distance << std::endl;

	return 0;
}

float getDistance(float mass, float power)
{
	return sqrt((6.67 * pow(10, -11) * mass * 1000 * mass * 1000) / power * pow(10, -5));
}
