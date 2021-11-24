#include <iostream>
#include <algorithm>

/**
* \brief Функция для упорядочивания чисел в порядке возрастания
* \param first_num Первое число
* \param second_num Второе число
* \param third_num Третье число
*/
void sortAscending(double first_num, double second_num, double third_num);

/**
* \brief Функция для упорядочивания чисел в порядке убывания
* \param first_num Первое число
* \param second_num Второе число
* \param third_num Третье число
*/
void sortDescending(double first_num, double second_num, double third_num);

/**
* \brief Функция для вывода чисел на экран
* \param first_num Первое число
* \param second_num Второе число
* \param third_num Третье число
*/
void numsOutput(double first_num, double second_num, double third_num);

/**
 * \brief Комманды для работы с числами
 */
enum class SORT_COMMANDS
{
	ASCENDING = 1, DESCENDING = 2
};

/**
* \brief Точка входа в программу
* \return В случае успеха возвращает 0
*/
int main()
{
	std::cout << "Введите первое число: ";
	double first_num;
	std::cin >> first_num;
	std::cout << "Введите второе число: ";
	double second_num;
	std::cin >> second_num;
	std::cout << "Введите третье число: ";
	double third_num;
	std::cin >> third_num;

	std::cout << "Введите комманду для расположения чисел\n"
		<< "В порядке возрастания - " << static_cast<int>(SORT_COMMANDS::ASCENDING)
		<< "\nВ порядке убывания - " << static_cast<int>(SORT_COMMANDS::DESCENDING) << "\n";

	int command;
	std::cin >> command;

	const auto sort_commands = static_cast<SORT_COMMANDS>(command);
	switch (sort_commands)
	{

	case SORT_COMMANDS::ASCENDING:

		sortAscending(first_num, second_num, third_num);
		break;

	case SORT_COMMANDS::DESCENDING:

		sortDescending(first_num, second_num, third_num);
		break;

	default:
		std::cout << "Введена неправильная команда\n";
		break;
	}
	return 0;
}

void sortAscending(double first_num, double second_num, double third_num)
{	
	
	if (first_num > second_num)
		std::swap(first_num, second_num);
	if (first_num > third_num)
		std::swap(first_num, third_num);
	if (second_num > third_num)
		std::swap(second_num, third_num);
	numsOutput(first_num, second_num, third_num);
}

void sortDescending(double first_num, double second_num, double third_num)
{

	if (first_num < second_num)
		std::swap(first_num, second_num);
	if (first_num < third_num)
		std::swap(first_num, third_num);
	if (second_num < third_num)
		std::swap(second_num, third_num);
	numsOutput(first_num, second_num, third_num);
}

void numsOutput(double first_num, double second_num, double third_num)
{
	std::cout << "\n" << first_num << "\n" << second_num << "\n" << third_num << "\n";
}
