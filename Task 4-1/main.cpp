#include <iostream>
#include <random>

using namespace std;

/**
 * \brief ������� ����� ������� �������.
 * \return ���������� ������ �������.
 */
size_t getSize();

/**
 * \brief ���������� ������� ���������� �������.
 * \param size ������ �������.
 * \param minValue ����������� �������� ��������� �������.
 * \param maxValue ������������ �������� ��������� �������.
 * \return ���������� ����������� ������.
 */
int* randomizeArray(size_t size, int minValue, int maxValue);

/**
 * \brief ����� �������.
 * \param newArray ������.
 * \param size ������ �������.
 */
void arrayPrint(const int* newArray, const size_t size);

/**
 * \brief ������� ���������� ������� �������
 * \param size ������ �������.
 * \return ���������� ����������� ������.
 */
int* userArray(size_t size);

/**
 * \brief �������, ����������� ��������� ������ ���������, �������� ������� �� ������ ������ 5
 * \param size ������ �������.
 * \return ���������� ������������ ��������� �������
 */
void multiplyingEvenNums(const int* newArray, size_t size);

/**
 * \brief �������, ��������� ���������� ���������, �������� ������� ������� � �� ������ ����������� �������� ����� �
 * \param size ������ �������.
 * \return ���������� ���������� ���������
 */
void countOddNums(const int* newArray, size_t size);

/**
 * \brief �������, ����������� ��������� �������� ��������� �������, ������� 3, �� �� ������
 * \param size ������ �������.
 * \return ���������� ������������ ��������� ������� �� �� ������
 */
void multiplyingOddNums(const int* newArray, size_t size);

/**
 * \brief �������� ����� �������.
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

	cout << "��������� ������:\n";
	cout << static_cast<int>(ARRAY_INPUT::RANDOMLY) << " - ��������,\n";
	cout << static_cast<int>(ARRAY_INPUT::MANUALLY) << " - �������.\n";
	int choice;
	cin >> choice;

	const auto chosen = static_cast<ARRAY_INPUT>(choice);

	int* newArray = nullptr;

	auto minValue = 0;
	auto maxValue = 0;
	cout << "������� �������� ����� �������" << endl;
	cin >> minValue >> maxValue;

	if (maxValue <= minValue)
	{
		cout << "�������� ��������" << endl;
	}

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

	return 0;
}

size_t getSize() 
{
	int size = 0;
	cout << "������� ������ �������" << endl;
	cin >> size;
	if (size <= 0)
	{
		cout << "�������� ������";
		return 0;
	}
	else
		return size;
};

void arrayPrint(const int* newArray, const size_t size)
{
	if (newArray == nullptr)
	{
		cout << "������� �� ����������\n";
	}
	else
	{
		cout << "������:\n";
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
	cout << "������� �������� �������" << "\n";

	for (int index = 0; index < size; index++)
	{
		cin >> array[index];
	}

	return array;
}

void multiplyingEvenNums(const int* newArray, size_t size)
{
	int mult = 1;
	for (int index = 0; index < size; index++)
	{
		if (newArray[index] % 2 == 0 && abs(newArray[index]) < 5)
		{
			mult *= newArray[index];
		}
	}
	cout << "������������ ������ ���������: " << mult << "\n\n";
}

void countOddNums(const int* newArray, size_t size)
{
	cout << "������� ����� A\n";
	int A;
	cin >> A;
	int count = 0;
	for (int index = 0; index < size; index++)
	{
		if (newArray[index] % 2 != 0 && abs(newArray[index]) > A)
		{
			count++;
		}
	}
	cout << "���������� �������� ��������� > A : " << count << "\n\n";
}

void multiplyingOddNums(const int* newArray, size_t size)
{
	cout << "������������ �������� ���������: ";
	int mult = 1;
	for (int index = 0; index < size; index++)
	{
		if (newArray[index] % 2 != 0 && newArray[index] % 3 == 0)
		{
			mult = newArray[index] * index;
			cout << mult << " ";
		}
	}
}