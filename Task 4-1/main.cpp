#include <iostream>
#include <random>

using namespace std;

/**
 * \brief Функция ввода размера массива.
 * \return Возвращает размер массива.
 */
size_t getSize();

/**
 * \brief Заполнение массива случайными числами.
 * \param size размер массива.
 * \param minValue минимальное значение элементов массива.
 * \param maxValue максимальное значение элементов массива.
 * \return Возвращает заполненный массив.
 */
int* randomizeArray(size_t size, int minValue, int maxValue);

/**
 * \brief Вывод массива.
 * \param newArray массив.
 * \param size размер массива.
 */
void arrayPrint(const int* newArray, const size_t size);

/**
 * \brief Функция заполнения массива вручную
 * \param size размер массива.
 * \return Возвращает заполненный массив.
 */
int* userArray(size_t size);

/**
 * \brief Функция, выполняющая умножение четных элементов, значения которых по модулю меньше 5
 * \param size размер массива.
 * \return Возвращает произведение элементов массива
 */
void multiplyingEvenNums(const int* newArray, size_t size);

/**
 * \brief Функция, считающая количество элементов, значения которых нечетны и по модулю превосходят заданное число А
 * \param size размер массива.
 * \return Возвращает количество элементов
 */
void countOddNums(const int* newArray, size_t size);

/**
 * \brief Функция, выполняющая умножение нечетных элементов массива, кратных 3, на их номера
 * \param size размер массива.
 * \return Возвращает произведение элементов массива на их номера
 */
void multiplyingOddNums(const int* newArray, size_t size);

/**
 * \brief Варианты ввода массива.
 */
enum class ARRAY_INPUT
{
	RANDOMLY, MANUALLY
};

/**
 * \brief Точка входа в программу
 * \return В случае успеха возвращает 0
 */
int main()
{
	size_t size = getSize();

	cout << "Заполнить массив:\n";
	cout << static_cast<int>(ARRAY_INPUT::RANDOMLY) << " - случайно,\n";
	cout << static_cast<int>(ARRAY_INPUT::MANUALLY) << " - вручную.\n";
	int choice;
	cin >> choice;

	const auto chosen = static_cast<ARRAY_INPUT>(choice);

	int* newArray = nullptr;

	auto minValue = -10;
	auto maxValue = 20;

	switch (chosen)
	{
	case ARRAY_INPUT::RANDOMLY:
	{
		newArray = randomizeArray(size, minValue, maxValue);
		break;
	}
	case ARRAY_INPUT::MANUALLY:
	{
		newArray = userArray(size);
		break;
	}
	}

	arrayPrint(newArray, size);

	multiplyingEvenNums(newArray, size);

	countOddNums(newArray, size);

	multiplyingOddNums(newArray, size);

	if (newArray != nullptr)
	{
		delete[] newArray;
		newArray = nullptr;
	}

	return 0;
}

size_t getSize()
{
	int size = 0;
	cout << "Введите размер массива" << endl;
	cin >> size;
	if (size <= 0)
	{
		cout << "Неверный размер";
		return 0;
	}
	else
		return size;
};

void arrayPrint(const int* newArray, const size_t size)
{
	if (newArray == nullptr)
	{
		cout << "Массива не существует\n";
	}
	else
	{
		cout << "Массив:\n";
		for (int index = 0; index < size; index++)
		{
			cout << newArray[index] << " ";
		}
		cout << "\n";

	}
}

int* randomizeArray(const size_t size, const int minValue, const int maxValue)
{
	random_device rd;
	mt19937 gen(rd());
	const std::uniform_int_distribution<> uniformIntDistribution(minValue, maxValue);
	auto* newArray = new int[size];

	for (int index = 0; index < size; index++)
	{
		newArray[index] = uniformIntDistribution(gen);
	}
	return newArray;
}

int* userArray(const size_t size)
{
	auto* array = new int[size];
	cout << "Введите элементы массива" << "\n";

	for (size_t index = 0; index < size; index++)
	{
		cin >> array[index];
	}

	return array;
}

void multiplyingEvenNums(const int* newArray, const size_t size)
{
	int count = 0;
	int mult = 1;

	if (newArray == nullptr)
	{
		cout << "Массива не существует\n";
	}

	for (size_t index = 0; index < size; index++)
	{
		if (newArray[index] % 2 == 0 && abs(newArray[index]) < 5)
		{
			mult *= newArray[index];
			count++;
		}
	}
	if (count == 0)
	{
		cout << "Нет таких элементов\n";
	}
	else
	{
		cout << "Произведение четных элементов: " << mult << "\n\n";
	}
}

void countOddNums(const int* newArray, const size_t size)
{
	cout << "Введите число A\n";
	int A;
	cin >> A;
	int count = 0;
	for (size_t index = 0; index < size; index++)
	{
		if (newArray[index] % 2 != 0 && abs(newArray[index]) > A)
		{
			count++;
		}
	}

	if (count == 0)
	{
		cout << "Нет таких элементов\n";
	}
	else
	{
		cout << "Количество нечетных элементов > A : " << count << "\n\n";
	}
}

void multiplyingOddNums(const int* newArray, const size_t size)
{
	int count = 0;
	cout << "Произведение нечетных элементов: ";
	int mult = 1;
	for (size_t index = 0; index < size; index++)
	{
		if (newArray[index] % 2 != 0 && newArray[index] % 3 == 0)
		{
			mult = newArray[index] * index;
			cout << mult << " ";
			count++;
		}
	}

	if (count == 0)
	{
		cout << "Нет таких элементов\n";
	}
	cout << endl;
}
