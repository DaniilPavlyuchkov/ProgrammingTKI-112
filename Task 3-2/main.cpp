#include <iostream>

size_t get_sequence_size()

/**
 * \brief Рассчитывает значение рекуррентного члена в зависимости от индекса.
 * \param index Индекс, номер итерации.
 * \return Возвращает 0 в случае успеха.
 */
double get_recurrent_member(const size_t index);

/**
 * \brief Точка входа в программу.
 * \return Возвращает 0 в случае успеха.
 */
int main()
{
	std::cout << "Введите количество членов последовательности";
	int count;
	std::cin >> count;
	if (count < 0)
		throw std::invalid_argument("Значение должно быть больше 0");

	const size_t n = count;

	return 0;
}

double get_recurrent_member(const size_t index)
{

}