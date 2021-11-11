#include<iostream>


/**
* \brief Эта функция вычисляет длину в дюймах
* \return Возвращает значение длины в дюймах
*/
double getInches(double lenght);

/**
* \brief Точка входа в программу
* \return В случае успеха возвращает 0
*/
int main()
{
	std::cout << "Введите значение длины в сантиметрах: ";
	double lenght;
	std::cin >> lenght;
	lenght = getInches(lenght);
	std::cout << "Длина в дюймах = " << lenght << std::endl;
}

double getInches(double lenght)
{
	return lenght / 2.5;
}