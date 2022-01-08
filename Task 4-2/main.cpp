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
 * \param array массив.
 * \param size размер массива.
 */
void arrayPrint(const int*, const size_t size);

/**
 * \brief Функция заполнения массива вручную
 * \param size размер массива.
 * \return Возвращает заполненный массив.
 */
int* userArray(size_t size);

/**
 * \brief Заменяет последний отрицательный элемент массива на модуль первого
 * \param size Размер массива
 */
void replaceLastNegativeNum(int*, size_t size);

/**
 * \brief Удаляет все числа, у которых одинаковые цифры 
 * \param size Размер массива
 * \param newsize Размер нового массива
 * \return Массив, в котором удалены все числа, у которых одинаковые цифры 
 */
int* deleteNums(int*, size_t size, size_t newSize);

/**
 * \brief Считает количество чисел с одинаковыми цифрами (\a index)
 * \param size Размер массива
 * \return Количество чисел с одинаковыми цифрами
 */
int getNumsCount(int*, size_t size);

/**
 * \brief Создает из исходного массива новый массив М по заданному правилу
 * \param size Размер массива
 * \return массив М
 */
int* createArrayM(int*, const size_t size);

/**
 * \brief Варианты ввода массива.
 */
enum class ARRAY_INPUT
{
	RANDOMLY, MANUALLY
};

int main()
{
	size_t size = getSize();

	if (size == 0)
		return 1;

	cout << "Заполнить массив:\n";
	cout << static_cast<int>(ARRAY_INPUT::RANDOMLY) << " - случайно,\n";
	cout << static_cast<int>(ARRAY_INPUT::MANUALLY) << " - вручную.\n";
	int choice;
	cin >> choice;

	const auto chosen = static_cast<ARRAY_INPUT>(choice);

	int* array = nullptr;

	auto minValue = -10;
	auto maxValue = 20;
	

	switch (chosen)
	{
	case ARRAY_INPUT::RANDOMLY:
	{
		array = randomizeArray(size, minValue, maxValue);
		break;
	}
	case ARRAY_INPUT::MANUALLY:
	{
		array = userArray(size);
		break;
	}
	}

	arrayPrint(array, size);

	replaceLastNegativeNum(array, size);

	int numsCount = getNumsCount(array, size);
	size_t newSize = size - numsCount;
	int* newArray = deleteNums(array, size, newSize);
	cout << "\nПосле удаления чисел с одинаковыми цифрами\n ";
	arrayPrint(newArray, newSize);

	cout << "\nНовый массив M\n";
	int* newArrayM = createArrayM(array, size);
	arrayPrint(newArrayM, size);


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

void arrayPrint(const int* array, const size_t size)
{
	if (array == nullptr)
	{
		cout << "Массива не существует\n";
	}
	else
	{
		cout << "Массив:\n";
		for (int index = 0; index < size; index++)
		{
			cout << array[index] << " ";
		}
		cout << "\n";
	}
}

int* randomizeArray(const size_t size, const int minValue, const int maxValue)
{
	random_device rd;
	mt19937 gen(rd());
	const std::uniform_int_distribution<> uniformIntDistribution(minValue, maxValue);
	auto* array = new int[size];

	for (int index = 0; index < size; index++)
	{
		array[index] = uniformIntDistribution(gen);
	}
	return array;
}

int* userArray(const size_t size)
{
	auto* array = new int[size];
	cout << "Введите элементы массива\n";

	for (int index = 0; index < size; index++)
	{
		cin >> array[index];
	}

	return array;
}

void replaceLastNegativeNum(int* array, size_t size)
{
	int count = -1;
	int temp;
	for (int index = 0; index < size; index++)
	{
		if (array[index] < 0)
		{
			temp = index;
			count++;
		}

	}

	if (count == -1)
	{
		cout << "\nНет отрицательных чисел";
	}
	else
	{
		array[temp] = abs(array[0]);
		cout << "\nПосле замены\n";
		arrayPrint(array, size);
	}
}

int* deleteNums(int* array, size_t size, size_t newSize)
{
	int* newArray = new int[newSize];
	int newIndex = 0;
	for (int index = 0; index < size; index++)
	{
		int temp = abs(array[index]);
		if (temp % 10 != temp / 10 || array[index] == 0) 
		{
			newArray[index - newIndex] = array[index];
		}
		else 
		{
			newIndex++;
		}
	} 
	return newArray;
}

int getNumsCount(int* array, size_t size)
{
	int count = 0;
	for (int index = 0; index < size; index++)
	{
		int temp = abs(array[index]);
		if (temp % 10 == temp / 10 && array[index] != 0)
		{
			count++;
		}
	}
	return count;
}

int* createArrayM(int* arrayP, const size_t size)
{
	int* arrayM = new int[size];
	for (int index = 0; index < size; index++)
		if (arrayP[index] % 2 == 0)
		{
			arrayM[index] = arrayP[index] * index;
		}
		else
		{
			arrayM[index] = -arrayP[index];
		}
	return arrayM;
}

	





