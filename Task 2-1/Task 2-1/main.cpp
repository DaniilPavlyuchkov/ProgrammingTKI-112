#include <iostream>
#include <algorithm>

/**
* \brief Функция для сравнения двух чисел
* \param first_num Первое число
* \param second_num Второе число
* \return Если первое число больше второго, возвращает true; В обратном случае - false
*/
bool compare(float first_num, float second_num);

/**
 * \brief Комманды для работы с массивом
 */
enum class ARRAY_COMMANDS
{
	ASCENDING, DESCENDING
};

/**
* \brief Точка входа в программу
* \return В случае успеха возвращает 0
*/
int main()
{	
	const size_t size = 3;
	double nums_array[size];
	std::cout << "Введите первое число: ";
	std::cin >> nums_array[0];
	std::cout << "Введите второе число: ";
	std::cin >> nums_array[1];
	std::cout << "Введите третье число: ";
	std::cin >> nums_array[2];
	
	std::cout << "Чтобы расположить числа в порядке возрастания (убывания) введите 0 (1)\n";
	
	int command;
	std::cin >> command;

	const auto array_commands = static_cast<ARRAY_COMMANDS>(command);
	switch (array_commands)
	{
	
		case ARRAY_COMMANDS::ASCENDING:

			std::sort(nums_array, nums_array + size);

			for (int i = 0; i < size; ++i)
				std::cout << nums_array[i] << ' ';
			break;

		case ARRAY_COMMANDS::DESCENDING:

			std::sort(nums_array, nums_array + size, compare);

			for (int i = 0; i < size; ++i)
				std::cout << nums_array[i] << ' ';
			break;
	}
	return 0;
}	

bool compare(float first_num, float second_num)
{
	if (first_num > second_num)
		return true;
	else
		return false;
}

